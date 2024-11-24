#! ------------------ change this only ------------------
fileDirectory := project/header_guard_example/ex3_main.cpp

executableName      := buildwithmakefile
executableExtension := .exe

sourceFileName      := mycustomsrcfile
sourceFileExtension := .cpp

CXX           := g++
optimizeFlags := # -O2
warningFlags  := -Wall -Wextra -Wpedantic
debugFlags    := # -g
#! ------------------------------------------------------

BIN     := bin/
SRC     := src/
INCLUDE := include/

cleanall:
	rm ${BIN}*.exe

#! require fileDirectory executableName executableExtension
single:
	${CXX} ${optimizeFlags} ${warningFlags} -fdiagnostics-color=always ${debugFlags} ${fileDirectory} -o ${BIN}${executableName}${executableExtension}

#! require fileDirectory executableName executableExtension sourceFileName sourceFileExtension
multiple:
	${CXX} ${optimizeFlags} ${warningFlags} -fdiagnostics-color=always ${debugFlags} ${fileDirectory} ${SRC}${sourceFileName}${sourceFileExtension} -I${INCLUDE} -o ${BIN}${executableName}${executableExtension}

clean:
	rm ${BIN}${executableName}${executableExtension}
