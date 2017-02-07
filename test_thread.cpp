// It is necessary to compile as x64 project.

#include <thread>

#include "common/memorystructures/cSortedArray.h"
#include "common/memorystructures/cSortedArrayWithLeaf.h"

#include "common/cNumber.h"
#include "common/utils/cTimer.h"
#include "common/stream/cStream.h"
#include "common/datatype/cBasicType.h"
#include "common/datatype/cDataVarLen.h"
#include "common\datatype\tuple\cTuple.h"
//#include "common/datatype/tuple/cNTuple.h"
#include "common/datatype/tuple/cSpaceDescriptor.h"

#include "dstruct/paged/core/cNodeCache.h"
#include "dstruct/paged/b+tree/cB+Tree.h"
#include "dstruct/paged/b+tree/cB+TreeHeader.h"
#include "dstruct/paged/core/cMemoryPool.h"
#include "dstruct/paged/core/cItemStream.h"
#include "dstruct/paged/core/cQuickDB.h"
#include "common/random/cGaussRandomGenerator.h"

using namespace dstruct::paged::bptree;
using namespace common::datatype::tuple;
using namespace common::utils;
using namespace common::random;

const unsigned int TUPLE_LENGTH = 5;
const unsigned int ITEM_COUNT = 2000000;
const unsigned int MAX_VALUE = ITEM_COUNT;
const unsigned int DATA_LENGTH = 4;

const unsigned int CACHE_SIZE = 20000;
const unsigned int BLOCK_SIZE = /*2048;*/8192;
const unsigned int MAX_NODE_INMEM_SIZE = 1.25 * BLOCK_SIZE;

const unsigned int NOF_THREADS = 3;
const unsigned int NOF_THREADS_M1 = NOF_THREADS-1;

const unsigned int DSMODES[] = { cDStructConst::DSMODE_DEFAULT }; //, cDStructConst::DSMODE_RI, cDStructConst::DSMODE_CODING, cDStructConst::DSMODE_RICODING};
const unsigned int ITEM_TYPES[] = { cDStructConst::TUPLE }; // , cDStructConst::NTUPLE };

const bool TEST_ALL_VARIANTS = true;						// true, if test of all variants is required

unsigned int DSMODE = cDStructConst::DSMODE_DEFAULT;		// defines the type of data structure mode
//DSMODE_DEFAULT	DSMODE_RI	DSMODE_CODING	DSMODE_RICODING 

unsigned int CODETYPE = ELIAS_FIBONACCI_FAST;				// defines the type of coding in the case of CODING and RICODING
//ELIAS_DELTA 1		ELIAS_DELTA_FAST 5		FIBONACCI2 2		FIBONACCI2_FAST 6
//FIBONACCI3  3		FIBONACCI3_FAST 7		ELIAS_FIBONACCI 4	ELIAS_FIBONACCI_FAST 8

unsigned int ITEM_TYPE = cDStructConst::TUPLE;			// defines type of tuple: TUPLE 0		NTUPLE 1

unsigned int ITEM_LENGTH = cDStructConst::VARIABLE_LENGTH;	// defines the length of tuple: FIXED_LENGTH 0		VARIABLE_LENGTH 1

static const unsigned int START_SEED = 865915;					// defines the starting seed of data generator

typedef cNTuple tKey_VarLen;
typedef cBpTree<tKey_VarLen> tBpTreeType_VarLen;

typedef cTuple tKey_Fixedlen;
typedef cBpTree<tKey_Fixedlen> tBpTreeType_Fixedlen;

cQuickDB *quickDB;

tKey_VarLen *mKey_VarLen[ITEM_COUNT];
char *mData_VarLen[ITEM_COUNT];
tBpTreeType_VarLen *mIndex_VarLen;
cBpTreeHeader<tKey_VarLen> *mHeader_VarLen;
cSpaceDescriptor* mSD;

