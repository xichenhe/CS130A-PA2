#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
int main(int argc, char const *argv[])
{
    GraphGenerator x;
    x.readEdges("testedges.txt");
    x.readHobbies("testhobbies.txt");
    
    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());
    
    
    std::cout << "avg: " << y.FindAverageDegree() << std::endl;
    
    std::cout << "highest: " << y.FindHighestDegree()<< std::endl;
    std::cout << "connectednum: " << y.FindConnectedNumber()<< std::endl;
    return 0;
    
}