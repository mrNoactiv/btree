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
		bool CreateTable(string query, cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE);
		cBpTreeHeader<cTuple>*GetHeader();
		cBpTree<cTuple>*GetIndex();

};

cTable::cTable():v(NULL),translator(new cTranslator()),mIndex(NULL),mHeader(NULL)
{
	
}

inline bool cTable::CreateTable(string query, cQuickDB *quickDB,const unsigned int BLOCK_SIZE,uint DSMODE,unsigned int COMPRESSION_RATIO, unsigned int CODETYPE,unsigned int RUNTIME_MODE,bool HISTOGRAMS, static const uint INMEMCACHE_SIZE)
{
	
	translator->TranlateCreate(query, translator->GetPosition());//překladad cretae table
	//translator->CreateFixSpaceDescriptor();//vytvoření SD podle nové tabulky

	cSpaceDescriptor *SD=translator->CreateFixSpaceDescriptor();


	std:make_heap(v.begin(), v.end());//vytvoření haldy


												//vytváření b-stromu
	mHeader = new cBpTreeHeader<cTuple>(translator->GetTableName(), BLOCK_SIZE, SD, SD->GetTypeSize(), SD->GetSize(), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
	mHeader->SetRuntimeMode(RUNTIME_MODE);
	mHeader->SetCodeType(CODETYPE);
	mHeader->SetHistogramEnabled(HISTOGRAMS);
	mHeader->SetInMemCacheSize(INMEMCACHE_SIZE);



	mIndex = new cBpTree<cTuple>();
	if (!mIndex->Create(mHeader, quickDB))
	{
		printf("TestCreate: creation failed!\n");
		return true;
	}
	else
		return false;
}

inline cBpTreeHeader<cTuple>* cTable::GetHeader()
{
	return mHeader;
}

inline cBpTree<cTuple>* cTable::GetIndex()
{
	return mIndex;
}
