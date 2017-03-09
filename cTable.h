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
#include "cCompleteBTree.h"

class cTable
{
public:

	

	/*proměnné k  vytvoření stromu*/
	std::vector<cDataType*> vHeap;//prázný vektor který se přetvoří na haldu jako rekace na create table
	//cBpTree<cTuple> *mKeyIndex;//prázdné tělo stromu strom
	//cBpTreeHeader<cTuple> *mKeyHeader;//prázdná hlavička
	bool varlen;
	bool keyVarlen;

	cSpaceDescriptor *keySD;//SD pro klič
	cSpaceDescriptor *varlenKeySD;
	cDataType *keyType;//datovy typ kliče
	cSpaceDescriptor * SD;//SD pro záznamy v tabulce

	/*univerzalni proměnné*/
	std::vector<cColumn*>*columns;
	string tableName;
	
	/*Proměnné k indexu*/
	std::vector<cCompleteBTree<cTuple>*>*indexesFixLen= new vector<cCompleteBTree<cTuple>*>();;//indexy fixní delky
	std::vector<cCompleteBTree<cNTuple>*>*indexesVarLen = new vector<cCompleteBTree<cNTuple>*>();;//indexy var delky


public:

	cTable();
	bool CreateTable(string query, cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, static const uint inMemCacheSize);
	bool CreateIndex(string query, cQuickDB * quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, const uint inMemCacheSize);
	bool CreateClusteredIndex();

		void SetValues(cTuple *tuple,cSpaceDescriptor *SD);
		void SetValues(cNTuple *tuple, cSpaceDescriptor *SD);
		cTuple* FindKey(string column,int searchedValue);
		cTuple* FindKey(float searchedValue);
		cTuple * TransportItemFixLen(cTuple *sourceTuple, cSpaceDescriptor *mSd, int columnPosition, cDataType *mType);
		cTuple * TransportItemVarLen(cTuple *sourceTuple, cSpaceDescriptor *mSd, cSpaceDescriptor *keySD, int columnPosition, cDataType *mType);
};

cTable::cTable():vHeap(NULL)
{
	
}

inline bool cTable::CreateTable(string query, cQuickDB *quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, static const uint inMemCacheSize)
{
	//bstrom1
	cTranslatorCreate *translator = new cTranslatorCreate();//instance překladače


	translator->TranlateCreate(query);//překladad cretae table

	keySD = translator->keySD;
	keyType = translator->keyType;
	SD = translator->SD;
	columns = translator->columns;
	tableName = translator->tableName;
	//varlen = translator->varlen;//proměnná delka
	keyVarlen = translator->keyVarlen;

	for (int i = 0; i < translator->columns->size(); i++)
	{
		if (columns->at(i)->primaryKey)
		{
			varlenKeySD = columns->at(i)->columnSD;
		}

	
	}



		//cCompleteBTree<cTuple> *index;
	



	if (translator->typeOfCreate == BTREE)
	{
		if (keyVarlen == false)
		{
			cCompleteBTree<cTuple>*index = new cCompleteBTree<cTuple>(tableName.c_str(), translator->keyPosition, BLOCK_SIZE, keySD, keySD->GetTypeSize(), keySD->GetSize(), false, DSMODE, cDStructConst::BTREE, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize, quickDB);

			/*
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
				return true;*/

			if (index != NULL)
			{
				indexesFixLen->push_back(index);

				return true;
			}
		}
		else
		{
			cNTuple tp(keySD, 12);
			unsigned int v1 = tp.GetSize(keySD);
			unsigned int v2 = keySD->GetSize();


			cCompleteBTree<cNTuple>*index = new cCompleteBTree<cNTuple>(tableName.c_str(), translator->keyPosition, BLOCK_SIZE, keySD, tp.GetSize(keySD), keySD->GetSize(), true, DSMODE, cDStructConst::BTREE, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize, quickDB);
//			cCompleteBTree<cNTuple>*index = new cCompleteBTree<cNTuple>(tableName.c_str(), translator->keyPosition, BLOCK_SIZE, keySD, keySD->GetTypeSize(), keySD->GetSize(), true, DSMODE, cDStructConst::BTREE, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize, quickDB);
			if (index != NULL)
			{
				indexesVarLen->push_back(index);
				//indexesFixLen->push_back(index);
				return true;
			}
		
		}

	}
	else return false;
}

