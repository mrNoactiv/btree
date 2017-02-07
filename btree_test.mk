##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Release
ProjectName            :=btree_test
ConfigurationName      :=Release
WorkspacePath          := "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test"
ProjectPath            := "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test"
IntermediateDirectory  :=./Release
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=kra28
Date                   :=03/31/2014
CodeLitePath           :="/data/home/fei/kra28/.codelite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="/data/home/fei/kra28/workspace_amphora/test/paged/btree_test/btree_test.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  -lrt
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch)../../../ 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -O2 -Wall  -std=c++0x  -DLINUX -mavx -msse4.1 $(Preprocessors)
CFLAGS   :=  -O2 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects=$(IntermediateDirectory)/stream_cFileStream$(ObjectSuffix) $(IntermediateDirectory)/stream_cCharStream$(ObjectSuffix) $(IntermediateDirectory)/compression_cCoderCommon$(ObjectSuffix) $(IntermediateDirectory)/compression_Coder$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(ObjectSuffix) \
	$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(ObjectSuffix) $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(ObjectSuffix) $(IntermediateDirectory)/common_cBitString$(ObjectSuffix) $(IntermediateDirectory)/common_cFastBitArray$(ObjectSuffix) $(IntermediateDirectory)/common_cMemory$(ObjectSuffix) $(IntermediateDirectory)/common_cNumber$(ObjectSuffix) $(IntermediateDirectory)/utils_cCounter$(ObjectSuffix) $(IntermediateDirectory)/utils_cTimer$(ObjectSuffix) $(IntermediateDirectory)/utils_cHistogram$(ObjectSuffix) \
	$(IntermediateDirectory)/random_cGaussRandomGenerator$(ObjectSuffix) $(IntermediateDirectory)/random_cUniformRandomGenerator$(ObjectSuffix) $(IntermediateDirectory)/datatype_cBasicType$(ObjectSuffix) $(IntermediateDirectory)/datatype_cDataType$(ObjectSuffix) $(IntermediateDirectory)/tuple_cLNTuple$(ObjectSuffix) $(IntermediateDirectory)/tuple_cNTuple$(ObjectSuffix) $(IntermediateDirectory)/tuple_cSpaceDescriptor$(ObjectSuffix) $(IntermediateDirectory)/tuple_cTuple$(ObjectSuffix) $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(ObjectSuffix) $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(ObjectSuffix) \
	$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(ObjectSuffix) $(IntermediateDirectory)/memdatstruct_cMemoryManager$(ObjectSuffix) $(IntermediateDirectory)/memorystructures_cArray$(ObjectSuffix) $(IntermediateDirectory)/core_cBucketHeader$(ObjectSuffix) $(IntermediateDirectory)/core_cBucketHeaderStorage$(ObjectSuffix) $(IntermediateDirectory)/core_cCacheStatistics$(ObjectSuffix) $(IntermediateDirectory)/core_cDStructHeader$(ObjectSuffix) $(IntermediateDirectory)/core_cItemStream$(ObjectSuffix) $(IntermediateDirectory)/core_cMemoryPool$(ObjectSuffix) $(IntermediateDirectory)/core_cNode$(ObjectSuffix) \
	$(IntermediateDirectory)/core_cNodeHeader$(ObjectSuffix) $(IntermediateDirectory)/core_cQueryStatistics$(ObjectSuffix) $(IntermediateDirectory)/core_cQuickDB$(ObjectSuffix) $(IntermediateDirectory)/core_cTreeHeader$(ObjectSuffix) $(IntermediateDirectory)/core_cTreeNodeHeader$(ObjectSuffix) $(IntermediateDirectory)/core_cNodeCache$(ObjectSuffix) $(IntermediateDirectory)/rtree_cRangeQueryConfig$(ObjectSuffix) $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(ObjectSuffix) $(IntermediateDirectory)/test$(ObjectSuffix) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects) > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@test -d ./Release || $(MakeDirCommand) ./Release

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/stream_cFileStream$(ObjectSuffix): ../../../common/stream/cFileStream.cpp $(IntermediateDirectory)/stream_cFileStream$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/stream/cFileStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stream_cFileStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stream_cFileStream$(DependSuffix): ../../../common/stream/cFileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stream_cFileStream$(ObjectSuffix) -MF$(IntermediateDirectory)/stream_cFileStream$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/stream/cFileStream.cpp"