tKey_Fixedlen *mKey_Fixedlen[ITEM_COUNT];
tBpTreeType_Fixedlen *mIndex_Fixedlen;
cBpTreeHeader<tKey_Fixedlen> *mHeader_Fixedlen;
cSpaceDescriptor* mSD_Fixedlen;
tKey_Fixedlen *mAuxTuple1;
tKey_Fixedlen *mAuxTuple2;

void printHeader();
void Generate(int seed, unsigned int type, bool randomLength = false); 

void Create_FixedLen();
bool Open_FixedLen();

void PointQuery(/*cTreeItemStream<tKey_Fixedlen>* result,*/ unsigned int loQueryOrder, unsigned int hiQueryOrder);
void RunPointQuery();

void checkItem_variablelen(unsigned int j);
bool checkItem_fixedlen(unsigned int j);

int main(void)
{
	ITEM_TYPE = ITEM_TYPES[0];
	Generate(START_SEED, ITEM_TYPE);
	DSMODE = DSMODES[0];
	printHeader();
	Create_FixedLen();
	RunPointQuery();

	return 0;
}

// **********************************************************************
// ********************** FixLen Items **********************************
// **********************************************************************

/**
* Perform point query on the B-tree and compare the result with the tuples stored in the mKey_Fixedlen.
*/
bool checkItem_fixedlen(unsigned int j)
{
	cTreeItemStream<tKey_Fixedlen>* result = mIndex_Fixedlen->PointQuery(*mKey_Fixedlen[j]);
	if (result->GetItemCount() != 1)
	{
		printf("Polozka %d nenalezena: ", j);
		mKey_Fixedlen[j]->Print("\n", mSD_Fixedlen);
	}
	const char* item = result->GetItem();
	if (mKey_Fixedlen[j]->Compare(item, mSD_Fixedlen) != 0)
	{
		printf("Polozka %d nekoresponduje\n", j);
		mKey_Fixedlen[j]->Print(" - inserted key\n", mSD_Fixedlen);
		tKey_Fixedlen::Print(item, " - readed key\n", mSD_Fixedlen);
		return false;
	}
	result->CloseResultSet();
	return true;
}

