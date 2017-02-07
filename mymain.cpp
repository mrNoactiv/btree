#include <crtdbg.h>

#include "common/cNumber.h"
#include "common/utils/cTimer.h"
#include "common/stream/cStream.h"
#include "common/datatype/cBasicType.h"
#include "common/datatype/tuple/cTuple.h"
#include "common/datatype/tuple/cNTuple.h"
#include "common/datatype/tuple/cSpaceDescriptor.h"

#include "dstruct/paged/core/cNodeCache.h"
#include "dstruct/paged/b+tree/cB+Tree.h"
#include "dstruct/paged/b+tree/cB+TreeHeader.h"
#include "dstruct/paged/core/cMemoryPool.h"
#include "dstruct/paged/core/cItemStream.h"

const unsigned int TUPLE_LENGTH = 4;
const unsigned int ITEM_COUNT = 1000000;
const unsigned int CACHE_SIZE = 5000;
const unsigned int BLOCK_SIZE = 8192;
const unsigned int MAX_NODE_INMEM_SIZE = 11000;

using namespace dstruct::paged::bptree;
using namespace common::datatype::tuple;
using namespace common::utils;

typedef cTuple tKey_Fixedlen;
typedef cBpTree<tKey_Fixedlen> tBpTreeType_Fixedlen;

tKey_Fixedlen *mKey_Fixedlen[ITEM_COUNT];
tBpTreeType_Fixedlen *mIndex_Fixedlen;
cBpTreeHeader<tKey_Fixedlen> *mHeader_Fixedlen;
cSpaceDescriptor* mSD_Fixedlen;

void prepare_fixedLen() 
{	
	mSD_Fixedlen = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());

	//cNTuple* tuple1 = new cNTuple(mSD_Fixedlen, 3);
	//cNTuple* tuple2 = new cNTuple(mSD_Fixedlen, 2);
	//char *tuple3 = new char[20];

	//tuple1->SetValue(0, 10, mSD_Fixedlen);
	//tuple1->SetValue(1, 11, mSD_Fixedlen);
	//tuple1->SetValue(2, 4, mSD_Fixedlen);
	//tuple1->Print("\n", mSD_Fixedlen);

	//tuple2->SetValue(0, 10, mSD_Fixedlen);
	//tuple2->SetValue(1, 11, mSD_Fixedlen);
	//tuple2->Print("\n", mSD_Fixedlen);

	//int comp = tuple1->Compare(*tuple2, mSD_Fixedlen);
	//tuple2->CopyTo(tuple3, mSD_Fixedlen);
	//comp = tuple1->Compare(tuple3, mSD_Fixedlen);

	// preparation of the items
	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
	{
		mKey_Fixedlen[i] = new cTuple(mSD_Fixedlen);
		for (unsigned int j = 0 ; j < TUPLE_LENGTH ; j++)
		{
			mKey_Fixedlen[i]->SetValue(j, cNumber::Random(ITEM_COUNT), mSD_Fixedlen);
		}
	}
}

