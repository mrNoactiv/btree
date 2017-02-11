#pragma once

#include "dstruct/paged/b+tree/cB+Tree.h"
#include "common/random/cGaussRandomGenerator.h"
#include "common/data/cDataCollection.h"
#include "common/data/cTuplesGenerator.h"
#include "dstruct/paged/core/cBulkLoad.h"
#include "common/datatype/tuple/cCommonNTuple.h"
#include <algorithm>
#include <array>
#include <vector>
#include "cTranslator.h"



enum TypeOfTable { BTREE = 0,RTREE=1 };
class cTable
{
public:
	cTranslator *translator;//instance překladače
	std::vector<cTuple*> v;//prázný vektor který se přetvoří na haldu jako rekace na create table
	cBpTree<cTuple> *mIndex;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mHeader;//prázdná hlavička


public:

		cTable();

};

cTable::cTable():v(NULL),translator(new cTranslator()),mIndex(NULL),mHeader(NULL)
{
	
}
