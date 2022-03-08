CXX=g++

CXXFLAGS = -std=c++17 -Wall -g

all: PA2

test: GraphGenerator.o GraphOperator.o test.o
	${CXX} ${CXXFLAGS} -o $@ $^

PA2: GraphGenerator.o GraphOperator.o PA2.o
	${CXX} ${CXXFLAGS} -o $@ $^

test.o: test.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

PA2.o: main.cpp
	${CXX} ${CXXFLAGS} -c -o $@ $^

GraphGenerator.o: GraphGenerator.cpp GraphGenerator.h
	${CXX} ${CXXFLAGS} -c -o $@ $^

GraphOperator.o: GraphOperator.cpp GraphOperator.h
	${CXX} ${CXXFLAGS} -c -o $@ $^
clean: 
	rm -rf *.o *.h.gch PA2 test