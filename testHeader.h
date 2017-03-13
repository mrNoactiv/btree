#include "dstruct/paged/b+tree/cB+Tree.h"
#include "common/random/cGaussRandomGenerator.h"
#include "common/data/cDataCollection.h"
#include "common/data/cTuplesGenerator.h"
#include "dstruct/paged/core/cBulkLoad.h"
#include "common/datatype/tuple/cCommonNTuple.h"
#include <algorithm>
#include <array>
#include <vector>

using namespace common::random;
using namespace common::data;

const unsigned int ITEM_COUNT = 2000000;
const unsigned int DOMAIN_MAX = ITEM_COUNT;    //  Maximum value for random generator in cTuplesGenerator.

const unsigned int CACHE_SIZE = 20000;
const unsigned int BLOCK_SIZE = /* 2048; */ 8192;
const unsigned int MAX_NODE_INMEM_SIZE = 1.25 * BLOCK_SIZE;//edit z 1.25 na 1.5

														   // defines the length of the inserting tuples
const unsigned int TUPLE_LENGTHS[] = { 5 };

// defines the length of the inserting data
const unsigned int DATA_LENGTHS[] = { 5 };

// defines the type of data structure mode
const unsigned int DSMODES[] = { cDStructConst::DSMODE_DEFAULT, cDStructConst::DSMODE_CODING,cDStructConst::DSMODE_RI, cDStructConst::DSMODE_RICODING };
//const unsigned int DSMODES[] = { cDStructConst::DSMODE_RI };

// defines type of tuple
const unsigned int ITEM_TYPES[] = { cDStructConst::TUPLE, cDStructConst::NTUPLE };
//const unsigned int ITEM_TYPES[] = { cDStructConst::TUPLE };

// defines the type of coding in the case of CODING and RICODING
unsigned int CODETYPE = FIXED_LENGTH_CODING_ALIGNED;
// ELIAS_DELTA 1		FIBONACCI2 2		FIBONACCI3  3		ELIAS_FIBONACCI 4
// ELIAS_DELTA_FAST 5	FIBONACCI2_FAST 6	FIBONACCI3_FAST 7	ELIAS_FIBONACCI_FAST 8
// FIXED_LENGTH_CODING 9	FIXED_LENGTH_CODING_ALIGNED 10

// defines maximal compression ratio in RI, CODING and RICODING mode
unsigned int COMPRESSION_RATIO = 2;

unsigned int MULTIPLERANGEQUERY = false;
unsigned int QUERIES_IN_MULTIQUERY = 4; // number of queries in multiquery

unsigned int RUNTIME_MODE = cDStructConst::RTMODE_DEFAULT; // defines the mode (with or without validation) RTMODE_DEFAULT		RTMODE_VALIDATION

														   // Histograms for each dimension will be created during build
bool HISTOGRAMS = false;

static const uint START_SEED = 865915;					// defines the starting seed of data generator
static const uint INMEMCACHE_SIZE = 0; // 1048576;

char dbPath[1024] = "quickdb";

typedef cNTuple tKey_VarLen;
typedef cTuple tKey_FixedLen;

typedef cTuple TKey;
typedef cBpTree<TKey> BpTree;

typedef cUInt tDomain; // defines domain used for loading tuples from collection file.

typedef cBulkLoad<BpTree, cBpTreeNode<TKey>, cBpTreeNode<TKey>, TKey, cBpTreeHeader<TKey>, tDomain> tBulkload;

uint DSMODE, ITEM_TYPE, TUPLE_LENGTH, DATA_LENGTH;

cTuplesGenerator<tDomain, tKey_VarLen>* generator_VarLen;

cTuplesGenerator<tDomain, tKey_FixedLen>* generator_FixedLen;
cTuplesGenerator<tDomain, TKey>* tuples_generatorCheck;


//cSpaceDescriptor<cUInt, cInt> sD; generika


char *mData_FixedLen;


tKey_FixedLen *mAuxTuple1;
tKey_FixedLen *mAuxTuple2;

/// specification of collections ///
int COLLECTION = cCollection::RANDOM;
int COMPUTER = Computer::DBEDU;
char *collectionFile, *queryFile;
uint nofDeletedItems, nofNotFoundItems;


void printHeader();
void InitializeTuplesGenerator(uint type);
void CloseTuplesGenerator(uint type);

void Create_VariableLen(bool variableData);
bool Open_VariableLen();

void Create_FixedLen();
bool Open_FixedLen();

void Bulkloading_FixedLen();

void checkItem_variablelen(cBpTree<tKey_VarLen> *index, unsigned int j);
bool checkItem_fixedlen(cBpTree<tKey_FixedLen> *index, unsigned int j);

uint DSMODES_COUNT() { return sizeof(DSMODES) / sizeof(uint); };
uint ITEM_TYPES_COUNT() { return sizeof(ITEM_TYPES) / sizeof(uint); };
uint TUPLE_LENGTHS_COUNT() { return sizeof(TUPLE_LENGTHS) / sizeof(uint); };
uint DATA_LENGTHS_COUNT() { return sizeof(DATA_LENGTHS) / sizeof(uint); };
