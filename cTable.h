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


class cTable
{
public:

	

	/*proměnné k  vytvoření stromu*/
	std::vector<cTuple*> vHeap;//prázný vektor který se přetvoří na haldu jako rekace na create table
	cBpTree<cTuple> *mKeyIndex;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mKeyHeader;//prázdná hlavička

	cSpaceDescriptor *keySD;//SD pro klič
	cDataType *keyType;//datovy typ kliče
	cSpaceDescriptor * SD;//SD pro záznamy v tabulce

	/*univerzalni proměnné*/
	std::vector<cColumn*>*columns;
	string tableName;
	
	/*Proměnné k indexu*/
	
	cBpTree<cTuple> *mIndex1;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mIndexHeader1;

public:

	cTable();
	bool CreateTable(string query, cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE);
	bool CreateIndex(string query ,cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE);
		cBpTreeHeader<cTuple>*GetHeader();
		cBpTree<cTuple>*GetIndex();
		void SetValues(cTuple *tuple,cSpaceDescriptor *SD);
		cTuple* FindKey(int searchedValue);
		cTuple* FindKey(float searchedValue);
		cTuple * transportItem(cTuple *sourceTuple, cSpaceDescriptor *mSd, int position, cDataType *mType);

};

cTable::cTable():vHeap(NULL),mKeyIndex(NULL),mKeyHeader(NULL)
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
	
	std:make_heap(vHeap.begin(), vHeap.end());//vytvoření haldy

	if (translator->typeOfCreate == BTREE)
	{
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
	else return true;

}

inline bool cTable::CreateIndex(string query, cQuickDB * quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int COMPRESSION_RATIO, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, const uint INMEMCACHE_SIZE)
{
	cTranslatorIndex *translator = new cTranslatorIndex();//instance překladače
	translator->TranslateCreateIndex(query);


	cDataType *indexType;
	int size;
	int indexColumnPosition;

	if (translator->tableName.compare(tableName) == 0)
	{
		for (int i = 0; i < columns->size(); i++)
		{
			string name = columns->at(i)->name;
			if (name.compare(translator->columnName) == 0)
			{
				indexColumnPosition = columns->at(i)->positionInTable;
				indexType = columns->at(i)->cType;
				size = columns->at(i)->size;

				i = columns->size();//vyzkočení z foru
			}
		}
	}
	else
	{
		cout << "column dont exist" << endl;
		exit(0);
	}
	
	cSpaceDescriptor *indexSD = new cSpaceDescriptor(1, new cTuple(), indexType, false);
	


	mIndexHeader1 = new cBpTreeHeader<cTuple>(tableName.c_str(), BLOCK_SIZE, indexSD, indexSD->GetTypeSize(), indexSD->GetSize(), false, DSMODE, cDStructConst::BTREE, COMPRESSION_RATIO);
	mIndexHeader1->SetRuntimeMode(RUNTIME_MODE);
	mIndexHeader1->SetCodeType(CODETYPE);
	mIndexHeader1->SetHistogramEnabled(HISTOGRAMS);
	mIndexHeader1->SetInMemCacheSize(INMEMCACHE_SIZE);



	mIndex1 = new cBpTree<cTuple>();
	bool succes = mIndex1->Create(mIndexHeader1, quickDB);
	



	if (succes)
	{
		for (int i = 1; i <= vHeap.size(); i++)
		{
			int size = vHeap.size();
			cTuple *heapTuple = vHeap.at(i - 1);


			cTuple *tuple = transportItem(heapTuple, indexSD, indexColumnPosition, indexType);
			mIndex1->Insert(*tuple, tuple->GetData());
		}
		return true;
		
		
	}
	else
	{
		printf("Index: creation failed!\n");
		return false;
		
	}
		


	


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
	cTuple *keyTuple = transportItem(tuple, keySD, 0, keyType);


	vHeap.push_back(tuple);
	int rowID = vHeap.size();
	keyTuple->SetValue(1, rowID, keySD);



	mKeyIndex->Insert(*keyTuple, keyTuple->GetData());
	mKeyIndex->Close();

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
				searchedTuple = vHeap.at(rowId - 1);			
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
				searchedTuple = vHeap.at(rowId - 1);
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

inline cTuple * cTable::transportItem(cTuple *sourceTuple, cSpaceDescriptor *mSd, int position, cDataType *mType)
{
	cTuple *destTuple=new cTuple(mSd);
	
	if (mType->GetCode() == 'i')//int
	{
		int key = sourceTuple->GetInt(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'u')//uint
	{
		unsigned int key = sourceTuple->GetUInt(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'f')//float, nepodporovan
	{
		float key = sourceTuple->GetFloat(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'n')//varchar,neodzkoušeno
	{
		cNTuple varcharTuple = sourceTuple->GetTuple(position, SD);
		destTuple->SetValue(0, *varcharTuple, SD);
	}
	else if (mType->GetCode() == 'c')//char(nejasny Get)
	{
		char key= sourceTuple->GetWChar(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 's')//short
	{
		short key = sourceTuple->GetUShort(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'S')//unsigned short
	{
		unsigned short key = sourceTuple->GetUShort(position, SD);
		destTuple->SetValue(0, key, mSd);
	}
	return destTuple;
}