$(IntermediateDirectory)/stream_cFileStream$(PreprocessSuffix): ../../../common/stream/cFileStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stream_cFileStream$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/stream/cFileStream.cpp"

$(IntermediateDirectory)/stream_cCharStream$(ObjectSuffix): ../../../common/stream/cCharStream.cpp $(IntermediateDirectory)/stream_cCharStream$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/stream/cCharStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/stream_cCharStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/stream_cCharStream$(DependSuffix): ../../../common/stream/cCharStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/stream_cCharStream$(ObjectSuffix) -MF$(IntermediateDirectory)/stream_cCharStream$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/stream/cCharStream.cpp"

$(IntermediateDirectory)/stream_cCharStream$(PreprocessSuffix): ../../../common/stream/cCharStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/stream_cCharStream$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/stream/cCharStream.cpp"

$(IntermediateDirectory)/compression_cCoderCommon$(ObjectSuffix): ../../../common/compression/cCoderCommon.cpp $(IntermediateDirectory)/compression_cCoderCommon$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cCoderCommon.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cCoderCommon$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cCoderCommon$(DependSuffix): ../../../common/compression/cCoderCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cCoderCommon$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cCoderCommon$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cCoderCommon.cpp"

$(IntermediateDirectory)/compression_cCoderCommon$(PreprocessSuffix): ../../../common/compression/cCoderCommon.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cCoderCommon$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cCoderCommon.cpp"

$(IntermediateDirectory)/compression_Coder$(ObjectSuffix): ../../../common/compression/Coder.cpp $(IntermediateDirectory)/compression_Coder$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/Coder.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_Coder$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_Coder$(DependSuffix): ../../../common/compression/Coder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_Coder$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_Coder$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/Coder.cpp"