inline bool cTable::CreateIndex(string query, cQuickDB * quickDB, const unsigned int BLOCK_SIZE, uint DSMODE, unsigned int compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, const uint inMemCacheSize)
{


	cTranslatorIndex *translator = new cTranslatorIndex();//instance překladače
	translator->TranslateCreateIndex(query);

	//bstrom2

	cDataType *indexType;
	int size;
	int indexColumnPosition;
	string indexName = translator->indexName;
	bool varlenIndex=false;

	cDataType ** ptr;
	ptr = new cDataType*[2];

	cSpaceDescriptor *indexKeySD;


	if (translator->tableName.compare(tableName) == 0)
	{
		bool found=false;
		for (int i = 0; i < columns->size(); i++)
		{
			string name = columns->at(i)->name;
			if (name.compare(translator->columnName) == 0)
			{
				found = true;
				indexColumnPosition = columns->at(i)->positionInTable;
				indexType = columns->at(i)->cType;
				ptr[0] = indexType;//typ proměnné v indexu
				ptr[1] = new cInt();//rowID
				size = columns->at(i)->size;
				if (size != 0)
				{
					varlenIndex = true;//yji3t2n9 jestli je slopec fixlen nebo varlen
					indexKeySD = columns->at(i)->columnSD;
				}
				i = columns->size();//vyzkočení z foru
			}
		}
		if (found == false)
		{
			cout << "table dont exist" << endl;
			exit(0);
		}
	}
	else
	{
		cout << "table dont exist" << endl;
		exit(0);
	}

	cSpaceDescriptor *indexSD = new cSpaceDescriptor(2, new cTuple(), ptr, false);

	if (varlenIndex == false)
	{
		cCompleteBTree<cTuple> *index = new cCompleteBTree<cTuple>(indexName.c_str(), indexColumnPosition, BLOCK_SIZE, indexSD, indexSD->GetTypeSize(), indexSD->GetSize(), false, DSMODE, cDStructConst::BTREE, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize, quickDB);


		if (index != NULL)
		{
			for (int i = 1; i <= vHeap.size(); i++)
			{
				int size = vHeap.size();

				cTuple *heapTuple = (cTuple*)vHeap.at(i - 1);

				cTuple *tuple = TransportItemFixLen(heapTuple, indexSD, indexColumnPosition, indexType);
				tuple->SetValue(1, i - 1, indexSD);


				index->mIndex->Insert(*tuple, tuple->GetData());
			}
			indexesFixLen->push_back(index);
			return true;
		}
		else
		{
			printf("Index: creation failed!\n");
			return false;
		}
	}
	else
	{
		/*cNTuple tp(indexSD, 12);
		unsigned int v1 = tp.GetSize(indexSD);
		unsigned int v2 = indexSD->GetSize();


		cCompleteBTree<cNTuple>*index = new cCompleteBTree<cNTuple>(tableName.c_str(), indexColumnPosition, BLOCK_SIZE, indexSD, tp.GetSize(indexSD), indexSD->GetSize(), true, DSMODE, cDStructConst::BTREE, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize, quickDB);
		//			

		


		if (index != NULL)
		{
			for (int i = 1; i <= vHeap.size(); i++)
			{


				cTuple *heapTuple = (cTuple*)vHeap.at(i - 1);

				cTuple *tuple = TransportItemVarLen(heapTuple, indexSD,indexKeySD, indexColumnPosition, indexType);
				
				tuple->SetValue(1, i - 1, indexKeySD);


				index->mIndex->Insert(*tuple, tuple->GetData());
			}
			indexesVarLen->push_back(index);
			return true;
		}
		else
		{
			printf("Index: creation failed!\n");
			return false;
		}
		*/
		return true;
	}
	
	
	}

inline bool cTable::CreateClusteredIndex()
{
	
	
	
	return false;
}



inline void cTable::SetValues(cTuple *tuple, cSpaceDescriptor *SD)//nastavení hodnopty záznamu a vložení primárního klíče do b-stromu pro primarni kliče
{
	if (keyVarlen)
	{
	/*
		cBpTree<cNTuple> *mKeyIndex = indexesVarLen->at(0)->mIndex;
		
		
		
		
		cNTuple *keyTuple = TransportItemVarLen(tuple, varlenKeySD,keySD, indexesVarLen->at(0)->indexColumnPosition, keyType);

		vHeap.push_back(tuple);
		int rowID = vHeap.size();
		keyTuple->SetValue(1, rowID, keySD);



		mKeyIndex->Insert(*keyTuple, keyTuple->GetData());*/
	}
	else
	{
		cBpTree<cTuple> *mKeyIndex = indexesFixLen->at(0)->mIndex;

		cTuple *keyTuple = TransportItemFixLen(tuple, keySD, indexesFixLen->at(0)->indexColumnPosition, keyType);


		vHeap.push_back(tuple);
		int rowID = vHeap.size();
		keyTuple->SetValue(1, rowID, keySD);



		mKeyIndex->Insert(*keyTuple, keyTuple->GetData());
	}
	

}
/*inline void cTable::SetValues(cNTuple *tuple, cSpaceDescriptor *SD)//nastavení hodnopty záznamu a vložení primárního klíče do b-stromu pro primarni kliče
{
	cBpTree<cNTuple> *mKeyIndex = indexesVarLen->at(0)->mIndex;

	cNTuple *keyTuple = TransportItemVarLen(tuple, keySD, indexesFixLen->at(0)->indexColumnPosition, keyType);


	vHeap.push_back(tuple);
	int rowID = vHeap.size();
	keyTuple->SetValue(1, rowID, keySD);



	mKeyIndex->Insert(*keyTuple, keyTuple->GetData());

}*/




