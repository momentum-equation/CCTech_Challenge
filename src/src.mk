##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=src
ConfigurationName      :=Debug
WorkspacePath          :=/media/suraj/e/projects/newfolder/CCTech_challenge
ProjectPath            :=/media/suraj/e/projects/newfolder/CCTech_challenge/src
IntermediateDirectory  :=$(ConfigurationName)
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=suraj
Date                   :=01/01/21
CodeLitePath           :=/home/suraj/.codelite
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
ObjectsFileList        :="src.txt"
PCHCompileFlags        :=
MakeDirCommand         :=mkdir -p
LinkOptions            :=  
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=/usr/share/codelite
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/pair.cpp$(ObjectSuffix) $(IntermediateDirectory)/indexList.cpp$(ObjectSuffix) $(IntermediateDirectory)/PrintInterface.cpp$(ObjectSuffix) $(IntermediateDirectory)/Point2DHelper.cpp$(ObjectSuffix) $(IntermediateDirectory)/basicArithmetic.cpp$(ObjectSuffix) $(IntermediateDirectory)/Polygon2D.cpp$(ObjectSuffix) $(IntermediateDirectory)/Point2D.cpp$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild MakeIntermediateDirs
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

MakeIntermediateDirs:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)


$(IntermediateDirectory)/.d:
	@test -d $(ConfigurationName) || $(MakeDirCommand) $(ConfigurationName)

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM main.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) main.cpp

$(IntermediateDirectory)/pair.cpp$(ObjectSuffix): pair.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/pair.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/pair.cpp$(DependSuffix) -MM pair.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/pair.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/pair.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/pair.cpp$(PreprocessSuffix): pair.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/pair.cpp$(PreprocessSuffix) pair.cpp

$(IntermediateDirectory)/indexList.cpp$(ObjectSuffix): indexList.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/indexList.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/indexList.cpp$(DependSuffix) -MM indexList.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/indexList.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/indexList.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/indexList.cpp$(PreprocessSuffix): indexList.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/indexList.cpp$(PreprocessSuffix) indexList.cpp

$(IntermediateDirectory)/PrintInterface.cpp$(ObjectSuffix): PrintInterface.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/PrintInterface.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/PrintInterface.cpp$(DependSuffix) -MM PrintInterface.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/PrintInterface.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/PrintInterface.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/PrintInterface.cpp$(PreprocessSuffix): PrintInterface.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/PrintInterface.cpp$(PreprocessSuffix) PrintInterface.cpp

$(IntermediateDirectory)/Point2DHelper.cpp$(ObjectSuffix): Point2DHelper.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Point2DHelper.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Point2DHelper.cpp$(DependSuffix) -MM Point2DHelper.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/Point2DHelper.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Point2DHelper.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Point2DHelper.cpp$(PreprocessSuffix): Point2DHelper.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Point2DHelper.cpp$(PreprocessSuffix) Point2DHelper.cpp

$(IntermediateDirectory)/basicArithmetic.cpp$(ObjectSuffix): basicArithmetic.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/basicArithmetic.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/basicArithmetic.cpp$(DependSuffix) -MM basicArithmetic.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/basicArithmetic.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/basicArithmetic.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/basicArithmetic.cpp$(PreprocessSuffix): basicArithmetic.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/basicArithmetic.cpp$(PreprocessSuffix) basicArithmetic.cpp

$(IntermediateDirectory)/Polygon2D.cpp$(ObjectSuffix): Polygon2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Polygon2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Polygon2D.cpp$(DependSuffix) -MM Polygon2D.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/Polygon2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Polygon2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Polygon2D.cpp$(PreprocessSuffix): Polygon2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Polygon2D.cpp$(PreprocessSuffix) Polygon2D.cpp

$(IntermediateDirectory)/Point2D.cpp$(ObjectSuffix): Point2D.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Point2D.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Point2D.cpp$(DependSuffix) -MM Point2D.cpp
	$(CXX) $(IncludePCH) $(SourceSwitch) "/media/suraj/e/projects/newfolder/CCTech_challenge/src/Point2D.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Point2D.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Point2D.cpp$(PreprocessSuffix): Point2D.cpp
	$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Point2D.cpp$(PreprocessSuffix) Point2D.cpp


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) -r $(ConfigurationName)/