$(IntermediateDirectory)/compression_Coder$(PreprocessSuffix): ../../../common/compression/Coder.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_Coder$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/Coder.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(ObjectSuffix): ../../../common/compression/cUniversalCoderEliasDelta.cpp $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasDelta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(DependSuffix): ../../../common/compression/cUniversalCoderEliasDelta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasDelta.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(PreprocessSuffix): ../../../common/compression/cUniversalCoderEliasDelta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasDelta.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(ObjectSuffix): ../../../common/compression/cUniversalCoderEliasFibonacci.cpp $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasFibonacci.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(DependSuffix): ../../../common/compression/cUniversalCoderEliasFibonacci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasFibonacci.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(PreprocessSuffix): ../../../common/compression/cUniversalCoderEliasFibonacci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderEliasFibonacci.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(ObjectSuffix): ../../../common/compression/cUniversalCoderFastEliasDelta.cpp $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasDelta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(DependSuffix): ../../../common/compression/cUniversalCoderFastEliasDelta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasDelta.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFastEliasDelta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasDelta.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(ObjectSuffix): ../../../common/compression/cUniversalCoderFastEliasFibonacci.cpp $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasFibonacci.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(DependSuffix): ../../../common/compression/cUniversalCoderFastEliasFibonacci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasFibonacci.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFastEliasFibonacci.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastEliasFibonacci.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(ObjectSuffix): ../../../common/compression/cUniversalCoderFastFibonacci2.cpp $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(DependSuffix): ../../../common/compression/cUniversalCoderFastFibonacci2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci2.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFastFibonacci2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci2.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(ObjectSuffix): ../../../common/compression/cUniversalCoderFastFibonacci3.cpp $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(DependSuffix): ../../../common/compression/cUniversalCoderFastFibonacci3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci3.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFastFibonacci3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFastFibonacci3.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(ObjectSuffix): ../../../common/compression/cUniversalCoderFibonacci2.cpp $(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci2.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(DependSuffix): ../../../common/compression/cUniversalCoderFibonacci2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci2.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFibonacci2.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci2.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(ObjectSuffix): ../../../common/compression/cUniversalCoderFibonacci3.cpp $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci3.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(DependSuffix): ../../../common/compression/cUniversalCoderFibonacci3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci3.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFibonacci3.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFibonacci3.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(ObjectSuffix): ../../../common/compression/cUniversalCoderFixedLength.cpp $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFixedLength.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(DependSuffix): ../../../common/compression/cUniversalCoderFixedLength.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(ObjectSuffix) -MF$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFixedLength.cpp"

$(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(PreprocessSuffix): ../../../common/compression/cUniversalCoderFixedLength.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/compression/cUniversalCoderFixedLength.cpp"

$(IntermediateDirectory)/common_cBitString$(ObjectSuffix): ../../../common/cBitString.cpp $(IntermediateDirectory)/common_cBitString$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/cBitString.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/common_cBitString$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/common_cBitString$(DependSuffix): ../../../common/cBitString.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/common_cBitString$(ObjectSuffix) -MF$(IntermediateDirectory)/common_cBitString$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/cBitString.cpp"

$(IntermediateDirectory)/common_cBitString$(PreprocessSuffix): ../../../common/cBitString.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/common_cBitString$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/cBitString.cpp"

$(IntermediateDirectory)/common_cFastBitArray$(ObjectSuffix): ../../../common/cFastBitArray.cpp $(IntermediateDirectory)/common_cFastBitArray$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/cFastBitArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/common_cFastBitArray$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/common_cFastBitArray$(DependSuffix): ../../../common/cFastBitArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/common_cFastBitArray$(ObjectSuffix) -MF$(IntermediateDirectory)/common_cFastBitArray$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/cFastBitArray.cpp"

$(IntermediateDirectory)/common_cFastBitArray$(PreprocessSuffix): ../../../common/cFastBitArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/common_cFastBitArray$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/cFastBitArray.cpp"

$(IntermediateDirectory)/common_cMemory$(ObjectSuffix): ../../../common/cMemory.cpp $(IntermediateDirectory)/common_cMemory$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/cMemory.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/common_cMemory$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/common_cMemory$(DependSuffix): ../../../common/cMemory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/common_cMemory$(ObjectSuffix) -MF$(IntermediateDirectory)/common_cMemory$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/cMemory.cpp"

$(IntermediateDirectory)/common_cMemory$(PreprocessSuffix): ../../../common/cMemory.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/common_cMemory$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/cMemory.cpp"

$(IntermediateDirectory)/common_cNumber$(ObjectSuffix): ../../../common/cNumber.cpp $(IntermediateDirectory)/common_cNumber$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/cNumber.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/common_cNumber$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/common_cNumber$(DependSuffix): ../../../common/cNumber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/common_cNumber$(ObjectSuffix) -MF$(IntermediateDirectory)/common_cNumber$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/cNumber.cpp"

$(IntermediateDirectory)/common_cNumber$(PreprocessSuffix): ../../../common/cNumber.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/common_cNumber$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/cNumber.cpp"

$(IntermediateDirectory)/utils_cCounter$(ObjectSuffix): ../../../common/utils/cCounter.cpp $(IntermediateDirectory)/utils_cCounter$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/utils/cCounter.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_cCounter$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_cCounter$(DependSuffix): ../../../common/utils/cCounter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_cCounter$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_cCounter$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/utils/cCounter.cpp"

$(IntermediateDirectory)/utils_cCounter$(PreprocessSuffix): ../../../common/utils/cCounter.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_cCounter$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/utils/cCounter.cpp"

$(IntermediateDirectory)/utils_cTimer$(ObjectSuffix): ../../../common/utils/cTimer.cpp $(IntermediateDirectory)/utils_cTimer$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/utils/cTimer.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_cTimer$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_cTimer$(DependSuffix): ../../../common/utils/cTimer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_cTimer$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_cTimer$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/utils/cTimer.cpp"

$(IntermediateDirectory)/utils_cTimer$(PreprocessSuffix): ../../../common/utils/cTimer.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_cTimer$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/utils/cTimer.cpp"

$(IntermediateDirectory)/utils_cHistogram$(ObjectSuffix): ../../../common/utils/cHistogram.cpp $(IntermediateDirectory)/utils_cHistogram$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/utils/cHistogram.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/utils_cHistogram$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/utils_cHistogram$(DependSuffix): ../../../common/utils/cHistogram.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/utils_cHistogram$(ObjectSuffix) -MF$(IntermediateDirectory)/utils_cHistogram$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/utils/cHistogram.cpp"

$(IntermediateDirectory)/utils_cHistogram$(PreprocessSuffix): ../../../common/utils/cHistogram.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/utils_cHistogram$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/utils/cHistogram.cpp"

$(IntermediateDirectory)/random_cGaussRandomGenerator$(ObjectSuffix): ../../../common/random/cGaussRandomGenerator.cpp $(IntermediateDirectory)/random_cGaussRandomGenerator$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/random/cGaussRandomGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/random_cGaussRandomGenerator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/random_cGaussRandomGenerator$(DependSuffix): ../../../common/random/cGaussRandomGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/random_cGaussRandomGenerator$(ObjectSuffix) -MF$(IntermediateDirectory)/random_cGaussRandomGenerator$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/random/cGaussRandomGenerator.cpp"

$(IntermediateDirectory)/random_cGaussRandomGenerator$(PreprocessSuffix): ../../../common/random/cGaussRandomGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/random_cGaussRandomGenerator$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/random/cGaussRandomGenerator.cpp"

$(IntermediateDirectory)/random_cUniformRandomGenerator$(ObjectSuffix): ../../../common/random/cUniformRandomGenerator.cpp $(IntermediateDirectory)/random_cUniformRandomGenerator$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/random/cUniformRandomGenerator.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/random_cUniformRandomGenerator$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/random_cUniformRandomGenerator$(DependSuffix): ../../../common/random/cUniformRandomGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/random_cUniformRandomGenerator$(ObjectSuffix) -MF$(IntermediateDirectory)/random_cUniformRandomGenerator$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/random/cUniformRandomGenerator.cpp"

$(IntermediateDirectory)/random_cUniformRandomGenerator$(PreprocessSuffix): ../../../common/random/cUniformRandomGenerator.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/random_cUniformRandomGenerator$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/random/cUniformRandomGenerator.cpp"

$(IntermediateDirectory)/datatype_cBasicType$(ObjectSuffix): ../../../common/datatype/cBasicType.cpp $(IntermediateDirectory)/datatype_cBasicType$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/cBasicType.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/datatype_cBasicType$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datatype_cBasicType$(DependSuffix): ../../../common/datatype/cBasicType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/datatype_cBasicType$(ObjectSuffix) -MF$(IntermediateDirectory)/datatype_cBasicType$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/cBasicType.cpp"

$(IntermediateDirectory)/datatype_cBasicType$(PreprocessSuffix): ../../../common/datatype/cBasicType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datatype_cBasicType$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/cBasicType.cpp"

$(IntermediateDirectory)/datatype_cDataType$(ObjectSuffix): ../../../common/datatype/cDataType.cpp $(IntermediateDirectory)/datatype_cDataType$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/cDataType.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/datatype_cDataType$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/datatype_cDataType$(DependSuffix): ../../../common/datatype/cDataType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/datatype_cDataType$(ObjectSuffix) -MF$(IntermediateDirectory)/datatype_cDataType$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/cDataType.cpp"

$(IntermediateDirectory)/datatype_cDataType$(PreprocessSuffix): ../../../common/datatype/cDataType.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/datatype_cDataType$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/cDataType.cpp"

$(IntermediateDirectory)/tuple_cLNTuple$(ObjectSuffix): ../../../common/datatype/tuple/cLNTuple.cpp $(IntermediateDirectory)/tuple_cLNTuple$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cLNTuple.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tuple_cLNTuple$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tuple_cLNTuple$(DependSuffix): ../../../common/datatype/tuple/cLNTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tuple_cLNTuple$(ObjectSuffix) -MF$(IntermediateDirectory)/tuple_cLNTuple$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cLNTuple.cpp"

$(IntermediateDirectory)/tuple_cLNTuple$(PreprocessSuffix): ../../../common/datatype/tuple/cLNTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tuple_cLNTuple$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cLNTuple.cpp"

$(IntermediateDirectory)/tuple_cNTuple$(ObjectSuffix): ../../../common/datatype/tuple/cNTuple.cpp $(IntermediateDirectory)/tuple_cNTuple$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cNTuple.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tuple_cNTuple$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tuple_cNTuple$(DependSuffix): ../../../common/datatype/tuple/cNTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tuple_cNTuple$(ObjectSuffix) -MF$(IntermediateDirectory)/tuple_cNTuple$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cNTuple.cpp"

$(IntermediateDirectory)/tuple_cNTuple$(PreprocessSuffix): ../../../common/datatype/tuple/cNTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tuple_cNTuple$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cNTuple.cpp"

$(IntermediateDirectory)/tuple_cSpaceDescriptor$(ObjectSuffix): ../../../common/datatype/tuple/cSpaceDescriptor.cpp $(IntermediateDirectory)/tuple_cSpaceDescriptor$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cSpaceDescriptor.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tuple_cSpaceDescriptor$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tuple_cSpaceDescriptor$(DependSuffix): ../../../common/datatype/tuple/cSpaceDescriptor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tuple_cSpaceDescriptor$(ObjectSuffix) -MF$(IntermediateDirectory)/tuple_cSpaceDescriptor$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cSpaceDescriptor.cpp"

$(IntermediateDirectory)/tuple_cSpaceDescriptor$(PreprocessSuffix): ../../../common/datatype/tuple/cSpaceDescriptor.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tuple_cSpaceDescriptor$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cSpaceDescriptor.cpp"

$(IntermediateDirectory)/tuple_cTuple$(ObjectSuffix): ../../../common/datatype/tuple/cTuple.cpp $(IntermediateDirectory)/tuple_cTuple$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cTuple.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/tuple_cTuple$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/tuple_cTuple$(DependSuffix): ../../../common/datatype/tuple/cTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/tuple_cTuple$(ObjectSuffix) -MF$(IntermediateDirectory)/tuple_cTuple$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cTuple.cpp"

$(IntermediateDirectory)/tuple_cTuple$(PreprocessSuffix): ../../../common/datatype/tuple/cTuple.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/tuple_cTuple$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/datatype/tuple/cTuple.cpp"

$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(ObjectSuffix): ../../../common/memdatstruct/cBlockLinkedList.cpp $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cBlockLinkedList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(DependSuffix): ../../../common/memdatstruct/cBlockLinkedList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(ObjectSuffix) -MF$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cBlockLinkedList.cpp"

$(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(PreprocessSuffix): ../../../common/memdatstruct/cBlockLinkedList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cBlockLinkedList.cpp"

$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(ObjectSuffix): ../../../common/memdatstruct/cHeapMemoryBlock.cpp $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cHeapMemoryBlock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(DependSuffix): ../../../common/memdatstruct/cHeapMemoryBlock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(ObjectSuffix) -MF$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cHeapMemoryBlock.cpp"

$(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(PreprocessSuffix): ../../../common/memdatstruct/cHeapMemoryBlock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cHeapMemoryBlock.cpp"

$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(ObjectSuffix): ../../../common/memdatstruct/cMemoryBlock.cpp $(IntermediateDirectory)/memdatstruct_cMemoryBlock$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryBlock.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(DependSuffix): ../../../common/memdatstruct/cMemoryBlock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(ObjectSuffix) -MF$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryBlock.cpp"

$(IntermediateDirectory)/memdatstruct_cMemoryBlock$(PreprocessSuffix): ../../../common/memdatstruct/cMemoryBlock.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memdatstruct_cMemoryBlock$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryBlock.cpp"

$(IntermediateDirectory)/memdatstruct_cMemoryManager$(ObjectSuffix): ../../../common/memdatstruct/cMemoryManager.cpp $(IntermediateDirectory)/memdatstruct_cMemoryManager$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryManager.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memdatstruct_cMemoryManager$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memdatstruct_cMemoryManager$(DependSuffix): ../../../common/memdatstruct/cMemoryManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memdatstruct_cMemoryManager$(ObjectSuffix) -MF$(IntermediateDirectory)/memdatstruct_cMemoryManager$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryManager.cpp"

$(IntermediateDirectory)/memdatstruct_cMemoryManager$(PreprocessSuffix): ../../../common/memdatstruct/cMemoryManager.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memdatstruct_cMemoryManager$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/memdatstruct/cMemoryManager.cpp"

$(IntermediateDirectory)/memorystructures_cArray$(ObjectSuffix): ../../../common/memorystructures/cArray.cpp $(IntermediateDirectory)/memorystructures_cArray$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/common/memorystructures/cArray.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/memorystructures_cArray$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/memorystructures_cArray$(DependSuffix): ../../../common/memorystructures/cArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/memorystructures_cArray$(ObjectSuffix) -MF$(IntermediateDirectory)/memorystructures_cArray$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/common/memorystructures/cArray.cpp"

$(IntermediateDirectory)/memorystructures_cArray$(PreprocessSuffix): ../../../common/memorystructures/cArray.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/memorystructures_cArray$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/common/memorystructures/cArray.cpp"

$(IntermediateDirectory)/core_cBucketHeader$(ObjectSuffix): ../../../dstruct/paged/core/cBucketHeader.cpp $(IntermediateDirectory)/core_cBucketHeader$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cBucketHeader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cBucketHeader$(DependSuffix): ../../../dstruct/paged/core/cBucketHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cBucketHeader$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cBucketHeader$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeader.cpp"

$(IntermediateDirectory)/core_cBucketHeader$(PreprocessSuffix): ../../../dstruct/paged/core/cBucketHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cBucketHeader$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeader.cpp"

$(IntermediateDirectory)/core_cBucketHeaderStorage$(ObjectSuffix): ../../../dstruct/paged/core/cBucketHeaderStorage.cpp $(IntermediateDirectory)/core_cBucketHeaderStorage$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeaderStorage.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cBucketHeaderStorage$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cBucketHeaderStorage$(DependSuffix): ../../../dstruct/paged/core/cBucketHeaderStorage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cBucketHeaderStorage$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cBucketHeaderStorage$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeaderStorage.cpp"

$(IntermediateDirectory)/core_cBucketHeaderStorage$(PreprocessSuffix): ../../../dstruct/paged/core/cBucketHeaderStorage.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cBucketHeaderStorage$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cBucketHeaderStorage.cpp"

$(IntermediateDirectory)/core_cCacheStatistics$(ObjectSuffix): ../../../dstruct/paged/core/cCacheStatistics.cpp $(IntermediateDirectory)/core_cCacheStatistics$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cCacheStatistics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cCacheStatistics$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cCacheStatistics$(DependSuffix): ../../../dstruct/paged/core/cCacheStatistics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cCacheStatistics$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cCacheStatistics$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cCacheStatistics.cpp"

$(IntermediateDirectory)/core_cCacheStatistics$(PreprocessSuffix): ../../../dstruct/paged/core/cCacheStatistics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cCacheStatistics$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cCacheStatistics.cpp"

$(IntermediateDirectory)/core_cDStructHeader$(ObjectSuffix): ../../../dstruct/paged/core/cDStructHeader.cpp $(IntermediateDirectory)/core_cDStructHeader$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cDStructHeader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cDStructHeader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cDStructHeader$(DependSuffix): ../../../dstruct/paged/core/cDStructHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cDStructHeader$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cDStructHeader$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cDStructHeader.cpp"

$(IntermediateDirectory)/core_cDStructHeader$(PreprocessSuffix): ../../../dstruct/paged/core/cDStructHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cDStructHeader$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cDStructHeader.cpp"

$(IntermediateDirectory)/core_cItemStream$(ObjectSuffix): ../../../dstruct/paged/core/cItemStream.cpp $(IntermediateDirectory)/core_cItemStream$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cItemStream.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cItemStream$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cItemStream$(DependSuffix): ../../../dstruct/paged/core/cItemStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cItemStream$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cItemStream$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cItemStream.cpp"

$(IntermediateDirectory)/core_cItemStream$(PreprocessSuffix): ../../../dstruct/paged/core/cItemStream.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cItemStream$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cItemStream.cpp"

$(IntermediateDirectory)/core_cMemoryPool$(ObjectSuffix): ../../../dstruct/paged/core/cMemoryPool.cpp $(IntermediateDirectory)/core_cMemoryPool$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cMemoryPool.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cMemoryPool$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cMemoryPool$(DependSuffix): ../../../dstruct/paged/core/cMemoryPool.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cMemoryPool$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cMemoryPool$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cMemoryPool.cpp"

$(IntermediateDirectory)/core_cMemoryPool$(PreprocessSuffix): ../../../dstruct/paged/core/cMemoryPool.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cMemoryPool$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cMemoryPool.cpp"

$(IntermediateDirectory)/core_cNode$(ObjectSuffix): ../../../dstruct/paged/core/cNode.cpp $(IntermediateDirectory)/core_cNode$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNode.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cNode$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cNode$(DependSuffix): ../../../dstruct/paged/core/cNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cNode$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cNode$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNode.cpp"

$(IntermediateDirectory)/core_cNode$(PreprocessSuffix): ../../../dstruct/paged/core/cNode.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cNode$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNode.cpp"

$(IntermediateDirectory)/core_cNodeHeader$(ObjectSuffix): ../../../dstruct/paged/core/cNodeHeader.cpp $(IntermediateDirectory)/core_cNodeHeader$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeHeader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cNodeHeader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cNodeHeader$(DependSuffix): ../../../dstruct/paged/core/cNodeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cNodeHeader$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cNodeHeader$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeHeader.cpp"

$(IntermediateDirectory)/core_cNodeHeader$(PreprocessSuffix): ../../../dstruct/paged/core/cNodeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cNodeHeader$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeHeader.cpp"

$(IntermediateDirectory)/core_cQueryStatistics$(ObjectSuffix): ../../../dstruct/paged/core/cQueryStatistics.cpp $(IntermediateDirectory)/core_cQueryStatistics$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQueryStatistics.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cQueryStatistics$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cQueryStatistics$(DependSuffix): ../../../dstruct/paged/core/cQueryStatistics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cQueryStatistics$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cQueryStatistics$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQueryStatistics.cpp"

$(IntermediateDirectory)/core_cQueryStatistics$(PreprocessSuffix): ../../../dstruct/paged/core/cQueryStatistics.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cQueryStatistics$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQueryStatistics.cpp"

$(IntermediateDirectory)/core_cQuickDB$(ObjectSuffix): ../../../dstruct/paged/core/cQuickDB.cpp $(IntermediateDirectory)/core_cQuickDB$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQuickDB.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cQuickDB$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cQuickDB$(DependSuffix): ../../../dstruct/paged/core/cQuickDB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cQuickDB$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cQuickDB$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQuickDB.cpp"

$(IntermediateDirectory)/core_cQuickDB$(PreprocessSuffix): ../../../dstruct/paged/core/cQuickDB.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cQuickDB$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cQuickDB.cpp"

$(IntermediateDirectory)/core_cTreeHeader$(ObjectSuffix): ../../../dstruct/paged/core/cTreeHeader.cpp $(IntermediateDirectory)/core_cTreeHeader$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeHeader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cTreeHeader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cTreeHeader$(DependSuffix): ../../../dstruct/paged/core/cTreeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cTreeHeader$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cTreeHeader$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeHeader.cpp"

$(IntermediateDirectory)/core_cTreeHeader$(PreprocessSuffix): ../../../dstruct/paged/core/cTreeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cTreeHeader$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeHeader.cpp"

$(IntermediateDirectory)/core_cTreeNodeHeader$(ObjectSuffix): ../../../dstruct/paged/core/cTreeNodeHeader.cpp $(IntermediateDirectory)/core_cTreeNodeHeader$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeNodeHeader.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cTreeNodeHeader$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cTreeNodeHeader$(DependSuffix): ../../../dstruct/paged/core/cTreeNodeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cTreeNodeHeader$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cTreeNodeHeader$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeNodeHeader.cpp"

$(IntermediateDirectory)/core_cTreeNodeHeader$(PreprocessSuffix): ../../../dstruct/paged/core/cTreeNodeHeader.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cTreeNodeHeader$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cTreeNodeHeader.cpp"

$(IntermediateDirectory)/core_cNodeCache$(ObjectSuffix): ../../../dstruct/paged/core/cNodeCache.cpp $(IntermediateDirectory)/core_cNodeCache$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeCache.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/core_cNodeCache$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/core_cNodeCache$(DependSuffix): ../../../dstruct/paged/core/cNodeCache.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/core_cNodeCache$(ObjectSuffix) -MF$(IntermediateDirectory)/core_cNodeCache$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeCache.cpp"

$(IntermediateDirectory)/core_cNodeCache$(PreprocessSuffix): ../../../dstruct/paged/core/cNodeCache.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/core_cNodeCache$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/core/cNodeCache.cpp"

$(IntermediateDirectory)/rtree_cRangeQueryConfig$(ObjectSuffix): ../../../dstruct/paged/rtree/cRangeQueryConfig.cpp $(IntermediateDirectory)/rtree_cRangeQueryConfig$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/rtree/cRangeQueryConfig.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/rtree_cRangeQueryConfig$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/rtree_cRangeQueryConfig$(DependSuffix): ../../../dstruct/paged/rtree/cRangeQueryConfig.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/rtree_cRangeQueryConfig$(ObjectSuffix) -MF$(IntermediateDirectory)/rtree_cRangeQueryConfig$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/rtree/cRangeQueryConfig.cpp"

$(IntermediateDirectory)/rtree_cRangeQueryConfig$(PreprocessSuffix): ../../../dstruct/paged/rtree/cRangeQueryConfig.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/rtree_cRangeQueryConfig$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/rtree/cRangeQueryConfig.cpp"

$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(ObjectSuffix): ../../../dstruct/paged/queryprocessing/cQueryProcStat.cpp $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/queryprocessing/cQueryProcStat.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(DependSuffix): ../../../dstruct/paged/queryprocessing/cQueryProcStat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(ObjectSuffix) -MF$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/dstruct/paged/queryprocessing/cQueryProcStat.cpp"

$(IntermediateDirectory)/queryprocessing_cQueryProcStat$(PreprocessSuffix): ../../../dstruct/paged/queryprocessing/cQueryProcStat.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/dstruct/paged/queryprocessing/cQueryProcStat.cpp"

$(IntermediateDirectory)/test$(ObjectSuffix): test.cpp $(IntermediateDirectory)/test$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test/test.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/test$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/test$(DependSuffix): test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/test$(ObjectSuffix) -MF$(IntermediateDirectory)/test$(DependSuffix) -MM "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test/test.cpp"

$(IntermediateDirectory)/test$(PreprocessSuffix): test.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/test$(PreprocessSuffix) "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test/test.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/stream_cFileStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stream_cFileStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stream_cFileStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/stream_cCharStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/stream_cCharStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/stream_cCharStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cCoderCommon$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cCoderCommon$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cCoderCommon$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_Coder$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_Coder$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_Coder$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasDelta$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderEliasFibonacci$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasDelta$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastEliasFibonacci$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci2$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFastFibonacci3$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci2$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFibonacci3$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(DependSuffix)
	$(RM) $(IntermediateDirectory)/compression_cUniversalCoderFixedLength$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/common_cBitString$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/common_cBitString$(DependSuffix)
	$(RM) $(IntermediateDirectory)/common_cBitString$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/common_cFastBitArray$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/common_cFastBitArray$(DependSuffix)
	$(RM) $(IntermediateDirectory)/common_cFastBitArray$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/common_cMemory$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/common_cMemory$(DependSuffix)
	$(RM) $(IntermediateDirectory)/common_cMemory$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/common_cNumber$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/common_cNumber$(DependSuffix)
	$(RM) $(IntermediateDirectory)/common_cNumber$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils_cCounter$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils_cCounter$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils_cCounter$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils_cTimer$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils_cTimer$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils_cTimer$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/utils_cHistogram$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/utils_cHistogram$(DependSuffix)
	$(RM) $(IntermediateDirectory)/utils_cHistogram$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/random_cGaussRandomGenerator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/random_cGaussRandomGenerator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/random_cGaussRandomGenerator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/random_cUniformRandomGenerator$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/random_cUniformRandomGenerator$(DependSuffix)
	$(RM) $(IntermediateDirectory)/random_cUniformRandomGenerator$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cBasicType$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cBasicType$(DependSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cBasicType$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cDataType$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cDataType$(DependSuffix)
	$(RM) $(IntermediateDirectory)/datatype_cDataType$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cLNTuple$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cLNTuple$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cLNTuple$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cNTuple$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cNTuple$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cNTuple$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cSpaceDescriptor$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cSpaceDescriptor$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cSpaceDescriptor$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cTuple$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cTuple$(DependSuffix)
	$(RM) $(IntermediateDirectory)/tuple_cTuple$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(DependSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cBlockLinkedList$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(DependSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cHeapMemoryBlock$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryBlock$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryBlock$(DependSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryBlock$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryManager$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryManager$(DependSuffix)
	$(RM) $(IntermediateDirectory)/memdatstruct_cMemoryManager$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/memorystructures_cArray$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/memorystructures_cArray$(DependSuffix)
	$(RM) $(IntermediateDirectory)/memorystructures_cArray$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeaderStorage$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeaderStorage$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cBucketHeaderStorage$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cCacheStatistics$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cCacheStatistics$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cCacheStatistics$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cDStructHeader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cDStructHeader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cDStructHeader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cItemStream$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cItemStream$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cItemStream$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cMemoryPool$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cMemoryPool$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cMemoryPool$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cNode$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cNode$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cNode$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeHeader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeHeader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeHeader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cQueryStatistics$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cQueryStatistics$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cQueryStatistics$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cQuickDB$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cQuickDB$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cQuickDB$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeHeader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeHeader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeHeader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeNodeHeader$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeNodeHeader$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cTreeNodeHeader$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeCache$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeCache$(DependSuffix)
	$(RM) $(IntermediateDirectory)/core_cNodeCache$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/rtree_cRangeQueryConfig$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/rtree_cRangeQueryConfig$(DependSuffix)
	$(RM) $(IntermediateDirectory)/rtree_cRangeQueryConfig$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(DependSuffix)
	$(RM) $(IntermediateDirectory)/queryprocessing_cQueryProcStat$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/test$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/test$(DependSuffix)
	$(RM) $(IntermediateDirectory)/test$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) "/data/home/fei/kra28/workspace_amphora/test/paged/btree_test/.build-release/btree_test"