inline cTuple* cTable::FindKey(string column, int searchedValue)
{
	int searchedColumn;
	bool succes=false;

	for (int i = 0; i < columns->size(); i++)
	{
		if (columns->at(i)->name.compare(column) == 0)
		{
			searchedColumn = columns->at(i)->positionInTable;
		}
	}

	cBpTreeHeader<cTuple> *mKeyHeader;
	cBpTree<cTuple> *mKeyIndex;
	
	for (int i = 0; i < indexesFixLen->size(); i++)
	{
		if (indexesFixLen->at(i)->indexColumnPosition == searchedColumn)
		{
			mKeyHeader = indexesFixLen->at(i)->mIndexHeader;
			mKeyIndex = indexesFixLen->at(i)->mIndex;
		}
		
	}
	/*funguje spravně jen pro keyIndex*/
/*
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
				i = itemCount;//vyzkočení z foru
			}
		}
	}
	if (searchedTuple != NULL)
	{
		return searchedTuple;
	}
	else
		return 0;
		*/

	int rowId;
	int nodeCount = mKeyHeader->GetNodeCount();
	int itemCount = mKeyHeader->GetItemCount();
	cTuple *searchedTuple = NULL;

	for (int i = 1; i <= nodeCount; i++)//pruchod všech uzlu
	{
		cBpTreeNode<cTuple> *node = mKeyIndex->ReadLeafNodeR(i);//přečteni jednotlivých uzlu
		int itemCount = node->GetItemCount();

		for (int i = 0; i < itemCount; i++)//pruchod jednotlivych itemu v uzlu
		{
			char *itemData = (char*)node->GetCItem(i);//vytahnuti dat z uzlu
			int itemValue = cCommonNTuple<int>::GetInt(itemData, 0, keySD);//překlad na int
			if (itemValue == searchedValue)
			{
				rowId = cCommonNTuple<int>::GetInt(itemData, 1, keySD);//přirazeni spravne rowID
				searchedTuple = (cTuple*)vHeap.at(rowId - 1);//navraceni celého záznamu ktery odpovida rowID
				i = itemCount;//vyzkočení z foru
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
	cBpTreeHeader<cTuple> *mKeyHeader = indexesFixLen->at(0)->mIndexHeader;
	cBpTree<cTuple> *mKeyIndex = indexesFixLen->at(0)->mIndex;

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
				searchedTuple = (cTuple*)vHeap.at(rowId - 1);
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

inline cTuple * cTable::TransportItemFixLen(cTuple *sourceTuple, cSpaceDescriptor *mSd, int columnPosition, cDataType *mType)
{
	cTuple *destTuple=new cTuple(mSd);
	
	if (mType->GetCode() == 'i')//int
	{
		int key = sourceTuple->GetInt(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'u')//uint
	{
		unsigned int key = sourceTuple->GetUInt(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'f')//float, nepodporovan
	{
		float key = sourceTuple->GetFloat(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'n')//varchar,neodzkoušeno
	{
		cNTuple varcharTuple = sourceTuple->GetTuple(columnPosition, SD);
		destTuple->SetValue(0, *varcharTuple, SD);
	}
	else if (mType->GetCode() == 'c')//char(nejasny Get)
	{
		char key= sourceTuple->GetWChar(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 's')//short
	{
		short key = sourceTuple->GetUShort(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'S')//unsigned short
	{
		unsigned short key = sourceTuple->GetUShort(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	return destTuple;
}
inline cTuple * cTable::TransportItemVarLen(cTuple *sourceTuple, cSpaceDescriptor *mSd,cSpaceDescriptor *keySD, int columnPosition, cDataType *mType)
{
	cNTuple *varlenTuple = new cNTuple(mSd);
	cTuple *destTuple = new cTuple(keySD);

	if (mType->GetCode() == 'i')//int
	{
		int key = sourceTuple->GetInt(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'u')//uint
	{
		unsigned int key = sourceTuple->GetUInt(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'f')//float, nepodporovan
	{
		float key = sourceTuple->GetFloat(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'n')//varchar,neodzkoušeno
	{
		char * TEMPTuple = sourceTuple->GetTuple(sourceTuple->GetData(), columnPosition, SD);
		varlenTuple->SetData(TEMPTuple);
		destTuple->SetValue(0, *varlenTuple, mSd);
		
		///varcharTuple->SetData(TEMPTuple);
		//destTuple->SetValue(0, *varcharTuple, SD);
		//char a=destTuple->GetCChar(0, mSd);

	}
	else if (mType->GetCode() == 'c')//char(nejasny Get)
	{
		char key = sourceTuple->GetWChar(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 's')//short
	{
		short key = sourceTuple->GetUShort(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	else if (mType->GetCode() == 'S')//unsigned short
	{
		unsigned short key = sourceTuple->GetUShort(columnPosition, SD);
		destTuple->SetValue(0, key, mSd);
	}
	return destTuple;
}
