//
////#include "common\cSortedArray.h"
//#include "common/memorystructures/cSortedArrayWithLeaf.h"
//
//#include "common/cNumber.h"
//#include "common/utils/cTimer.h"
//#include "common/stream/cStream.h"
//#include "common/datatype/cBasicType.h"
//#include "common/datatype/cDataVarLen.h"
////#include "common\datatype\tuple\cTuple.h"
//#include "common/datatype/tuple/cNTuple.h"
//#include "common/datatype/tuple/cSpaceDescriptor.h"
//
//#include "dstruct/paged/core/cNodeCache.h"
//#include "dstruct/paged/b+tree/cB+Tree.h"
//#include "dstruct/paged/b+tree/cB+TreeHeader.h"
//#include "dstruct/paged/core/cMemoryPool.h"
//#include "dstruct/paged/core/cItemStream.h"
//#include "dstruct/paged/core/cQuickDB.h"
//#include "common/random/cGaussRandomGenerator.h"
//#include "common/data/cTuplesGenerator.h"
//#include "common/compression/coder.h"
//
//char COLLECTION_FILE[2048] = "J:\\data\\ngram\\idoc2013_ngramID_4\\export_ngram.txt"/*10*/;
//const unsigned int TUPLE_LENGTH = 4 /*10*/;
//const unsigned int ITEM_COUNT = 50000000;//225886258;//453469461;
//const unsigned int CACHE_SIZE = 32000;//10000;//10;//32000;//10;//32000 /*10000*/;
//const unsigned int BLOCK_SIZE = /*2048;*/8192;//2048;//8192;
//const unsigned int MAX_NODE_INMEM_SIZE = /*2400;*/10500;
//
//using namespace dstruct::paged::bptree;
//using namespace common::datatype::tuple;
//using namespace common::data;
//using namespace common::random;
//
//typedef cNTuple tKey_VarLen; // warning cTuple vs cNTuple
//typedef cBpTree<tKey_VarLen> tBpTreeType_VarLen;
//
//tKey_VarLen *mKey_VarLen2[1000000];
//char *mData_VarLen2[1000000];
//
//tKey_VarLen *mKey_VarLen;//[ITEM_COUNT];
//char *mData_VarLen;//[ITEM_COUNT];
//tBpTreeType_VarLen *mIndex_VarLen;
//cBpTreeHeader<tKey_VarLen> *mHeader_VarLen;
//cSpaceDescriptor* mSD;
//
//void Print2File(char* fileName, double avg) 
//{
//	FILE *streamInfo = fopen(fileName, "a");
//	fprintf(streamInfo,"Performance: %.1f\n", avg);
//    fclose(streamInfo);
//}
//
//void prepare_tuples()
//{	
//	cTuplesGenerator<cUInt, cNTuple> generator;
//	generator.SetFileName(COLLECTION_FILE);
//
//	if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		mKey_VarLen2[i] = new tKey_VarLen(mSD, TUPLE_LENGTH);
//		tKey_VarLen::Copy(mKey_VarLen2[i]->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		mKey_VarLen2[i]->SetLength(TUPLE_LENGTH);
//
//		unsigned int len = i % (TUPLE_LENGTH - 1) + 2;
//		mData_VarLen2[i] = new char[len * 2 + 1];
//		for (unsigned int j = 0; j < len * 2; j++)
//		{
//			mData_VarLen2[i][1 + j] = 'a';
//		}
//		mData_VarLen2[i][0] = len * 2;
//	}
//
//	generator.TextFileClose();
//}
//
//void create_variablelen2()
//{
//	bool debug = false;
//	cTimer runtime;
//	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	tKey_VarLen tp(mSD, TUPLE_LENGTH);
//	mKey_VarLen = new tKey_VarLen(mSD, TUPLE_LENGTH);
//	mData_VarLen = new char[TUPLE_LENGTH];
//	mData_VarLen[0] = TUPLE_LENGTH;
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create("quickDB", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree
//	mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, BLOCK_SIZE, false, cDStructConst::DSMODE_DEFAULT);
//	mIndex_VarLen = new tBpTreeType_VarLen();
//	if (!mIndex_VarLen->Create(mHeader_VarLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	cGaussRandomGenerator rg(1000);
//
//	runtime.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT/5 ; i++)
//	{
//		if (i==249)
//			int c = 3;
//
//		if (i % 10000 == 0)
//		{
//			printf("%d\r", i);
//			//mNodeCache->PrintStatistics();
//		}
//
//		unsigned int order = rg.GetNextUInt(ITEM_COUNT);
//		mIndex_VarLen->Insert(*mKey_VarLen2[order], mData_VarLen2[order]);
//		
//			/*cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//			if (resultSet->GetItemCount() != 1)
//			{
//				printf("Critical Error: Item was not");
//			}
//			resultSet->CloseResultSet();
//		*/
//
//	}
//	runtime.Stop();
//	//mIndex_VarLen->PrintInfo();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//
//	delete mIndex_VarLen;
//	quickDB->Close();
//	_CrtCheckMemory();
//	delete quickDB;
//	delete mHeader_VarLen;
//}
//
//void create_variablelen()
//{
//	bool debug = false;
//	cTimer runtime;
//	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	tKey_VarLen tp(mSD, TUPLE_LENGTH);
//	mKey_VarLen = new tKey_VarLen(mSD, TUPLE_LENGTH);
//	mData_VarLen = new char[TUPLE_LENGTH];
//	mData_VarLen[0] = TUPLE_LENGTH;
//
//	cTuplesGenerator<cUInt, cNTuple> generator;
//	generator.SetFileName(COLLECTION_FILE);
//
//	cTuplesGenerator<cUInt, cNTuple> generator2;
//	generator2.SetFileName(COLLECTION_FILE);
//
//	if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create("quickDB", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree
//	//mHeader_RI = new cBpTreeHeader<tKey_RI>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_RI);
//	mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_DEFAULT);
//	mIndex_VarLen = new tBpTreeType_VarLen();
//	if (!mIndex_VarLen->Create(mHeader_VarLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	runtime.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		tKey_VarLen::Copy(mKey_VarLen->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		mKey_VarLen->SetLength(TUPLE_LENGTH);
//		//mKey_VarLen->Print("\n", mSD);
//
//		if (i == 100001)
//			int c = 3;
//
//		if (i % 10000 == 0)
//		{
//			printf("%d\r", i);
//			//mNodeCache->PrintStatistics();
//		}
//
//		//if (i % 100 == 0)
//		{
//			mIndex_VarLen->Insert(*mKey_VarLen, mData_VarLen);
//		
//			/*cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//			if (resultSet->GetItemCount() != 1)
//			{
//				printf("Critical Error: Item was not");
//			}
//			resultSet->CloseResultSet();*/
//		}
//
//	}
//	runtime.Stop();
//	//mIndex_VarLen->PrintInfo();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//	Print2File("statistics.txt", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//
//	generator.TextFileClose();
//	_CrtCheckMemory();
//
//	//mIndex_VarLen->GetHeader()->Print();
//	//mHeader_VarLen->Print();
//	mIndex_VarLen->PrintInfo();
//
//
//	// -----------------------------------------------------------------------------
//	if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	cTimer queryTimer;
//	queryTimer.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		tKey_VarLen::Copy(mKey_VarLen->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		// mk!!: mKey_VarLen->SetLength(TUPLE_LENGTH);
//
//		if (i % 10000 == 0)
//		{
//			printf("Query: %d\r", i);
//			//mNodeCache->PrintStatistics();
//		}
//
//
//		//if (i % 100 == 0)
//		{
//		cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//		if (resultSet->GetItemCount() != 1)
//		{
//			printf("Critical Error: Item was not");
//		}
//		resultSet->CloseResultSet();
//		}
//	}
//	queryTimer.Stop();
//	printf("\n");
//	queryTimer.Print(" - Query time\n");
//	printf("Performance: %.1f Queries/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / queryTimer.GetTime());
//	Print2File("statistics.txt", mIndex_VarLen->GetHeader()->GetItemCount() / queryTimer.GetTime());
//	// -----------------------------------------------------------------------------
//	//mHeader_VarLen->Print();*/
//
//	//mIndex_VarLen->GetHeader()->Print();
//	//mHeader_VarLen->Print();
//	mIndex_VarLen->PrintInfo();
//
//	generator.TextFileClose();
//
//	delete mIndex_VarLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_VarLen;
//}
//
//
//void create_ri()
//{
//	bool debug = false;
//	cTimer runtime;
//	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	tKey_VarLen tp(mSD, TUPLE_LENGTH);
//	mKey_VarLen = new tKey_VarLen(mSD, TUPLE_LENGTH);
//	mData_VarLen = new char[TUPLE_LENGTH];
//	mData_VarLen[0] = TUPLE_LENGTH;
//
//	cTuplesGenerator<cUInt, cNTuple> generator;
//	generator.SetFileName(COLLECTION_FILE);
//
//	cTuplesGenerator<cUInt, cNTuple> generator2;
//	generator2.SetFileName(COLLECTION_FILE);
//
//	if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create("quickDB", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree
//	//mHeader_RI = new cBpTreeHeader<tKey_RI>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_RI);
//	mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_RI);
//	mIndex_VarLen = new tBpTreeType_VarLen();
//	if (!mIndex_VarLen->Create(mHeader_VarLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	runtime.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		tKey_VarLen::Copy(mKey_VarLen->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		mKey_VarLen->SetLength(TUPLE_LENGTH);
//
//		if (i % 10000 == 0)
//		{
//			printf("%d\r", i);
//		}
//
//		//if (i % 100 == 0)
//		{
//			mIndex_VarLen->Insert(*mKey_VarLen, mData_VarLen);
//		
//		/*	cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//			if (resultSet->GetItemCount() != 1)
//			{
//				printf("Critical Error: Item was not");
//			}
//			resultSet->CloseResultSet();*/
//		}
//
//	}
//	runtime.Stop();
//	//mIndex_VarLen->PrintInfo();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//	Print2File("statistics.txt", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//
//	generator.TextFileClose();
//	_CrtCheckMemory();
//
//	mIndex_VarLen->PrintInfo();
//
//	// -----------------------------------------------------------------------------
//	/*if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	cTimer queryTimer;
//	queryTimer.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		tKey_VarLen::Copy(mKey_VarLen->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		// mk!!: mKey_VarLen->SetLength(TUPLE_LENGTH);
//
//		if (i % 10000 == 0)
//		{
//			printf("Query: %d\r", i);
//			//mNodeCache->PrintStatistics();
//		}
//
//
//		//if (i % 100 == 0)
//		{
//		cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//		if (resultSet->GetItemCount() != 1)
//		{
//			printf("Critical Error: Item was not");
//		}
//		resultSet->CloseResultSet();
//		}
//	}
//	queryTimer.Stop();
//	printf("\n");
//	queryTimer.Print(" - Query time\n");
//	printf("Performance: %.1f Queries/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / queryTimer.GetTime());
//	Print2File("statistics.txt", mIndex_VarLen->GetHeader()->GetItemCount() / queryTimer.GetTime());
//	// -----------------------------------------------------------------------------
//	//mHeader_VarLen->Print();*/
//
//	//mIndex_VarLen->GetHeader()->Print();
//	
//	//generator.TextFileClose();
//
//	delete mIndex_VarLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_VarLen;
//}
//
//
//void create_ricoding()
//{
//	bool debug = false;
//	cTimer runtime;
//	mSD = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	tKey_VarLen tp(mSD, TUPLE_LENGTH);
//	mKey_VarLen = new tKey_VarLen(mSD, TUPLE_LENGTH);
//	mData_VarLen = new char[TUPLE_LENGTH];
//	mData_VarLen[0] = TUPLE_LENGTH;
//
//	cTuplesGenerator<cUInt, cNTuple> generator;
//	generator.SetFileName(COLLECTION_FILE);
//
//	cTuplesGenerator<cUInt, cNTuple> generator2;
//	generator2.SetFileName(COLLECTION_FILE);
//
//	if (!generator.TextFileOpen())
//	{
//		printf("Error: File wasn't opened!\n");
//		exit(1);
//	}
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create("quickDB", CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree
//	//mHeader_RI = new cBpTreeHeader<tKey_RI>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_RI);
//	mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD, tp.GetSize(mSD), TUPLE_LENGTH / 2, false, cDStructConst::DSMODE_RICODING);
//	mHeader_VarLen->SetCodeType(ELIAS_FIBONACCI_FAST);
//
//	mIndex_VarLen = new tBpTreeType_VarLen();
//	if (!mIndex_VarLen->Create(mHeader_VarLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	runtime.Start();
//	for (unsigned int i = 0 ; i < ITEM_COUNT ; i++)
//	{
//		tKey_VarLen::Copy(mKey_VarLen->GetData(), generator.GetNextTupleFromTextFile(mSD)->GetData(), mSD);
//		mKey_VarLen->SetLength(TUPLE_LENGTH);
//
//		if (i % 10000 == 0)
//		{
//			printf("%d\r", i);
//		}
//
//		//if (i % 100 == 0)
//		{
//			mIndex_VarLen->Insert(*mKey_VarLen, mData_VarLen);
//		
//		/*	cItemStream* resultSet = mIndex_VarLen->PointQuery(*mKey_VarLen);
//			if (resultSet->GetItemCount() != 1)
//			{
//				printf("Critical Error: Item was not");
//			}
//			resultSet->CloseResultSet();*/
//		}
//
//	}
//	runtime.Stop();
//	//mIndex_VarLen->PrintInfo();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//	Print2File("statistics.txt", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetTime());
//
//	generator.TextFileClose();
//	_CrtCheckMemory();
//
//	mIndex_VarLen->PrintInfo();
//
//	delete mIndex_VarLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_VarLen;
//}
//
//int main(void)
//{
//	cTimer runtime;
//
//	bool testvariablelen = true;
//	bool testreferenceitems = false;
//	bool testricoding = false;
//
//	if (testvariablelen)
//	{
//		printf("\n\n---------------------------------------------\n");
//		printf("Variable length B-tree test\n");
//		runtime.Start();
//		create_variablelen();	
//		runtime.Stop();
//		runtime.Print(" - whole test time\n");
//	}
//
//	if (testreferenceitems)
//	{
//		printf("\n\n---------------------------------------------\n");
//		printf("Variable length B-tree with Reference Items test\n");
//		runtime.Start();
//		create_ri();	
//		runtime.Stop();
//		runtime.Print(" - whole test time\n");
//	}
//
//	if (testricoding)
//	{
//		printf("\n\n---------------------------------------------\n");
//		printf("Variable length B-tree with RI Coding test\n");
//		runtime.Start();
//		create_ricoding();	
//		runtime.Stop();
//		runtime.Print(" - whole test time\n");
//	}
//
//	return 1;
//}