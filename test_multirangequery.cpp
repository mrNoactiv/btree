//#include "dstruct/paged/b+tree/cB+Tree.h"
//#include "common/data/cDataCollection.h"
//#include "common/data/cTuplesGenerator.h"
//#include "common/random/cGaussRandomGenerator.h"
//#include "common/datatype/cComparator.h"
//
//using namespace common::random;
//using namespace common::data;
//using namespace common::datatype;
//
////const unsigned int ITEM_COUNT = 2000000; //orig
////const unsigned int ITEM_COUNT = 4;
////const unsigned int ITEM_COUNT = 20;
////const unsigned int ITEM_COUNT = 1750;
////const unsigned int ITEM_COUNT = 1800;
////const unsigned int ITEM_COUNT = 2000;
//const unsigned int ITEM_COUNT = 15000;
////const unsigned int ITEM_COUNT = 400000;
////const unsigned int ITEM_COUNT = 500000;
////const unsigned int ITEM_COUNT = 2000000;
////const unsigned int ITEM_COUNT = 10000000;
//const unsigned int MAX_VALUE = ITEM_COUNT;
//
////const unsigned int CACHE_SIZE = 10000; //orig
////const unsigned int CACHE_SIZE = 20000;
//const unsigned int CACHE_SIZE = 200000;
////const unsigned int CACHE_SIZE = 400000;
//const unsigned int BLOCK_SIZE = /*2048;*/  8192;
//const unsigned int MAX_NODE_INMEM_SIZE = 1.25 * BLOCK_SIZE;
//
//// defines the length of the inserting tuples
//const unsigned int TUPLE_LENGTHS[] = { 4 };
//
//// defines the length of the inserting data
//const unsigned int DATA_LENGTHS[] = { 4 };
//
//// defines the type of data structure mode
////const unsigned int DSMODES[] = { cDStructConst::DSMODE_DEFAULT, cDStructConst::DSMODE_CODING, cDStructConst::DSMODE_RI /*, cDStructConst::DSMODE_RICODING*/ };
//const unsigned int DSMODES[] = { cDStructConst::DSMODE_DEFAULT };
//
//// defines type of tuple
////const unsigned int ITEM_TYPES[] = { cDStructConst::TUPLE, cDStructConst::NTUPLE };
//const unsigned int ITEM_TYPES[] = { cDStructConst::TUPLE };
//
//// defines the type of coding in the case of CODING and RICODING
//unsigned int CODETYPE = FIXED_LENGTH_CODING_ALIGNED;
//// ELIAS_DELTA 1		FIBONACCI2 2		FIBONACCI3  3		ELIAS_FIBONACCI 4
//// ELIAS_DELTA_FAST 5	FIBONACCI2_FAST 6	FIBONACCI3_FAST 7	ELIAS_FIBONACCI_FAST 8
//// FIXED_LENGTH_CODING 9	FIXED_LENGTH_CODING_ALIGNED 10
//
//// defines maximal compression ratio in RI, CODING and RICODING mode
//unsigned int COMPRESSION_RATIO = 2;
//
////unsigned int MULTIPLERANGEQUERY = false;
//unsigned int MULTIPLERANGEQUERY = true;
////unsigned int QUERIES_IN_MULTIQUERY = 3; // number of queries in multiquery
////unsigned int QUERIES_IN_MULTIQUERY = 4;
////unsigned int QUERIES_IN_MULTIQUERY = 5;
////unsigned int QUERIES_IN_MULTIQUERY = 12;
////unsigned int QUERIES_IN_MULTIQUERY = 18;
////unsigned int QUERIES_IN_MULTIQUERY = 50;
////unsigned int QUERIES_IN_MULTIQUERY = 150;
////unsigned int QUERIES_IN_MULTIQUERY = 500;
////unsigned int QUERIES_IN_MULTIQUERY = 1000;
//
////unsigned int QUERIES_IN_MULTIQUERY = 2000;
////unsigned int QUERIES_IN_MULTIQUERY = 2500;
//unsigned int QUERIES_IN_MULTIQUERY = 5000;
////unsigned int QUERIES_IN_MULTIQUERY = 10000;
////unsigned int QUERIES_IN_MULTIQUERY = 30000;
//
//const bool STACKRECOVERY = true;
//
//const unsigned int retry_RangeQuery = 1; // val644 - zopakovani provedeni rozsahovych dotazu
//
//unsigned int RUNTIME_MODE = cDStructConst::RTMODE_DEFAULT; // defines the mode (with or without validation) RTMODE_DEFAULT		RTMODE_VALIDATION
//
//// Histograms for each dimension will be created during build
//bool HISTOGRAMS = false;
//
//static const uint START_SEED = 865915;					// defines the starting seed of data generator
//static const uint INMEMCACHE_SIZE = 0; // 1048576;
//
//typedef cUInt tDomain; // defines domain used for loading tuples from collection file.
//typedef cTuple tKey;   // defines the type of tree key
/////	specification of collections ///
//int COLLECTION = cCollection::RANDOM;
//int COMPUTER = Computer::DBSYS;
//int QUERY_TYPE = cQueryType::INDEX_VALIDATION;
//int SEARCH_MODE = cRangeQueryConfig::SEARCH_DFS;
//
//cTuplesGenerator<tDomain, tKey> *generator; //generates random tuples or load them from a file.
//char *collectionFile, *queryFile;
//
//char dbPath[1024] = "quickdb";
//
//typedef cNTuple tKey_VarLen;
//typedef cTuple tKey_FixedLen;
//
//uint DSMODE, ITEM_TYPE, TUPLE_LENGTH, DATA_LENGTH;
//
//tKey_VarLen *mKey_VarLen;
//char *mData_VarLen[ITEM_COUNT];
//cSpaceDescriptor* mSD_VarLen;
//
//tKey_FixedLen *mKey_FixedLen;
//char *mData_FixedLen;
//cSpaceDescriptor* mSD_FixedLen;
//
//tKey_FixedLen *mAuxTuple1;
//tKey_FixedLen *mAuxTuple2;
//
////val644 start - RangeQuery
//tKey_FixedLen *qls;
//tKey_FixedLen *qhs;
////val644 end - RangeQuery
////int countCompareOrder;
//double basicTime;
////double basicTotalReadNodes;
//double timeOrderRQ;
//
//
//void printHeader();
//void Generate(int seed, unsigned int type, bool printInfo, bool randomLength = false);
//void LoadFromDataCollection();
//void Generate_RangeQuery(cBpTree<tKey_FixedLen>* mIndex_FixedLen, int minReturnsItems, int maxReturnsItems, bool printInfo);
////void PrintInfoCompare(cTreeHeader *myHeader, unsigned int basicCountCompare);
////void SaveToFileInfoCompare(string fileName, string typeRQ, int rq_min, int rq_max, bool new_typeRQ, double mTime, cTreeHeader *myHeader, unsigned int RQ_resultSize, unsigned int basicCountCompare, float indexSizeMB, unsigned int leafCountItems);
//void Quick_Sort_RQ(int start, int end);
//void Quick_Sort_mKey(int start, int end);
//
//void Create_VariableLen(bool variableData);
//bool Open_VariableLen();
//
//void Create_FixedLen();
//bool Open_FixedLen();
//
//void checkItem_variablelen(cBpTree<tKey_VarLen> *index, unsigned int j);
//bool checkItem_fixedlen(cBpTree<tKey_FixedLen> *index, unsigned int j);
//
//uint DSMODES_COUNT() { return sizeof(DSMODES) / sizeof(uint); };
//uint ITEM_TYPES_COUNT() { return sizeof(ITEM_TYPES) / sizeof(uint); };
//uint TUPLE_LENGTHS_COUNT() { return sizeof(TUPLE_LENGTHS) / sizeof(uint); };
//uint DATA_LENGTHS_COUNT() { return sizeof(DATA_LENGTHS) / sizeof(uint); };
//
//int main()
//{
//
//	/*_CrtSetReportMode(_CRT_WARN, _CRTDBG_MODE_FILE);
//	_CrtSetReportFile(_CRT_WARN, _CRTDBG_FILE_STDOUT);
//	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_FILE);
//	_CrtSetReportFile(_CRT_ERROR, _CRTDBG_FILE_STDOUT);
//	_CrtSetReportMode(_CRT_ASSERT, _CRTDBG_MODE_FILE);
//	_CrtSetReportFile(_CRT_ASSERT, _CRTDBG_FILE_STDOUT);*/
//
//	for (uint i = 0; i < TUPLE_LENGTHS_COUNT(); i++)
//	{
//		TUPLE_LENGTH = TUPLE_LENGTHS[i];
//		for (uint j = 0; j < DATA_LENGTHS_COUNT(); j++)
//		{
//			DATA_LENGTH = DATA_LENGTHS[j];
//			for (uint k = 0; k < ITEM_TYPES_COUNT(); k++)
//			{
//				ITEM_TYPE = ITEM_TYPES[k];
//				//val644 - start - Definovani, zda se pouzije nahodne generovani, nebo datova kolekce
//				if (COLLECTION == cCollection::RANDOM)
//				{
//					Generate(START_SEED, ITEM_TYPE, false, true);
//				}
//				else
//				{
//					LoadFromDataCollection();
//				}
//				//val644 - end - Definovani, zda se pouzije nahodne generovani
//				for (uint l = 0; l < DSMODES_COUNT(); l++)
//				{
//					DSMODE = DSMODES[l];
//					printHeader();
//					if (ITEM_TYPE == cDStructConst::TUPLE)
//					{
//						Create_FixedLen();
//						if (!Open_FixedLen())
//						{
//							printf("Error with seed %d\n", START_SEED);
//							return 0;
//						}
//					}
//
//					else
//					{
//
//						Create_VariableLen(false);
//						if (!Open_VariableLen())
//						{
//							printf("Error with seed %d\n", START_SEED);
//							return 0;
//						}
//					}
//					printf("--------------------------------------------------------------------------------\n");
//				}
//			}
//		}
//	}
//	system("PAUSE"); // val644
//	return 0;
//}
//
//// **********************************************************************
//// ********************** VarLen Items **********************************
//// **********************************************************************
//void Create_VariableLen(bool variableData)
//{
//	bool debug = false;
//	cTimer runtime;
//	tKey_VarLen tp(mSD_VarLen, TUPLE_LENGTH);
//	unsigned int count = ITEM_COUNT / 2;
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create(dbPath, CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree Header
//	cBpTreeHeader<tKey_VarLen> *mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD_VarLen, tp.GetSize(mSD_VarLen), TUPLE_LENGTH / 2, variableData, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
//	mHeader_VarLen->SetCodeType(CODETYPE);
//	mHeader_VarLen->SetRuntimeMode(RUNTIME_MODE);
//	mHeader_VarLen->SetHistogramEnabled(HISTOGRAMS);
//
//	// B-tree
//	cBpTree<tKey_VarLen> *mIndex_VarLen = new cBpTree<tKey_VarLen>();
//	if (!mIndex_VarLen->Create(mHeader_VarLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	runtime.Start();
//	for (unsigned int i = 0; i < count; i++)
//	{
//		if (i % 50000 == 0)
//		{
//			printf("Inserts: %d\r", i);
//			fflush(stdout);
//		}
//
//		mIndex_VarLen->Insert(mKey_VarLen[i], mData_VarLen[i]);
//	}
//	runtime.Stop();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n\n", mIndex_VarLen->GetHeader()->GetItemCount() / runtime.GetRealTime());
//
//	// -----------------------------------------------------------------------------
//	cTimer queryTimer;
//	queryTimer.Start();
//	for (unsigned int i = 0; i < count; i++)
//	{
//		if (i % 50000 == 0)
//		{
//			printf("Queries: %d\r", i);
//			fflush(stdout);
//		}
//
//		cTreeItemStream<tKey_VarLen>* resultSet = mIndex_VarLen->PointQuery(mKey_VarLen[i]);
//		if (resultSet->GetItemCount() != 1)
//		{
//			printf("Critical Error: Item was not found!");
//		}
//		else
//		{
//			// check data
//			char* resultData = (char*)(resultSet->GetItem() + tKey_VarLen::GetSize(resultSet->GetItem(), mSD_VarLen));
//			char dataLength = mData_VarLen[i][0];
//			char dataLength2 = resultData[0];
//			/*if (dataLength != dataLength2)
//			{
//			int c = 3;
//			}*/
//
//			/*for (unsigned int j = 1; j < dataLength; j++)
//			{
//			if (mData_VarLen[i][j] != resultData[j])
//			{
//			printf("Critical Error: Data are not correct: item order: %u,%u!", i, j);
//			mKey_FixedLen[i].Print("\n", mSD_VarLen);
//			}
//			}*/
//		}
//
//		resultSet->CloseResultSet();
//	}
//	queryTimer.Stop();
//	printf("\n");
//	queryTimer.Print(" - Query time\n");
//	printf("Performance: %.1f Queries/s\n\n", mIndex_VarLen->GetHeader()->GetItemCount() / queryTimer.GetRealTime());
//	// -----------------------------------------------------------------------------
//
//	//quickDB->GetNodeCache()->GetCacheStatistics()->Print();
//	delete mIndex_VarLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_VarLen;
//}
//
//bool Open_VariableLen()
//{
//	bool debug = false;
//	cTimer runtime;
//	tKey_VarLen tp(mSD_VarLen, TUPLE_LENGTH);
//
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Open(dbPath, CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not opened!\n");
//		exit(1);
//	}
//
//	// B-tree
//	cBpTreeHeader<tKey_VarLen> *mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", BLOCK_SIZE, mSD_VarLen, tp.GetSize(mSD_VarLen), DATA_LENGTH, false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
//	//cBpTreeHeader<tKey_VarLen> *mHeader_VarLen = new cBpTreeHeader<tKey_VarLen>("btree1", mSD_VarLen);
//	mHeader_VarLen->SetCodeType(CODETYPE);
//	mHeader_VarLen->SetRuntimeMode(RUNTIME_MODE);
//	mHeader_VarLen->SetHistogramEnabled(HISTOGRAMS);
//
//	cBpTree<tKey_VarLen> *mIndex_VarLen = new cBpTree<tKey_VarLen>();
//	if (!mIndex_VarLen->Open(mHeader_VarLen, quickDB, false))
//	{
//		mHeader_VarLen->Print();
//		printf("TestCreate: open failed!\n");
//		exit(0);
//	}
//
//	runtime.Start();
//	for (unsigned int i = ITEM_COUNT / 2; i < ITEM_COUNT; i++)
//	{
//		if (i % 50000 == 0)
//		{
//			printf("Inserts: %d\r", i);
//			fflush(stdout);
//		}
//		mIndex_VarLen->Insert(mKey_VarLen[i], mData_VarLen[i]);
//	}
//	runtime.Stop();
//	printf("\n");
//	runtime.Print(" - Insert time (after open)\n");
//
//	cTreeItemStream<tKey_VarLen>* result = mIndex_VarLen->RangeQuery(mKey_VarLen[0], mKey_VarLen[1]);
//	int resultSize = result->GetItemCount();
//	result->CloseResultSet();
//
//	printf("Inner/Leaf Nodes: %d/%d ", mIndex_VarLen->GetHeader()->GetInnerNodeCount(), mIndex_VarLen->GetHeader()->GetLeafNodeCount());
//	//quickDB->GetNodeCache()->GetCacheStatistics()->Print();
//	printf("Index Size: %.2f MB\n", mIndex_VarLen->GetIndexSizeMB(BLOCK_SIZE));
//
//	delete mIndex_VarLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_VarLen;
//
//	// printf("Index Size: %.2f MB\n", FileSize(dbPath));
//
//	return true;
//}
//
//void checkItem_variablelen(cBpTree<tKey_VarLen> *index, unsigned int j)
//{
//	cTreeItemStream<tKey_VarLen>* result = index->PointQuery(mKey_VarLen[j]);
//	if (result->GetItemCount() != 1)
//	{
//		printf("Polozka %d nenalezena: ", j);
//		mKey_VarLen[j].Print("\n", mSD_VarLen);
//	}
//	const char* item = result->GetItem();
//	const char* data = item + tKey_VarLen::GetSize(item, mSD_VarLen);
//
//	if (mKey_VarLen[j].Compare(item, mSD_VarLen) != 0 || !cDataVarlen::Compare(mData_VarLen[j], data, cDataVarlen::GetSize(data)))
//	{
//		printf("Polozka %d nekoresponduje\n", j);
//		mKey_VarLen[j].Print(" - inserted key\n", mSD_VarLen);
//		tKey_VarLen::Print(item, " - readed key\n", mSD_VarLen);
//		cDataVarlen::Print(mData_VarLen[j], " - inserted data\n");
//		cDataVarlen::Print(data, " - readed data\n");
//	}
//	result->CloseResultSet();
//}
//
//// **********************************************************************
//// ********************** FixLen Items **********************************
//// **********************************************************************
//
///**
//* Perform point query on the B-tree and compare the result with the tuples stored in the mKey_Fixedlen.
//*/
//bool checkItem_fixedlen(cBpTree<tKey_FixedLen> *index, unsigned int j)
//{
//	cTreeItemStream<tKey_FixedLen>* result = index->PointQuery(mKey_FixedLen[j]);
//	if (result->GetItemCount() != 1)
//	{
//		printf("Polozka %d nenalezena: ", j);
//		mKey_FixedLen[j].Print("\n", mSD_FixedLen);
//	}
//	const char* item = result->GetItem();
//	if (mKey_FixedLen[j].Compare(item, mSD_FixedLen) != 0)
//	{
//		printf("Polozka %d nekoresponduje\n", j);
//		mKey_FixedLen[j].Print(" - inserted key\n", mSD_FixedLen);
//		tKey_FixedLen::Print(item, " - readed key\n", mSD_FixedLen);
//		return false;
//	}
//	result->CloseResultSet();
//	return true;
//}
//
///**
//* Create the B-tree and insert one half of the data.
//*/
//void Create_FixedLen()
//{
//	cTimer runtime;
//	cTuple tp(mSD_FixedLen);
//	char* resultData = new char[DATA_LENGTH];
//
//	// creation of a new persistent file and opening the cache
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Create(dbPath, CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not created!\n");
//		exit(1);
//	}
//
//	// B-tree
//	cBpTreeHeader<tKey_FixedLen> *mHeader_FixedLen = new cBpTreeHeader<tKey_FixedLen>("btree1", BLOCK_SIZE, mSD_FixedLen, tp.GetSize(mSD_FixedLen), DATA_LENGTH, false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
//	mHeader_FixedLen->SetRuntimeMode(RUNTIME_MODE);
//	mHeader_FixedLen->SetCodeType(CODETYPE);
//	mHeader_FixedLen->SetHistogramEnabled(HISTOGRAMS);
//	mHeader_FixedLen->SetInMemCacheSize(INMEMCACHE_SIZE);
//
//	cBpTree<tKey_FixedLen> *mIndex_FixedLen = new cBpTree<tKey_FixedLen>();
//	if (!mIndex_FixedLen->Create(mHeader_FixedLen, quickDB))
//	{
//		printf("TestCreate: creation failed!\n");
//	}
//
//	// inserting tuples into the B-tree
//	runtime.Start();
//	if (COLLECTION == cCollection::RANDOM)
//	{
//		for (unsigned int i = 0; i <= ITEM_COUNT - 1; i++)
//		{
//			if (i % 50000 == 0)
//			{
//				printf("Inserts: %d\r", i);
//				fflush(stdout);
//			}
//			mIndex_FixedLen->Insert(mKey_FixedLen[i], mData_FixedLen);
//		}
//	}
//	else
//	{
//		int max = generator->GetTuplesCount();
//		for (unsigned int i = 0; i <= max - 1; i++)
//		{
//			if (i % 50000 == 0)
//			{
//				printf("Inserts: %d\r", i);
//				fflush(stdout);
//			}
//			mIndex_FixedLen->Insert(mKey_FixedLen[i], mData_FixedLen);
//		}
//	}
//	runtime.Stop();
//	printf("\n");
//	runtime.Print(" - Insert time\n");
//	printf("Performance: %.1f Inserts/s\n\n", mIndex_FixedLen->GetHeader()->GetItemCount() / runtime.GetRealTime());
//
//	bool insertOnly = true; //val644 - nastaveno na true
//
//	printf("QUERY PROCESSING WITHOUT RESULT SET\n");
//	if (!insertOnly)
//	{
//		// Perform queries
//		cTimer querytime;
//		querytime.Start();
//		for (unsigned int i = 0; i <= ITEM_COUNT / 2; i++)
//		{
//			if (i % 50000 == 0)
//			{
//				printf("Queries: %d\r", i);
//				fflush(stdout);
//			}
//
//			if (!mIndex_FixedLen->PointQuery(mKey_FixedLen[i], resultData))
//			{
//				printf("Critical Error: Item was not found!");
//				mKey_FixedLen[i].Print("\n", mSD_FixedLen);
//			}
//			else
//			{
//				// check data
//				for (unsigned int j = 0; j < DATA_LENGTH; j++)
//				{
//					if (mData_FixedLen[j] != resultData[j])
//					{
//						printf("Critical Error: Data are not correct: item order: %u,%u!", i, j);
//						mKey_FixedLen[i].Print("\n", mSD_FixedLen);
//					}
//				}
//			}
//		}
//		querytime.Stop();
//		printf("\n");
//		querytime.Print(" - Query time\n");
//		printf("Performance: %.1f Queries/s\n\n", mIndex_FixedLen->GetHeader()->GetItemCount() / querytime.GetRealTime());
//		// ----------------------------------------------------
//	}
//
//	printf("QUERY PROCESSING WITH RESULT SET\n");
//	if (!insertOnly)
//	{
//		// Perform queries
//		cTimer querytime;
//		querytime.Start();
//		for (unsigned int i = 0; i <= ITEM_COUNT / 2; i++)
//		{
//			if (i % 50000 == 0)
//			{
//				printf("Queries: %d\r", i);
//				fflush(stdout);
//			}
//
//			cTreeItemStream<tKey_FixedLen>* resultSet = mIndex_FixedLen->PointQuery(mKey_FixedLen[i]);
//
//			if (resultSet->GetItemCount() != 1)
//			{
//				printf("Critical Error: Item was not found!");
//				mKey_FixedLen[i].Print("\n", mSD_FixedLen);
//			}
//			else
//			{
//				// check data
//				char* resultData2 = (char*)(resultSet->GetItem() + mIndex_FixedLen->GetHeader()->GetKeySize());
//				for (unsigned int j = 0; j < DATA_LENGTH; j++)
//				{
//					if (mData_FixedLen[j] != resultData2[j])
//					{
//						printf("Critical Error: Data are not correct: item order: %u,%u!", i, j);
//						mKey_FixedLen[i].Print("\n", mSD_FixedLen);
//					}
//				}
//			}
//			resultSet->CloseResultSet();
//		}
//		querytime.Stop();
//		printf("\n");
//		querytime.Print(" - Query time\n");
//		printf("Performance: %.1f Queries/s\n\n", mIndex_FixedLen->GetHeader()->GetItemCount() / querytime.GetRealTime());
//		// ----------------------------------------------------
//	}
//
//
//	delete mIndex_FixedLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_FixedLen;
//	delete resultData;
//}
//
///**
//* Open the B-tree and insert the second half of the data.
//*/
//bool Open_FixedLen()
//{
//	cTimer runtime;
//	cTuple tp(mSD_FixedLen);
//
//	// opening of an existing persistent file and opening the cache
//	cQuickDB *quickDB = new cQuickDB();
//	if (!quickDB->Open(dbPath, CACHE_SIZE, MAX_NODE_INMEM_SIZE, BLOCK_SIZE))
//	{
//		printf("Critical Error: Cache Data File was not opened!\n");
//		exit(1);
//	}
//
//	// B-tree
//	cBpTreeHeader<tKey_FixedLen> *mHeader_FixedLen = new cBpTreeHeader<tKey_FixedLen>("btree1", BLOCK_SIZE, mSD_FixedLen, tp.GetSize(mSD_FixedLen), sizeof(int), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
//	mHeader_FixedLen->SetCodeType(CODETYPE);
//	mHeader_FixedLen->SetRuntimeMode(RUNTIME_MODE);
//	mHeader_FixedLen->SetHistogramEnabled(HISTOGRAMS);
//	mHeader_FixedLen->SetInMemCacheSize(INMEMCACHE_SIZE);	
//
//	cBpTree<tKey_FixedLen> *mIndex_FixedLen = new cBpTree<tKey_FixedLen>();
//	if (!mIndex_FixedLen->Open(mHeader_FixedLen, quickDB, false))
//	{
//		printf("TestCreate: opening failed!\n");
//		exit(0);
//	}
//
//	//runtime.Start();
//	//if (COLLECTION == cCollection::RANDOM)
//	//{
//	//	/*for (unsigned int i = ITEM_COUNT / 2 + 1; i < ITEM_COUNT; i++)
//	//	{
//	//		if (i % 50000 == 0)
//	//		{
//	//			printf("Inserts: %d\r", i);
//	//			fflush(stdout);
//	//		}
//	//		mIndex_FixedLen->Insert(mKey_FixedLen[i], mData_FixedLen);
//	//	}*/
//	//}
//	//else
//	//{
//	//	int max = generator->GetTuplesCount();
//	//	for (unsigned int i = max / 2; i < max; i++)
//	//	{
//	//		if (i % 50000 == 0)
//	//		{
//	//			printf("Inserts: %d\r", i);
//	//			fflush(stdout);
//	//		}
//	//		mIndex_FixedLen->Insert(mKey_FixedLen[i], mData_FixedLen);
//	//	}
//	//}
//	//runtime.Stop();
//	//printf("\n");
//	//runtime.Print(" - Insert time (after open)\n");
//
//	//val644 - zakomentovano
//	/*cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery(*mAuxTuple1, *mAuxTuple2);
//	if (result->GetItemCount() != 0)
//	{
//	printf("open_fixedlen - empty range query failed (it returns some result)\n");
//	}
//	result->CloseResultSet();*/
//	//val644 - zakomentovano
//
//	//val644 - start - Range Query
//	mIndex_FixedLen->PrintInfo();
//
//	if (COLLECTION == cCollection::RANDOM)
//	{
//		Quick_Sort_mKey(0, ITEM_COUNT - 1);
//	}
//	else
//	{
//		Quick_Sort_mKey(0, generator->GetTuplesCount() - 1);
//	}
//
//	//unsigned int basicCountCompare = 0;	
//
//	int rq_result_count[9][2] = {
//		{ 1, 5 }, // 1-10, 11-99, 100-
//		{ 5, 50 },
//		{ 50, 100 },
//		{ 100, 500 },
//		{ 500, 1000 },
//		{ 1000, 5000 },
//		{ 5000, 10000 },
//		{ 10000, 50000 },
//		{ 1, 50000 }
//	};
//
//	for (unsigned int t = 0; t < 5; t++)
//	{
//		cTuple::typeRQ = 0;
//		cTuple::typeRQordered = false;
//		string collectionName = "zwi0009";		
//
//		bool sortRangeQuery = cTuple::typeRQordered;
//		bool printInfoRandomRQ = false; //ZWI0009
//		printf("\n________________________________________________________________________________");
//
//		for (unsigned int tp = 0; tp < 3; tp++)
//		{
//			cTuple::ResetStatistic();
//			switch (tp)
//			{
//			case 0:
//				cTuple::typeRQ = 1;
//				cTuple::typeRQordered = true;
//				timeOrderRQ = 0;
//				cTuple::countCompareOrder = 0;
//				Generate_RangeQuery(mIndex_FixedLen, rq_result_count[t][0], rq_result_count[t][1], printInfoRandomRQ); //val644 - generovani rozsahovych dotazu
//				break;
//			case 1:
//				cTuple::typeRQ = 2;
//				cTuple::typeRQordered = true;
//				break;
//			case 2:
//				cTuple::typeRQ = 0;
//				cTuple::typeRQordered = false;
//				timeOrderRQ = 0;
//				cTuple::countCompareOrder = 0;
//				Generate_RangeQuery(mIndex_FixedLen, rq_result_count[t][0], rq_result_count[t][1], printInfoRandomRQ); //val644 - generovani rozsahovych dotazu
//				break;
//			default:
//				break;
//			}
//
//			if (QUERIES_IN_MULTIQUERY > 0)
//			{
//				unsigned int sum = 0;
//
//				cTreeHeader *myTreeHeader = mIndex_FixedLen->GetHeader();
//
//				int rq_resultCount;
//				if (cTuple::typeRQordered & cTuple::typeRQ == 1)
//				{
//					runtime.Start();
//					for (unsigned int i = 0; i < retry_RangeQuery; i++)
//					{
//						sum = 0;
//						cTuple::basicCountCompare = 0;
//						cTuple::ResetStatistic();
//
//						for (unsigned int q = 0; q < QUERIES_IN_MULTIQUERY; q++)
//						{
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery_LoHi(qls[q], qhs[q]);
//							sum += result->GetItemCount();
//
//							cTuple::basicCountCompare += cTuple::countCompare;
//
//							//printf("\nRange Query [%i] - Result size: %i", i, result->GetItemCount());
//							/*result->SetFirstItem();
//							for (unsigned int r = 0; r < result->GetItemCount(); r++)
//							{
//							result->Next();
//							printf("\n\tResult item[%i]", r);
//							cTuple::Print(result->GetItem(), "", mSD_FixedLen);
//							}*/
//
//							result->CloseResultSet();
//						}
//						for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//						{
//							qls[flag].flagRQ = 0;
//						}
//					}
//
//					rq_resultCount = sum;
//					runtime.Stop();
//					printf("\nRange Query LH SUM - Results size: %i", sum);
//					printf("\n\tTime: ");
//					runtime.Print("");
//					basicTime = runtime.GetRealTime();
//					sum = 0;
//					cTuple::basicTotalReadNodes = cTuple::GetTotalReadNodes();
//					printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//					cTuple::basicCountCompare = cTuple::countCompare;
//					cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//					//SaveToFileInfoCompare(collectionName, "RangeQueryLoHi", rq_result_count[t][0], rq_result_count[t][1], true, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount(), basicTime);
//					cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_LoHi", rq_result_count[t][0], rq_result_count[t][1], true, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);					
//				}
//				else
//				{
//					//SaveToFileInfoCompare(collectionName, "RangeQuery", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//				}
//
//				//val644 - end - Range Query
//
//				//val644 - Range Query Lo - Hi
//				if (cTuple::typeRQordered & cTuple::typeRQ == 1)
//				{
//					runtime.Start();
//					for (unsigned int i = 0; i < retry_RangeQuery; i++)
//					{
//						sum = 0;
//						cTuple::ResetStatistic();
//
//						for (unsigned int q = 0; q < QUERIES_IN_MULTIQUERY; q++)
//						{
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery(qls[q], qhs[q]);
//							sum += result->GetItemCount();
//							result->CloseResultSet();
//						}
//						for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//						{
//							qls[flag].flagRQ = 0;
//						}
//					}
//
//					rq_resultCount = sum;
//					runtime.Stop();
//					printf("\n\nRange Query SUM - Results size: %i", sum);
//					printf("\n\tTime: ");
//					runtime.Print("");
//					sum = 0;
//					printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//					//PrintInfoCompare(myTreeHeader, basicCountCompare);
//					cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//					//SaveToFileInfoCompare(collectionName, "RangeQuery", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//					cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//				}
//
//				////setrizeni rozsahovych dotazu
//				cTuple::countCompareOrder = 0;
//				if (cTuple::typeRQordered)
//				{
//					cTuple::countCompare = 0;
//					cTimer timer;
//					timer.Start();
//					Quick_Sort_RQ(0, QUERIES_IN_MULTIQUERY - 1);
//					timer.Stop();
//					timeOrderRQ = timer.GetRealTime();
//					printf("\n\nCountCompareRQ order: %i, Time: %i", cTuple::countCompare, timeOrderRQ);
//					cTuple::countCompareOrder = cTuple::countCompare;
//				}
//
//				//val644 - Range Query Order Lo - Hi
//				if (cTuple::typeRQordered & cTuple::typeRQ == 1)
//				{
//					runtime.Start();
//					for (unsigned int i = 0; i < retry_RangeQuery; i++)
//					{
//						sum = 0;
//						cTuple::ResetStatistic();
//
//						for (unsigned int q = 0; q < QUERIES_IN_MULTIQUERY; q++)
//						{
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery_LoHi(qls[q], qhs[q]);
//							sum += result->GetItemCount();
//							result->CloseResultSet();
//						}
//						for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//						{
//							qls[flag].flagRQ = 0;
//						}
//					}
//
//					rq_resultCount = sum;
//					runtime.Stop();
//					printf("\n\nRange Query LH Order SUM - Results size: %i", sum);
//					printf("\n\tTime: ");
//					runtime.Print("");
//					sum = 0;
//					printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//					//PrintInfoCompare(myTreeHeader, basicCountCompare);
//					cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//					//SaveToFileInfoCompare(collectionName, "RangeQueryLoHiO", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//					cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_LoHiO", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//				}
//
//				if (MULTIPLERANGEQUERY)
//				{
//					cRangeQueryConfig config;
//					config.SetQueryProcessingType(cRangeQueryProcessorConstants::RQ_BTREE_SEQ);
//					//config.SetLeafIndicesCapacity(1024);
//					//config.SetMaxReadNodes(1024);
//					config.SetFinalResultSize(0);
//					//config.SetStackRecovery(STACKRECOVERY);
//
//					//val644 - start - Range Query Batch Seq
//					runtime.Start();
//
//					for (unsigned int i = 0; i < retry_RangeQuery; i++)
//					{
//						cTuple::ResetStatistic();
//
//						cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->BatchRangeQuery(qls, qhs, &config, QUERIES_IN_MULTIQUERY, NULL, NULL);
//
//						if (i + 1 == retry_RangeQuery)
//						{
//							printf("\n\nRange Query Batch Seq - Result size: %i", result->GetItemCount());
//							rq_resultCount = result->GetItemCount();
//						}
//						result->CloseResultSet();
//						for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//						{
//							qls[flag].flagRQ = 0;
//						}
//					}			
//
//					runtime.Stop();
//					printf("\n\tTime: ");
//					runtime.Print("");
//					printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//					//PrintInfoCompare(myTreeHeader, basicCountCompare);
//					cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//					//SaveToFileInfoCompare(collectionName, "RangeQuerySeq", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//					//cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_Seq", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//					cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_Seq", rq_result_count[t][0], rq_result_count[t][1], true, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//					printf("\n");
//					//val644 - end - Range Query Batch Seq
//
//					//val644 - start - Range Query Batch Binary
//
//					if (DSMODE == cDStructConst::RTMODE_DEFAULT)
//					{
//						config.SetQueryProcessingType(cRangeQueryProcessorConstants::RQ_BTREE_BIN);
//						runtime.Start();
//						for (unsigned int i = 0; i < retry_RangeQuery; i++)
//						{
//							cTuple::ResetStatistic();
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->BatchRangeQuery(qls, qhs, &config, QUERIES_IN_MULTIQUERY, NULL, NULL);
//							if (i + 1 == retry_RangeQuery)
//							{
//								printf("\nRange Query Batch Binary - Result size: %i", result->GetItemCount());
//								rq_resultCount = result->GetItemCount();
//							}
//							result->CloseResultSet();
//							for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//							{
//								qls[flag].flagRQ = 0;
//							}
//						}
//
//						runtime.Stop();
//
//						printf("\n\tTime: ");
//						runtime.Print("");
//						printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//						//PrintInfoCompare(myTreeHeader, basicCountCompare);
//						cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//						//SaveToFileInfoCompare(collectionName, "RangeQueryBin", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//						cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_Bin", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//						printf("\n");
//					}
//					//val644 - end - Range Query Batch Binary
//
//					//val644 - start - Range Query Batch Hybrit (Na nelistovych uzlech se provadi seq prochazeni)
//
//					if (DSMODE == cDStructConst::RTMODE_DEFAULT)
//					{
//						config.SetQueryProcessingType(cRangeQueryProcessorConstants::RQ_BTREE_L0_SEQ);
//						runtime.Start();
//						for (unsigned int i = 0; i < retry_RangeQuery; i++)
//						{
//							cTuple::ResetStatistic();
//
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->BatchRangeQuery(qls, qhs, &config, QUERIES_IN_MULTIQUERY, NULL, NULL);
//							if (i + 1 == retry_RangeQuery)
//							{
//								printf("\nRange Query Batch LO Seq - Result size: %i", result->GetItemCount());
//								rq_resultCount = result->GetItemCount();
//							}
//							result->CloseResultSet();
//							for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//							{
//								qls[flag].flagRQ = 0;
//							}
//						}
//						runtime.Stop();
//
//						printf("\n\tTime: ");
//						runtime.Print("");
//						printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//						//PrintInfoCompare(myTreeHeader, basicCountCompare);
//						cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//						//SaveToFileInfoCompare(collectionName, "RangeQueryHyb1", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//						cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_L0_Seq", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//						printf("\n");
//					}
//					////val644 - end - Range Query Batch Hybrit (Na nelistovych uzlech se provadi seq prochazeni)
//
//					////val644 - start - Range Query Batch Hybrit2 (Seq prochazeni na korenovem uzlu, zbytek bin prochazeni)
//					if (DSMODE == cDStructConst::RTMODE_DEFAULT)
//					{
//						config.SetQueryProcessingType(cRangeQueryProcessorConstants::RQ_BTREE_L_LAST_BIN);
//						runtime.Start();
//						for (unsigned int i = 0; i < retry_RangeQuery; i++)
//						{
//							cTuple::ResetStatistic();
//							cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->BatchRangeQuery(qls, qhs, &config, QUERIES_IN_MULTIQUERY, NULL, NULL);
//							if (i + 1 == retry_RangeQuery)
//							{
//								printf("\nRange Query Batch L Last Bin - Result size: %i", result->GetItemCount());
//								rq_resultCount = result->GetItemCount();
//							}
//							result->CloseResultSet();
//							for (unsigned int flag = 0; flag < QUERIES_IN_MULTIQUERY; flag++)
//							{
//								qls[flag].flagRQ = 0;
//							}
//						}
//						runtime.Stop();
//
//						printf("\n\tTime: ");
//						runtime.Print("");
//						printf(" - [%f%%]", (((runtime.GetRealTime() / basicTime)) * 100));
//
//						//PrintInfoCompare(myTreeHeader, basicCountCompare);
//						cTuple::PrintInfoCompare(cTuple::basicCountCompare, myTreeHeader->GetHeight());
//						//SaveToFileInfoCompare(collectionName, "RangeQueryHyb2", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), myTreeHeader, rq_resultCount, cTuple::basicCountCompare, mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//						cTuple::SaveToFileStatisticInfoCompare(collectionName, "RQ_L_Last_Bin", rq_result_count[t][0], rq_result_count[t][1], false, runtime.GetRealTime(), timeOrderRQ, rq_resultCount, retry_RangeQuery, QUERIES_IN_MULTIQUERY, basicTime);
//
//						printf("\n");
//					}
//					//val644 - end - Range Query Batch Hybrit2 (Seq prochazeni na korenovem uzlu, zbytek bin prochazeni)
//				}
//				else
//				{
//					// test where we search for every tuple in the B-tree
//					for (unsigned int j = 0; j < ITEM_COUNT; j++)
//					{
//						if (j % 50000 == 0)
//						{
//							printf("checkItem: %d\r", j);
//							fflush(stdout);
//						}
//
//						if (!checkItem_fixedlen(mIndex_FixedLen, j))
//						{
//							delete mIndex_FixedLen;
//							quickDB->Close();
//							delete quickDB;
//							delete mHeader_FixedLen;
//
//							return false;
//						}
//					}
//				}
//			}
//		}
//		//system("PAUSE"); // val644
//	}
//	//quickDB->GetNodeCache()->GetCacheStatistics()->Print();
//	printf("\nInner/Leaf Nodes: %d/%d ", mIndex_FixedLen->GetHeader()->GetInnerNodeCount(), mIndex_FixedLen->GetHeader()->GetLeafNodeCount());
//	printf("Index Size: %.2f MB\n", mIndex_FixedLen->GetIndexSizeMB(BLOCK_SIZE));
//
//	mIndex_FixedLen->PrintInfo();
//
//	if ((DSMODE == cDStructConst::DSMODE_RI) && (RUNTIME_MODE == cDStructConst::RTMODE_VALIDATION))
//	{
//		mIndex_FixedLen->PrintSubNodesDistribution("snDistribution.txt");
//	}
//	printf("\nEnd benchmark range query.\n");
//	system("PAUSE"); //val644
//	delete mIndex_FixedLen;
//	quickDB->Close();
//	delete quickDB;
//	delete mHeader_FixedLen;
//
//	return true;
//}
//
//
//// **********************************************************************
//// ********************** Item & Data Generator *************************
//// **********************************************************************
//
//void Generate(int seed, unsigned int type, bool printInfo, bool randomLength)
//{
//	mSD_VarLen = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	mSD_FixedLen = new cSpaceDescriptor(TUPLE_LENGTH, new cUInt());
//	cGaussRandomGenerator rg(seed);
//
//	// preparation of the items
//	if (type == cDStructConst::NTUPLE)
//	{
//		mKey_VarLen = new tKey_VarLen[ITEM_COUNT];
//		for (unsigned int i = 0; i < ITEM_COUNT; i++)
//		{
//			unsigned int len = (randomLength) ? i % (TUPLE_LENGTH - 1) + 2 : TUPLE_LENGTH;
//
//			mKey_VarLen[i].Resize(mSD_VarLen, len);
//			for (unsigned int j = 0; j < len; j++)
//			{
//				mKey_VarLen[i].SetValue(j, rg.GetNextUInt(MAX_VALUE), mSD_VarLen);
//			}
//			mKey_VarLen[i].SetLength(len);
//
//
//			mData_VarLen[i] = new char[len * 2 + 1];
//			for (unsigned int j = 1; j < len * 2; j++)
//			{
//				mData_VarLen[i][j] = 'a';
//			}
//			mData_VarLen[i][0] = len * 2;
//		}
//	}
//	else
//	{
//		mKey_FixedLen = new tKey_FixedLen[ITEM_COUNT];
//		for (unsigned int i = 0; i < ITEM_COUNT; i++)
//		{
//			mKey_FixedLen[i].Resize(mSD_FixedLen);
//			for (unsigned int j = 0; j < TUPLE_LENGTH; j++)
//			{				
//				mKey_FixedLen[i].SetValue(j, rg.GetNextUInt(MAX_VALUE), mSD_FixedLen); // setting a random value into each dimension of this tuple
//			}
//		}
//
//		mData_FixedLen = new char[DATA_LENGTH];
//		for (unsigned int j = 0; j < DATA_LENGTH; j++)
//		{
//			mData_FixedLen[j] = (char)j;
//		}
//
//		mAuxTuple1 = new tKey_FixedLen(mSD_FixedLen); // auxiliary tuple used during test
//		mAuxTuple2 = new tKey_FixedLen(mSD_FixedLen); // auxiliary tuple used during test
//
//		for (unsigned int j = 0; j < TUPLE_LENGTH; j++)
//		{
//			mAuxTuple1->SetValue(j, 150000, mSD_FixedLen);
//			mAuxTuple2->SetValue(j, 150000, mSD_FixedLen);
//		}
//	}
//
//	//ZWI0009 - PRINT TEST
//	if (printInfo){
//		if (type == cDStructConst::NTUPLE)
//		{
//			for (unsigned int i = 0; i < ITEM_COUNT; i++)
//			{
//				printf("VARLEN TUPLE #%d: [", i);
//				for (unsigned int j = 0; j < mKey_VarLen[i].GetLength(); j++)
//				{
//					printf("%d", mKey_VarLen[i].GetUInt(j, mSD_FixedLen));
//					if (j < mKey_VarLen[i].GetLength() - 1)
//					{
//						printf(", ");
//					}
//				}
//				printf("]\n", i);
//			}
//		}
//		else
//		{
//			for (unsigned int i = 0; i < ITEM_COUNT; i++)
//			{
//				printf("FIXLEN TUPLE #%d: [", i);
//				for (unsigned int j = 0; j < TUPLE_LENGTH; j++)
//				{
//					printf("%d", mKey_FixedLen[i].GetUInt(j, mSD_FixedLen));
//					if (j < TUPLE_LENGTH - 1)
//					{
//						printf(", ");
//					}
//				}
//				printf("]\n", i);
//			}
//		}
//	}
//}
//
//
//// **********************************************************************
//// ********************** Header Generator *************************
//// **********************************************************************
//
///*
//autor: Miroslav Valecko - val644
//*/
//
//void LoadFromDataCollection()
//{
//	collectionFile = cDataCollection::COLLECTION_FILE(COLLECTION, COMPUTER);
//	queryFile = cDataCollection::QUERY_FILE(COLLECTION, COMPUTER);
//	generator = new cTuplesGenerator<cUInt, tKey_FixedLen>(collectionFile, false);
//
//	mSD_FixedLen = generator->GetSpaceDescriptor();
//
//	mKey_FixedLen = new tKey_FixedLen[generator->GetTuplesCount()];
//	for (unsigned int i = 0; i < generator->GetTuplesCount(); i++)
//	{
//		generator->GetNextTuple(mKey_FixedLen[i]);
//	}
//
//	mData_FixedLen = new char[DATA_LENGTH];
//	for (unsigned int j = 0; j < DATA_LENGTH; j++)
//	{
//		mData_FixedLen[j] = (char)j;
//	}
//}
//
///*
//autor: Miroslav Valecko - val644
//
//input params:
//mIndex_FixedLen - created BTree index
//sort - ordering range query
//minReturnsItems - range query min returns items in Btree
//maxReturnsItems - range query max returns items in Btree
//printInfo - print info
//*/
//void Generate_RangeQuery(cBpTree<tKey_FixedLen>* mIndex_FixedLen, int minReturnsItems, int maxReturnsItems, bool printInfo)
//{
//	qls = new tKey_FixedLen[QUERIES_IN_MULTIQUERY];
//	qhs = new tKey_FixedLen[QUERIES_IN_MULTIQUERY];
//	tKey_FixedLen tmp;
//
//	int seed = START_SEED;
//	cGaussRandomGenerator rg(seed);
//
//	int maxNumber;
//	if (COLLECTION == cCollection::RANDOM)
//	{
//		maxNumber = ITEM_COUNT;
//	}
//	else
//	{
//		maxNumber = generator->GetTuplesCount();
//	}
//
//	int sum = 0;
//
//	for (unsigned int q = 0; q < QUERIES_IN_MULTIQUERY; q++)
//	{
//		int randomKey = rg.GetNextUInt(maxNumber);
//
//		qls[q].Resize(mSD_FixedLen);
//		mKey_FixedLen[randomKey].CopyTo(qls[q], mSD_FixedLen);
//
//		int countRQ = 0;
//		while (countRQ < minReturnsItems)
//		{
//			if (minReturnsItems == 1 && maxReturnsItems == 50000)
//			{
//				if (q < 800)
//				{
//					countRQ = rg.GetNextUInt(250);
//				}
//				else
//				{
//					countRQ = rg.GetNextUInt(maxReturnsItems);
//				}
//			}
//			else
//			{
//				countRQ = rg.GetNextUInt(maxReturnsItems);
//			}
//			//countRQ = rg.GetNextUInt(maxReturnsItems);
//		}
//
//		
//
//		cTreeItemStream<tKey_FixedLen>* resultGetRangeQ = mIndex_FixedLen->GetRandomRangeQuery(qls[q], countRQ, NULL);
//		if (resultGetRangeQ->GetItemCount() == 0)
//		{
//			q--;
//			resultGetRangeQ->CloseResultSet();
//		}
//		else
//		{
//			const char* highQ = resultGetRangeQ->GetItem();
//			qhs[q].Resize(mSD_FixedLen);
//
//			for (unsigned int s = 0; s < mSD_FixedLen->GetDimension(); s++)
//			{
//				qhs[q].SetValue(s, cTuple::GetInt(highQ, s, mSD_FixedLen), mSD_FixedLen);
//			}
//			resultGetRangeQ->CloseResultSet();
//
//			// ZWI0009 - SWITCH WRONG DATA
//			for (unsigned j = 0; j < mSD_FixedLen->GetDimension(); j++)
//			{
//				int qlsValue = qls[q].GetInt(j, mSD_FixedLen);
//				int qhsValue = qhs[q].GetInt(j, mSD_FixedLen);
//
//				if (qlsValue > qhsValue)
//				{
//					int temp = qls[q].GetInt(j, mSD_FixedLen);
//
//					qls[q].SetValue(j, qhs[q].GetInt(j, mSD_FixedLen), mSD_FixedLen);
//					qhs[q].SetValue(j, temp, mSD_FixedLen);
//
//				}
//			}
//			// END - ZWI0009 - SWITCH WRONG DATA
//
//			cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery(qls[q], qhs[q]);
//			if ((result->GetItemCount() > maxReturnsItems) | (result->GetItemCount() < minReturnsItems))
//			{
//				q--;
//			}
//			sum += result->GetItemCount();
//
//			result->CloseResultSet();
//		}		
//	}
//
//	sum = sum;
//
//	printf("\nRangeQuery. %ix[%i - %i], Sorted: %s", QUERIES_IN_MULTIQUERY, minReturnsItems, maxReturnsItems, cTuple::typeRQordered ? "true" : "false");
//	if (printInfo)
//	{
//		printf("\n________________________________________________________________________________\n");
//	}
//
//	//Quick_Sort_RQ(0, QUERIES_IN_MULTIQUERY - 1);
//
//	if (printInfo)
//	{
//		printf("Nesetrizene rozsahove dotazy\n");
//
//		for (unsigned int i = 0; i < QUERIES_IN_MULTIQUERY; i++)
//		{
//			printf("\n[%i] LOW", i);
//			qls[i].Print("->HIGH", mSD_FixedLen);
//			qhs[i].Print("\n", mSD_FixedLen);
//			cTreeItemStream<tKey_FixedLen>* result = mIndex_FixedLen->RangeQuery(qls[i], qhs[i]);
//			printf("[%i] Result Items Count: %i\n", i, result->GetItemCount());
//			result->CloseResultSet();
//
//			// ZWI0009 - COMPARE RANGE QUERY VALUES
//			bool errorCheck = false;
//			for (unsigned j = 0; j < mSD_FixedLen->GetDimension(); j++)
//			{
//				uint qlsValue = qls[i].GetInt(j, mSD_FixedLen);
//				uint qhsValue = qhs[i].GetInt(j, mSD_FixedLen);
//
//				if (qlsValue > qhsValue)
//				{
//					errorCheck = true;
//					printf("\nWRONG DATA AT POSITION [%i, %i] - QLS: %i, QHS: %i", i, j, qlsValue, qhsValue);
//				}
//			}
//
//			if (errorCheck == false)
//			{
//				printf("\nNO COMPARE ERRORS FOUND");
//			}
//
//			printf("\n");
//			// END - \nZWI0009 - COMPARE RANGE QUERY VALUES
//		}
//		printf("\n_______________________________________________________________________________\n");
//	}
//}
//
///*
//autor: Miroslav Valecko - val644
//*/
////void PrintInfoCompare(cTreeHeader *myHeader, unsigned int basicCountCompare)
////{
////	bool fullInfo = true;
////	float avg;
////	float a;
////	float b;
////
////	a = cTuple::countCompare;
////	b = basicCountCompare;
////	avg = a / b;
////	avg = (avg)* 100;
////	printf("\n    CountCompare SUM: %i \t [%0.3f %%]", cTuple::countCompare, avg);
////
////	a = cTuple::countCompare + countCompareOrder;
////	avg = a / b;
////	avg = (avg)* 100;
////
////	printf("\n       CC with order: %i \t [%0.3f %%]", (cTuple::countCompare + countCompareOrder), avg);
////
////	a = cTuple::countCompare;
////	b = cTuple::callCountCompare;
////	avg = a / b;
////	printf("\n             Call CC: %i", cTuple::callCountCompare);
////	printf("\n        AVG compare Tuple: %f", avg);
////
////	/*avg = (float)cTuple::countCompare / myHeader->GetNodeCount();
////	printf("\n        SUM/AllNodes: %i/%i = %4.3f", cTuple::countCompare, myHeader->GetNodeCount(), avg);
////
////	avg = (float)cTuple::countCompare / myHeader->GetItemCount();
////	printf("\n        SUM/AllItems: %i/%i = %4.3f", cTuple::countCompare, myHeader->GetItemCount(), avg);*/
////
////	int sum = 0;
////	for (unsigned int i = 0; i < 24; i++)
////	{
////		sum += cTuple::readNodesInLevel[i];
////	}
////	a = sum;
////	b = basicTotalReadNodes;
////	avg = a / b;
////	avg = (avg)* 100;
////	printf("\n        AllReadsNodes: %i\t[%0.3f%%]", sum, avg);
////
////	printf("\n    CountCompareFor: ");
////	if (fullInfo)
////	{
////		for (unsigned int i = 0; i < 24; i++)
////		{
////			if (cTuple::countCompareLevel[i] != 0)
////			{
////				printf("\n\tLevel[%i]: %i", i, cTuple::countCompareLevel[i]);
////
////				int avgForNodes = 0;
////
////				if (i == 0)
////				{
////					printf("\n\t   CountItems: %i", cTuple::itemsCountForLevel);
////					printf("\n\t   TotalReadsNodes: %i", cTuple::readNodesInLevel[i]);
////					//avg = (float)cTuple::countCompareLevel[i] / QUERIES_IN_MULTIQUERY;
////					//printf("\n\t   /RangeQueryCount: %i/%i = %4.3f", cTuple::countCompareLevel[i], QUERIES_IN_MULTIQUERY, avg);
////				}
////				else if (i > 0)
////				{
////					printf("\n\t   TotalReadsNodes: %i", cTuple::readNodesInLevel[i]);
////
////					if (i == myHeader->GetHeight())
////					{
////						//avg = (float)cTuple::countCompareLevel[i] / myHeader->GetLeafNodeCount();
////						//printf("\n\t   CCFL/LeafNodes: %i/%i = %4.3f", cTuple::countCompareLevel[i], myHeader->GetLeafNodeCount(), avg);
////						//avg = (float)cTuple::countCompareLevel[i] / myHeader->GetLeafItemCount();
////						//printf("\n\t   CCFL/LeafItems: %i/%i = %4.3f", cTuple::countCompareLevel[i], myHeader->GetLeafItemCount(), avg);
////					}
////				}
////			}
////		}
////	}
////}
//
////void SaveToFileInfoCompare(string fileName, string typeRQ, int rq_min, int rq_max, bool new_typeRQ, double mTime, cTreeHeader *myHeader, unsigned int RQ_resultSize, unsigned int basicCountCompare, float indexSizeMB, unsigned int leafCountItems)
////{
////	ofstream saveFile;
////	saveFile.open(fileName + ".csv", std::ios::app);
////
////	if (new_typeRQ)
////	{
////		saveFile << "\n";
////		saveFile << "\n";
////		saveFile << "\n";
////		saveFile << "Pocet opakovani rozsahovych dotazu;" << retry_RangeQuery;
////		saveFile << "\nPocet klicu;" << myHeader->GetLeafItemCount() << ";Velikost jednoho rozsahoveho dotazu;Pocet rozsahovych dotazu\n";
////		saveFile << "Velikost indexu: " << indexSizeMB << "MB;;;" << QUERIES_IN_MULTIQUERY << ";;;;;;;;;;;";
////		for (unsigned int i = 0; i < 24; i++)
////		{
////			if (cTuple::countCompareLevel[i] != 0)
////			{
////				saveFile << ";Uroven" << i;
////				if (i == 0)
////				{
////					saveFile << ";Uroven" << i;
////					saveFile << ";Uroven" << i;
////				}
////				else
////				{
////					saveFile << ";Uroven" << i;
////				}
////				if (i < 23)
////				{
////					if (cTuple::countCompareLevel[i + 1] == 0)
////					{
////						saveFile << ";Uroven" << i;
////					}
////				}
////			}
////		}
////		saveFile << "\n;;;";
////		saveFile << "Vykonavany cas;Cas v %;Pocet porovnani;Pocet porovnani %;Setrizeni;Cas setrizeni;Celkovy pocet porovnani;Celkovy pocet porovnani v %; Velikost vysledku;Prumer porov. na klic;Pocet nactenych uzlu;Pocet nactenych uzlu %";
////		for (unsigned int i = 0; i < 24; i++)
////		{
////			if (cTuple::countCompareLevel[i] != 0)
////			{
////				saveFile << ";Pocet porovnani";
////				if (i == 0)
////				{
////					saveFile << ";Pocet klicu";
////					saveFile << ";Nactenych uzlu";
////				}
////				else
////				{
////					saveFile << ";Nactenych uzlu";
////				}
////				if (i < 23)
////				{
////					if (cTuple::countCompareLevel[i + 1] == 0)
////					{
////						saveFile << ";Pocet listovych uzlu";
////					}
////				}
////			}
////		}
////	}
////	saveFile << "\n";
////
////	if (typeRQ == "RangeQuery" | typeRQ == "RangeQueryOrder" | typeRQ == "RangeQueryLoHi" | typeRQ == "RangeQueryLoHiO")
////	{
////		saveFile << ";" << (char *)&typeRQ << ";" << rq_min << " ~ " << rq_max << ";" << mTime << ";" << (((mTime / basicTime)) * 100);
////	}
////	else
////	{
////		saveFile << ";" << (char *)&typeRQ << " - " << cTuple::typeRQ << ";" << rq_min << " ~ " << rq_max << ";" << mTime << ";" << (((mTime / basicTime)) * 100);
////	}
////
////	float avg;
////	float a;
////	float b;
////
////	a = cTuple::countCompare;
////	b = basicCountCompare;
////	avg = a / b;
////	avg = (avg)* 100;
////	saveFile << ";" << cTuple::countCompare << ";" << avg << ";" << cTuple::countCompareOrder << ";" << timeOrderRQ;
////
////	a = cTuple::countCompare + cTuple::countCompareOrder;
////	avg = a / b;
////	avg = (avg)* 100;
////	saveFile << ";" << (cTuple::countCompareOrder + cTuple::countCompare) << ";" << avg << ";" << RQ_resultSize;
////
////	a = cTuple::countCompare;
////	b = cTuple::callCountCompare;
////	avg = a / b;
////	saveFile << ";" << avg;
////
////	int sum = 0;
////	for (unsigned int i = 0; i < 24; i++)
////	{
////		sum += cTuple::readNodesInLevel[i];
////	}
////	a = sum;
////	b = cTuple::basicTotalReadNodes;
////	avg = a / b;
////	avg = (avg)* 100;
////	saveFile << ";" << sum << ";" << avg;
////
////	uint cmpCount = cComparator<void>::CountCompare;
////
////	for (unsigned int i = 0; i < 24; i++)
////	{
////		if (cTuple::countCompareLevel[i] != 0)
////		{
////			saveFile << ";" << cTuple::countCompareLevel[i];
////			if (i == 0)
////			{
////				saveFile << ";" << cTuple::itemsCountForLevel << ";" << cTuple::readNodesInLevel[i];
////			}
////			else if (i > 0)
////			{
////				saveFile << ";" << cTuple::readNodesInLevel[i];
////			}
////			if (i < 23)
////			{
////				if (cTuple::countCompareLevel[i + 1] == 0)
////				{
////					saveFile << ";" << leafCountItems;
////				}
////			}
////		}
////	}
////
////	saveFile.flush();
////	saveFile.close();
////}
//
//void Quick_Sort_RQ(int start, int end)
//{
//	int i = start;
//	int j = end;
//	if (end - start >= 1)
//	{
//		tKey_FixedLen tmp;
//		tmp.Resize(mSD_FixedLen);
//		qls[(start + end) / 2].CopyTo(tmp, mSD_FixedLen);
//		do
//		{
//			while (qls[i].Compare(tmp, mSD_FixedLen) == -1)
//			{
//				i++;
//			}
//			while (qls[j].Compare(tmp, mSD_FixedLen) == 1)
//			{
//				j--;
//			}
//			if (i <= j)
//			{
//				tKey_FixedLen swap;
//				swap.Resize(mSD_FixedLen);
//				qls[i].CopyTo(swap, mSD_FixedLen);
//				qls[j].CopyTo(qls[i], mSD_FixedLen);
//				swap.CopyTo(qls[j], mSD_FixedLen);
//
//				qhs[i].CopyTo(swap, mSD_FixedLen);
//				qhs[j].CopyTo(qhs[i], mSD_FixedLen);
//				swap.CopyTo(qhs[j], mSD_FixedLen);
//
//				swap.Clear(mSD_FixedLen);
//				i++;
//				j--;
//			}
//		} while (i <= j);
//		tmp.Clear(mSD_FixedLen);
//		if (start < j)
//		{
//			Quick_Sort_RQ(start, j);
//		}
//		if (i < end)
//		{
//			Quick_Sort_RQ(i, end);
//		}
//	}
//}
//
//void Quick_Sort_mKey(int start, int end)
//{
//	int i = start;
//	int j = end;
//	if (end - start >= 1)
//	{
//		tKey_FixedLen tmp;
//		tmp.Resize(mSD_FixedLen);
//		mKey_FixedLen[(start + end) / 2].CopyTo(tmp, mSD_FixedLen);
//		do
//		{
//			while (mKey_FixedLen[i].Compare(tmp, mSD_FixedLen) == -1)
//			{
//				i++;
//			}
//			while (mKey_FixedLen[j].Compare(tmp, mSD_FixedLen) == 1)
//			{
//				j--;
//			}
//			if (i <= j)
//			{
//				tKey_FixedLen swap;
//				swap.Resize(mSD_FixedLen);
//				mKey_FixedLen[i].CopyTo(swap, mSD_FixedLen);
//				mKey_FixedLen[j].CopyTo(mKey_FixedLen[i], mSD_FixedLen);
//				swap.CopyTo(mKey_FixedLen[j], mSD_FixedLen);
//
//				swap.Clear(mSD_FixedLen);
//				i++;
//				j--;
//			}
//		} while (i <= j);
//		tmp.Clear(mSD_FixedLen);
//		if (start < j)
//		{
//			Quick_Sort_mKey(start, j);
//		}
//		if (i < end)
//		{
//			Quick_Sort_mKey(i, end);
//		}
//	}
//}
//
//void printHeader()
//{
//	//printf("---------------------------------------------\n");
//	if (ITEM_TYPE == cDStructConst::TUPLE)
//		printf("Fixed length B-tree test (tuple length/data length: %d/%d)\n", TUPLE_LENGTH, DATA_LENGTH);
//	else
//		printf("Variable length B-tree test (tuple length/data length: %d/%d)\n", TUPLE_LENGTH, DATA_LENGTH);
//
//	switch (DSMODE)
//	{
//	case cDStructConst::DSMODE_DEFAULT: printf("DSMODE: DEFAULT "); break;
//	case cDStructConst::DSMODE_RI: printf("DSMODE: REFERENCE ITEMS "); break;
//	case cDStructConst::DSMODE_CODING: printf("DSMODE: CODING "); break;
//	case cDStructConst::DSMODE_RICODING: printf("DSMODE: REFERENCE ITEMS & CODING "); break;
//	}
//
//	if ((DSMODE == cDStructConst::DSMODE_CODING) || (DSMODE == cDStructConst::DSMODE_RICODING))
//	{
//		printf("/ ");
//		switch (CODETYPE)
//		{
//		case ELIAS_DELTA: printf("CODETYPE: ELIAS_DELTA "); break;
//		case FIBONACCI2: printf("CODETYPE: FIBONACCI2 "); break;
//		case FIBONACCI3: printf("CODETYPE: FIBONACCI3 "); break;
//		case ELIAS_FIBONACCI: printf("CODETYPE: ELIAS_FIBONACCI "); break;
//		case ELIAS_DELTA_FAST: printf("CODETYPE: ELIAS_DELTA_FAST "); break;
//		case FIBONACCI2_FAST: printf("CODETYPE: FIBONACCI2_FAST "); break;
//		case FIBONACCI3_FAST: printf("CODETYPE: FIBONACCI3_FAST "); break;
//		case ELIAS_FIBONACCI_FAST: printf("CODETYPE: ELIAS_FIBONACCI_FAST "); break;
//		case FIXED_LENGTH_CODING: printf("CODETYPE: FIXED_LENGTH_CODING "); break;
//		case FIXED_LENGTH_CODING_ALIGNED: printf("CODETYPE: FIXED_LENGTH_CODING_ALIGNED "); break;
//		}
//	}
//	printf("\n");
//}