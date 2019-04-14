CXX = g++
CXXFLAGS = -std=c++0x
CXXFLAGS += -pedantic-errors
CXXFLAGS += -Wall
LDFLAGS = -lboost_date_time
OBJS = main.o ant.o board.o menu.o validateInt.o
SRCS = main.cpp ant.cpp board.cpp menu.cpp validateInt.cpp
HEADERS = menu.hpp ant.hpp board.hpp validateInt.hpp


main: ${OBJS} ${HEADERS}
	${CXX} ${CXXFLAGS} ${OBJS} -o main

${OBJS}:${SRCS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