/**
* Create the B-tree and insert one half of the data.
*/
void Create_FixedLen()
{
	char data[DATA_LENGTH], *resultData;
	bool debug = false;
	cTimer runtime;
	cTuple tp(mSD_Fixedlen);

	// creation of a new persistent file and opening the cache
	quickDB = new cQuickDB();
	if (!quickDB->Create("quickDB.dat", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
	{
		printf("Critical Error: Cache Data File was not created!\n");
		exit(1);
	}

	// B-tree
	mHeader_Fixedlen = new cBpTreeHeader<tKey_Fixedlen>("btree1", BLOCK_SIZE, mSD_Fixedlen, tp.GetSize(mSD_Fixedlen), DATA_LENGTH, false, DSMODE);
	if (DSMODE == cDStructConst::DSMODE_CODING || DSMODE == cDStructConst::DSMODE_RICODING)
	{
		mHeader_Fixedlen->SetCodeType(CODETYPE);
	}

	mIndex_Fixedlen = new tBpTreeType_Fixedlen();
	if (!mIndex_Fixedlen->Create(mHeader_Fixedlen, quickDB))
	{
		printf("TestCreate: creation failed!\n");
	}

	for (unsigned int i = 0 ; i < DATA_LENGTH ; i++)
	{
		data[i] = (char)i;
	}

	// inserting tuples into the B-tree
	runtime.Start();
	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
	{
		if (i % 10000 == 0)
		{
			printf("%d\r", i);
		}
		mIndex_Fixedlen->Insert(*mKey_Fixedlen[i], data);
	}
	runtime.Stop();
	printf("\n");
	runtime.Print(" - Insert time\n");
	printf("Performance: %.1f Inserts/s\n", mIndex_Fixedlen->GetHeader()->GetItemCount() / runtime.GetTime());
}

void RunPointQuery()
{
	std::thread **threads = new std::thread*[NOF_THREADS_M1];
	// cTreeItemStream<tKey_Fixedlen>** results = new cTreeItemStream<tKey_Fixedlen>*[NOF_THREADS];
	unsigned int count = ITEM_COUNT / NOF_THREADS;
	unsigned int loQueryOrder = 0, hiQueryOrder = count;
	cTimer tmrQuery;

	tmrQuery.Start();

	for (unsigned int i = 0; i < NOF_THREADS; i++)
	{
		//results[i] = (cTreeItemStream<tKey_Fixedlen>*)quickDB->GetResultSet();
		//results[i]->SetNodeHeader(mHeader_Fixedlen->GetNodeHeader(cTreeHeader::HEADER_LEAFNODE));
	}

	for (unsigned int i = 0 ; i < NOF_THREADS_M1 ; i++)
	{
		threads[i] = new std::thread(PointQuery, /*results[i],*/ loQueryOrder, hiQueryOrder);
		loQueryOrder += count;
		hiQueryOrder += count;

	}
	PointQuery(/*results[NOF_THREADS_M1],*/ loQueryOrder, ITEM_COUNT);

	for (unsigned int i = 0 ; i < NOF_THREADS-1 ; i++)
	{
		threads[i]->join();  // wait for all threads created
	}

	for (unsigned int i = 0; i < NOF_THREADS; i++)
	{
		// results[i]->CloseResultSet();
	}

	for (unsigned int i = 0 ; i < NOF_THREADS-1 ; i++)
	{
		delete threads[i];
	}
	delete []threads;

	// print timers and counters
	tmrQuery.Stop();
	tmrQuery.Print(" - Query time\n");
	printf("Performance: %.1f Queries/s\n\n", mIndex_Fixedlen->GetHeader()->GetLeafItemCount() / tmrQuery.GetTime());

	delete mIndex_Fixedlen;
	quickDB->Close();
	delete quickDB;
	delete mHeader_Fixedlen;
}

void PointQuery(/*cTreeItemStream<tKey_Fixedlen>* result,*/ unsigned int loQueryOrder, unsigned int hiQueryOrder)
{
	char data[DATA_LENGTH];

	printf("%u, %u\n", loQueryOrder, hiQueryOrder);

	for (unsigned int i = loQueryOrder ; i < hiQueryOrder ; i++)
	{
		if (i % 25000 == 0)
		{
			// printf("#Thread: %d, #Query: %d, #IN: %.2f, #LN: %.2f      \r", std::thread::id(), i, queryStat.GetLarInAvg(), queryStat.GetLarLnAvg());
			// cout << "#Thread: " << std::this_thread::get_id() << ", #Query: " << i << ", #IN: " << queryStat.GetLarInAvg() << 
			//	", #LN: " << queryStat.GetLarLnAvg() << "\r";
			cout << ".";
		}

		// mIndex_Fixedlen->PointQuery(*mKey_Fixedlen[i], result);
		cItemStream* resultSet = mIndex_Fixedlen->PointQuery(*mKey_Fixedlen[i]); // RangeQuery(*mKey_Fixedlen[i], *mKey_Fixedlen[i], 1, 1);
		if (resultSet->GetItemCount() != 1)
		{
			printf("Critical Error: Item was not found!");
			mKey_Fixedlen[i]->Print("\n", mSD_Fixedlen);
		}
		else
		{
			// check data
			/*resultData = (char*)(resultSet->GetItem() + mIndex_Fixedlen->GetHeader()->GetKeySize());
			for (unsigned int j = 0 ; j < DATA_LENGTH ; j++)
			{
				if (data[j] != resultData[j])
				{
					printf("Critical Error: Data are not correct: item order: %u,%u!", i, j);
					mKey_Fixedlen[i]->Print("\n", mSD_Fixedlen);
				}
			}*/
		}
		resultSet->CloseResultSet();
	}

	if (NOF_THREADS == 1)
	{
		printf("\n");
		cout << "#Thread: " << std::this_thread::get_id();
		printf("\n");
	}
}


// **********************************************************************
// ********************** Item & Data Generator *************************
// **********************************************************************

void Generate(int seed, unsigned int type, bool randomLength) 
{	
	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
	mSD_Fixedlen  = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
	cGaussRandomGenerator rg(seed);

	// preparation of the items
	if (type == cDStructConst::NTUPLE)
	{
		for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
		{
			unsigned int len = (randomLength) ? i % (TUPLE_LENGTH - 1) + 2 : TUPLE_LENGTH;

			mKey_VarLen[i] = new tKey_VarLen(mSD, len);
			for (unsigned int j = 0 ; j < len ; j++)
			{
				mKey_VarLen[i]->SetValue(j, rg.GetNextUInt(ITEM_COUNT), mSD);
			}
			mKey_VarLen[i]->SetLength(len);


			mData_VarLen[i] = new char[len * 2 + 1];
			for (unsigned int j = 0; j < len * 2; j++)
			{
				mData_VarLen[i][1 + j] = 'a';
			}
			mData_VarLen[i][0] = len * 2;
		}
	}
	else
	{
		for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
		{
			mKey_Fixedlen[i] = new tKey_Fixedlen(mSD); // creation of a tuple
			for (unsigned int j = 0 ; j < TUPLE_LENGTH ; j++)
			{
				mKey_Fixedlen[i]->SetValue(j, rg.GetNextUInt(MAX_VALUE), mSD); // setting a random value into each dimension of this tuple
			}
		}

		mAuxTuple1 = new tKey_Fixedlen(mSD_Fixedlen); // auxiliary tuple used during test
		mAuxTuple2 = new tKey_Fixedlen(mSD_Fixedlen); // auxiliary tuple used during test

		for (unsigned int j = 0 ; j < TUPLE_LENGTH ; j++)
		{
			mAuxTuple1->SetValue(j, 150000, mSD_Fixedlen);
			mAuxTuple2->SetValue(j, 150000, mSD_Fixedlen);
		}
	}
}


// **********************************************************************
// ********************** Header Generator *************************
// **********************************************************************

void printHeader()
{
	printf("\n\n---------------------------------------------\n");
	if (ITEM_TYPE == cDStructConst::TUPLE)
		printf("Fixed length B-tree test\n");
	else
		printf("Variable length B-tree test\n");

	switch (DSMODE)
	{
	case cDStructConst::DSMODE_DEFAULT: printf("DSMODE: DEFAULT "); break;
	case cDStructConst::DSMODE_RI: printf("DSMODE: REFERENCE ITEMS "); break;
	case cDStructConst::DSMODE_CODING: printf("DSMODE: CODING "); break;
	case cDStructConst::DSMODE_RICODING: printf("DSMODE: REFERENCE ITEMS & CODING "); break;
	}

	if ((DSMODE == cDStructConst::DSMODE_CODING) || (DSMODE == cDStructConst::DSMODE_RICODING))
	{
		printf("/ ");
		switch (CODETYPE)
		{
		case ELIAS_DELTA: printf("CODETYPE: ELIAS_DELTA "); break;
		case FIBONACCI2: printf("CODETYPE: FIBONACCI2 "); break;
		case FIBONACCI3: printf("CODETYPE: FIBONACCI3 "); break;
		case ELIAS_FIBONACCI: printf("CODETYPE: ELIAS_FIBONACCI "); break;
		case ELIAS_DELTA_FAST: printf("CODETYPE: ELIAS_DELTA_FAST "); break;
		case FIBONACCI2_FAST: printf("CODETYPE: FIBONACCI2_FAST "); break;
		case FIBONACCI3_FAST: printf("CODETYPE: FIBONACCI3_FAST "); break;
		case ELIAS_FIBONACCI_FAST: printf("CODETYPE: ELIAS_FIBONACCI_FAST "); break;
		}
	}
	printf("\n");
}

