
test: GraphGenerator.o GraphOperator.o test.o
	g++ -std=c++11 -o test test.o GraphGenerator.o GraphOperator.o

main: GraphGenerator.o GraphOperator.o main.o
	g++ -std=c++11 -o PA2 main.o GraphGenerator.o GraphOperator.o

test.o: test.cpp
	g++ -std=c++11 -c test.cpp

main.o: main.cpp
	g++ -std=c++11 -c main.cpp

GraphGenerator.o: GraphGenerator.cpp GraphGenerator.h
	g++ -std=c++11 -c GraphGenerator.cpp GraphGenerator.h

GraphOperator.o: GraphOperator.cpp GraphOperator.h
	g++ -std=c++11 -c GraphOperator.cpp GraphOperator.h

clean: 
	rm -rf *.o PA2 test