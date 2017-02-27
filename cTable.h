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
#include "cTranslatorCreate.h"
#include "cTranslatorIndex.h"


enum TypeOfTable { BTREE = 0,RTREE=1 };
class cTable
{
public:

	

	/*proměnné k  vytvoření stromu*/
	std::vector<cTuple*> v;//prázný vektor který se přetvoří na haldu jako rekace na create table
	cBpTree<cTuple> *mKeyIndex;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mKeyHeader;//prázdná hlavička

	cSpaceDescriptor *keySD;//SD pro klič
	cDataType *keyType;//datovy typ kliče
	cSpaceDescriptor * SD;//SD pro záznamy v tabulce

	/*univerzalni proměnné*/
	std::vector<cColumn*>*columns;
	string tableName;
	
	/*Proměnné k indexu*/
	int indexColumnPosition;
	cBpTree<cTuple> *mIndex;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mIndexHeader;

public:

	cTable();
	bool CreateTable(string query, cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE);
	bool CreateIndex(string query ,cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE);
		cBpTreeHeader<cTuple>*GetHeader();
		cBpTree<cTuple>*GetIndex();
		void SetValues(cTuple *tuple,cSpaceDescriptor *SD);
		cTuple* FindKey(int searchedValue);
		cTuple* FindKey(float searchedValue);

};

cTable::cTable():v(NULL),mKeyIndex(NULL),mKeyHeader(NULL)
{
	
}

inline bool cTable::CreateTable(string query, cQuickDB *quickDB,const unsigned int BLOCK_SIZE,uint DSMODE,unsigned int COMPRESSION_RATIO, unsigned int CODETYPE,unsigned int RUNTIME_MODE,bool HISTOGRAMS, static const uint INMEMCACHE_SIZE)
{
	
	cTranslatorCreate *translator=new cTranslatorCreate();//instance překladače
	
	
	translator->TranlateCreate(query);//překladad cretae table
	
	keySD = translator->keySD;
	keyType = translator->keyType;
	SD = translator->SD;
	columns = translator->columns;
	tableName=translator->tableName;
	
	std:make_heap(v.begin(), v.end());//vytvoření haldy


												//vytváření b-stromu
	mKeyHeader = new cBpTreeHeader<cTuple>(tableName.c_str(), BLOCK_SIZE, keySD, keySD->GetTypeSize(), keySD->GetSize(), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
	mKeyHeader->SetRuntimeMode(RUNTIME_MODE);
	mKeyHeader->SetCodeType(CODETYPE);
	mKeyHeader->SetHistogramEnabled(HISTOGRAMS);
	mKeyHeader->SetInMemCacheSize(INMEMCACHE_SIZE);



	mKeyIndex = new cBpTree<cTuple>();
	if (!mKeyIndex->Create(mKeyHeader, quickDB))
	{
		printf("Key index: creation failed!\n");
		return false;
	}
	else
		return true;
}

inline bool cTable::CreateIndex(string query, cQuickDB * quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, const uint INMEMCACHE_SIZE)
{
	cTranslatorIndex *translator = new cTranslatorIndex();//instance překladače
	translator->TranslateCreateIndex(query);


	cDataType *cType;
	int size;


	if (translator->tableName.compare(tableName) == 0)
	{
		for (int i = 0; i < columns->size(); i++)
		{
			string name = columns->at(i)->name;
			if (name.compare(translator->columnName)==0)
			{
				indexColumnPosition = columns->at(i)->positionInTable;
				cType = columns->at(i)->cType;
				size = columns->at(i)->size;

				i = columns->size();//vyzkočení z foru
			}
		}
	}
	
	cSpaceDescriptor *indexSD = new cSpaceDescriptor(1, new cNTuple(), cType, false);
	cTuple *tuple = new cTuple(indexSD);
	
	
	mIndexHeader = new cBpTreeHeader<cTuple>(tableName.c_str(), BLOCK_SIZE, indexSD, indexSD->GetTypeSize(), indexSD->GetSize(), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
	mIndexHeader->SetRuntimeMode(RUNTIME_MODE);
	mIndexHeader->SetCodeType(CODETYPE);
	mIndexHeader->SetHistogramEnabled(HISTOGRAMS);
	mIndexHeader->SetInMemCacheSize(INMEMCACHE_SIZE);



	mIndex = new cBpTree<cTuple>();
	if (!mKeyIndex->Create(mIndexHeader, quickDB))
	{
		printf("Index: creation failed!\n");
		return false;
	}
	else
		return true;

}

inline cBpTreeHeader<cTuple>* cTable::GetHeader()
{
	return mKeyHeader;
}

inline cBpTree<cTuple>* cTable::GetIndex()
{
	return mKeyIndex;
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
	
	cTuple* keyTuple = new cTuple(keySD);


	if (keyType->GetCode() == 'i')//int
	{
		int key = tuple->GetInt(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}
	else if (keyType->GetCode() == 'u')//uint
	{
		unsigned int key = tuple->GetUInt(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}
	else if (keyType->GetCode() == 'f')
	{
		float key = tuple->GetFloat(0, SD);
		keyTuple->SetValue(0, key, keySD);
	}

	v.push_back(tuple);
	int rowID = v.size();
	keyTuple->SetValue(1, rowID, keySD);



	mKeyIndex->Insert(*keyTuple, keyTuple->GetData());

}

inline cTuple* cTable::FindKey(int searchedValue)
{
	int rowId;
	int nodeCount = mKeyHeader->GetNodeCount();
	int itemCount = mKeyHeader->GetItemCount();
	cTuple *searchedTuple = NULL;
	
	for (int i = 1; i <= nodeCount; i++)
	{
		cBpTreeNode<cTuple> *node = mKeyIndex->ReadLeafNodeR(i);
		int itemCount = node->GetItemCount();

		for (int i = 0; i < itemCount; i++)
		{
			char *itemData = (char*)node->GetCItem(i);
			int itemValue = cCommonNTuple<int>::GetInt(itemData, 0, keySD);
			if (itemValue == searchedValue)
			{
				rowId = cCommonNTuple<int>::GetInt(itemData, 1, keySD);
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
	int nodeCount = mKeyHeader->GetNodeCount();
	int itemCount = mKeyHeader->GetItemCount();
	cTuple *searchedTuple = NULL;

	for (int i = 1; i <= nodeCount; i++)
	{
		cBpTreeNode<cTuple> *node = mKeyIndex->ReadLeafNodeR(i);
		int itemCount = node->GetItemCount();

		for (int i = 0; i < itemCount; i++)
		{
			char *itemData = (char*)node->GetCItem(i);
			float itemValue = cCommonNTuple<float>::GetFloat(itemData, 0, keySD);
			if (itemValue == searchedValue)
			{
				rowId = cCommonNTuple<int>::GetInt(itemData, 1, keySD);
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

