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
		void SetValues(cTuple *tuple,cSpaceDescriptor *SD);
		cTuple* FindKey(int searchedValue);
		cTuple* FindKey(float searchedValue);

};

cTable::cTable():v(NULL),translator(new cTranslator()),mIndex(NULL),mHeader(NULL)
{
	
}

inline bool cTable::CreateTable(string query, cQuickDB *quickDB,const unsigned int BLOCK_SIZE,uint DSMODE,unsigned int COMPRESSION_RATIO, unsigned int CODETYPE,unsigned int RUNTIME_MODE,bool HISTOGRAMS, static const uint INMEMCACHE_SIZE)
{
	
	translator->TranlateCreate(query, translator->GetPosition());//překladad cretae table
	
	cSpaceDescriptor *keySD = translator->CreateKeySpaceDescriptor();
	
	std:make_heap(v.begin(), v.end());//vytvoření haldy


												//vytváření b-stromu
	mHeader = new cBpTreeHeader<cTuple>(translator->GetTableName(), BLOCK_SIZE, keySD, keySD->GetTypeSize(), keySD->GetSize(), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
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

inline void cTable::SetValues(cTuple *tuple, cSpaceDescriptor *SD)
{


	/*
	char *rowID = new char();

	 Možnost narvat row id do inseru jako data(asi blbost)
	std::string s = std::to_string(v.size());

	char const *pchar = s.c_str();
	rowID = (char*)pchar;
	*/
	cSpaceDescriptor *keySD = translator->keySD;
	cTuple* keyTuple = new cTuple(keySD);


	if (translator->keyType->GetCode() == 'i')//int
	{
		int key = tuple->GetInt(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}
	else if (translator->keyType->GetCode() == 'u')//uint
	{
		unsigned int key = tuple->GetUInt(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}
	else if (translator->keyType->GetCode() == 'f')
	{
		float key = tuple->GetFloat(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}

	v.push_back(tuple);
	int rowID = v.size();
	keyTuple->SetValue(1, rowID, keySD);



	mIndex->Insert(*keyTuple, keyTuple->GetData());

}

inline cTuple* cTable::FindKey(int searchedValue)
{
	int rowId;
	int nodeCount = mHeader->GetNodeCount();
	int itemCount = mHeader->GetItemCount();
	cTuple *searchedTuple = NULL;
	
	for (int i = 1; i <= nodeCount; i++)
	{
		cBpTreeNode<cTuple> *node = mIndex->ReadLeafNodeR(i);
		int itemCount = node->GetItemCount();

		for (int i = 0; i < itemCount; i++)
		{
			char *itemData = (char*)node->GetCItem(i);
			int itemValue = cCommonNTuple<int>::GetInt(itemData, 0, translator->keySD);
			if (itemValue == searchedValue)
			{
				rowId = cCommonNTuple<int>::GetInt(itemData, 1, translator->keySD);
				searchedTuple = v.at(rowId - 1);			
			}
		}
	}
	if (searchedTuple != NULL)
	{
		return searchedTuple;
	}
	else
		return 0;


}

inline cTuple * cTable::FindKey(float searchedValue)
{
	
	int rowId;
	int nodeCount = mHeader->GetNodeCount();
	int itemCount = mHeader->GetItemCount();
	cTuple *searchedTuple = NULL;

	for (int i = 1; i <= nodeCount; i++)
	{
		cBpTreeNode<cTuple> *node = mIndex->ReadLeafNodeR(i);
		int itemCount = node->GetItemCount();

		for (int i = 0; i < itemCount; i++)
		{
			char *itemData = (char*)node->GetCItem(i);
			float itemValue = cCommonNTuple<float>::GetFloat(itemData, 0, translator->keySD);
			if (itemValue == searchedValue)
			{
				rowId = cCommonNTuple<int>::GetInt(itemData, 1, translator->keySD);
				searchedTuple = v.at(rowId - 1);
			}
		}
	}
	if (searchedTuple != NULL)
	{
		return searchedTuple;
	}
	else
		return 0;
}