void create_fixedLen()
{
	bool debug = false;
	cTimer runtime;
	cTuple tp(mSD_Fixedlen);

	// B-tree header
	mHeader_Fixedlen = new cBpTreeHeader<tKey_Fixedlen>("btree1", mSD_Fixedlen, tp.GetInMemSize(mSD_Fixedlen), sizeof(int), BLOCK_SIZE);

	// cache
	cNodeCache* mNodeCache = new cNodeCache();	
	if (!mNodeCache->Create("tmp.bpt", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
	{
		printf("Critical Error: Cache Data File was not created!\n");
		exit(1);
	}

	// pool
	cMemoryPool* memoryPool = new cMemoryPool();

	// B-tree
	mIndex_Fixedlen = new tBpTreeType_Fixedlen(memoryPool);
	if (!mIndex_Fixedlen->Create(mHeader_Fixedlen, mNodeCache))
	{
		printf("TestCreate: creation failed!\n");
	}

	runtime.Start();
	for (unsigned int i = 0 ; i < ITEM_COUNT / 2 ; i++)
	{
		if (i % 10000 == 0)
		{
			printf("%d\r", i);
			//mNodeCache->PrintStatistics();
		}

		if (debug || i >= -1)
		{
			mIndex_Fixedlen->SetDebug(true);
			mKey_Fixedlen[i]->Print("\n", mSD_Fixedlen);
		}

		mIndex_Fixedlen->Insert(*mKey_Fixedlen[i], (char*)&i);

		//for (unsigned int j = i; j <= i; j++)
		//{
		//	if (!mIndex_Fixedlen->PointQuery(*mKey_Fixedlen[j]))
		//	{
		//		printf("Polozka %d nenalezena po %d iteraci: ", j, i);
		//		mKey_Fixedlen[j]->Print("\n", mSD_Fixedlen);
		//		// mIndex_Fixedlen->Print(cObject::MODE_DEC);
		//	}
		//}
	}
	runtime.Stop();
	mIndex_Fixedlen->PrintInfo();
	printf("\n");
	mNodeCache->PrintStatistics();
	printf("\n");
	runtime.Print(" - Insert time\n");
	printf("Performance: %.1f Inserts/s\n", mIndex_Fixedlen->GetHeader()->GetItemCount() / runtime.GetTime());

	delete mIndex_Fixedlen;
	delete mNodeCache;
	delete mHeader_Fixedlen;
}

void open_fixedLen()
{
	bool debug = false;
	cTimer runtime;
	cTuple tp(mSD_Fixedlen);

	// B-tree header
	mHeader_Fixedlen = new cBpTreeHeader<tKey_Fixedlen>("btree1", mSD_Fixedlen);

	// cache
	cNodeCache* mNodeCache = new cNodeCache();	
	if (!mNodeCache->Open("tmp.bpt", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
	{
		printf("Critical Error: Cache Data File was not open!\n");
		exit(1);
	}

	// pool
	cMemoryPool* memoryPool = new cMemoryPool();

	// B-tree
	mIndex_Fixedlen = new tBpTreeType_Fixedlen(memoryPool);
	if (!mIndex_Fixedlen->Open(mHeader_Fixedlen, mNodeCache, false))
	{
		printf("TestCreate: creation failed!\n");
	}

	runtime.Start();
	for (unsigned int i = ITEM_COUNT / 2 + 1 ; i < ITEM_COUNT ; i++)
	{

		if (i % 10000 == 0)
		{
			printf("%d\r", i);
		}

		if (debug || i >= -1)
		{
			mIndex_Fixedlen->SetDebug(true);
			mKey_Fixedlen[i]->Print("\n", mSD_Fixedlen);
		}

		mIndex_Fixedlen->Insert(*mKey_Fixedlen[i], (char*)&i);

	}
	runtime.Stop();
	mIndex_Fixedlen->PrintInfo();
	runtime.Print(" - insert time (after open)\n");
	//mHeader_Fixedlen->Print();

	for (unsigned int j = 0; j < ITEM_COUNT; j++)
	{
		if (!mIndex_Fixedlen->PointQuery(*mKey_Fixedlen[j]))
		{
			printf("Error: item %d not found!!!", j);
			mKey_Fixedlen[j]->Print("\n", mSD_Fixedlen);
			exit(1);
		}
	}

	delete mIndex_Fixedlen;
	delete mNodeCache;
	delete mHeader_Fixedlen;
}

bool main()
{
	cTimer runtime;

	_CrtSetReportMode( _CRT_WARN, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_WARN, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ERROR, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ERROR, _CRTDBG_FILE_STDOUT );
	_CrtSetReportMode( _CRT_ASSERT, _CRTDBG_MODE_FILE );
	_CrtSetReportFile( _CRT_ASSERT, _CRTDBG_FILE_STDOUT );

	prepare_fixedLen();
	runtime.Start();
	create_fixedLen();	
	open_fixedLen();
	runtime.Stop();
	runtime.Print("\n - test time\n");
	return 1;
}