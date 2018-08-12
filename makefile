#/*****************************************************************************
#** Program name: Project 4 - makefile
#** Author: Hassan Alarafat
#** Date: May 27, 2018
#** Description: makefile for the different files of Project 4
#*****************************************************************************/

#name of this assignment, plus the flags that will be used
#g++ to use the compiler g++
#-g to help with debugging later
#-Wall to enable warning messages
#-pedantic to make sure program is warning/error free before compiling
#-std=c++11 for some features including chrono and thread libraries
BIN = final
CXX = g++ -std=c++11
CXXFLAGS = -g -Wall -pedantic

#lists of source files, object files and header files
SRCS = main.cpp Game.cpp menu.cpp validation.cpp Space.cpp Map.cpp Puzzle.cpp Store.cpp Monster.cpp Boss.cpp Character.cpp Protagonist.cpp
OBJS = main.o Game.o menu.o validation.o Space.o Map.o Puzzle.o Store.o Monster.o Boss.o Character.o Protagonist.o
HEADERS = Game.hpp menu.hpp validation.hpp Space.hpp Map.hpp Puzzle.hpp Store.hpp Monster.hpp Boss.hpp Character.hpp Protagonist.hpp

#generates an executable from object
${BIN}: ${OBJS}
	${CXX} ${OBJS} -o ${BIN}


#generates object files from cpp files
${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

#removes object files after compiling, linking and making  program exercutable
clean:
	rm -rf ${OBJS} ${BIN} *.hpp.gch
