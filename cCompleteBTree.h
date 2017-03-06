#pragma once
#include "dstruct/paged/b+tree/cB+Tree.h"
class cCompleteBTree
{
public:
	cBpTree<cTuple> *mIndex;//prázdné tělo stromu strom
	cBpTreeHeader<cTuple> *mIndexHeader;
	int indexColumnPosition;

	cCompleteBTree(const char* uniqueName,int position, uint blockSize, cDTDescriptor *dd, uint keySize, uint dataSize,bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB);
	bool SetBTree(const char* uniqueName, uint blockSize, cDTDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB);

};

cCompleteBTree::cCompleteBTree(const char* uniqueName,int position, uint blockSize, cDTDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, static const uint inMemCacheSize, cQuickDB *quickDB)
{
	SetBTree(uniqueName, blockSize, dd, keySize, dataSize, variableLenData, dsMode, treeCode, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize,quickDB);
	indexColumnPosition = position;
}

inline bool cCompleteBTree::SetBTree(const char* uniqueName, uint blockSize, cDTDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB)
{
	mIndexHeader = new cBpTreeHeader<cTuple>(uniqueName, blockSize, dd, keySize, dataSize, variableLenData, dsMode, treeCode, compressionRatio);
	mIndexHeader->SetRuntimeMode(RUNTIME_MODE);
	mIndexHeader->SetCodeType(CODETYPE);
	mIndexHeader->SetHistogramEnabled(HISTOGRAMS);
	mIndexHeader->SetInMemCacheSize(INMEMCACHE_SIZE);
	

	mIndex = new cBpTree<cTuple>();
	if (!mIndex->Create(mIndexHeader, quickDB))
	{
		printf("Key index: creation failed!\n");
		return false;
	}
	else
		return true;
}
