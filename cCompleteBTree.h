#pragma once
#include "dstruct/paged/b+tree/cB+Tree.h"

template<class TKey>
class cCompleteBTree
{
public:
	
	cBpTree<TKey> *mIndex;//prázdné tělo stromu strom
	cBpTreeHeader<TKey> *mIndexHeader;
	int indexColumnPosition;

	cCompleteBTree(const char* uniqueName,int position, uint blockSize, cSpaceDescriptor *dd, uint keySize, uint dataSize,bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB);
	bool SetBTree(const char* uniqueName, uint blockSize, cSpaceDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB);

};
template<class TKey>
cCompleteBTree<TKey>::cCompleteBTree(const char* uniqueName,int position, uint blockSize, cSpaceDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int codeType, unsigned int runtimeMode, bool histograms, static const uint inMemCacheSize, cQuickDB *quickDB)
{
	SetBTree(uniqueName, blockSize, dd, keySize, dataSize, variableLenData, dsMode, treeCode, compressionRatio, codeType, runtimeMode, histograms, inMemCacheSize,quickDB);
	indexColumnPosition = position;
}
template<class TKey>
inline bool cCompleteBTree<TKey>::SetBTree(const char* uniqueName, uint blockSize, cSpaceDescriptor *dd, uint keySize, uint dataSize, bool variableLenData, uint dsMode, uint treeCode, uint compressionRatio, unsigned int CODETYPE, unsigned int RUNTIME_MODE, bool HISTOGRAMS, static const uint INMEMCACHE_SIZE, cQuickDB *quickDB)
{
	mIndexHeader = new cBpTreeHeader<TKey>(uniqueName, blockSize, dd, keySize, dataSize, variableLenData, dsMode, treeCode, compressionRatio);
	mIndexHeader->SetRuntimeMode(RUNTIME_MODE);
	mIndexHeader->SetCodeType(CODETYPE);
	mIndexHeader->SetHistogramEnabled(HISTOGRAMS);
	mIndexHeader->SetInMemCacheSize(INMEMCACHE_SIZE);
	

	mIndex = new cBpTree<TKey>();
	if (!mIndex->Create(mIndexHeader, quickDB))
	{
		printf("Key index: creation failed!\n");
		return false;
	}
	else
		return true;
}
