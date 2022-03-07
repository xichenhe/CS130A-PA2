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
    std::cout << "parameter: "<< std::endl;
    
    for(auto x: y.FindConnectedParameters()){
        for(auto y:x){
            std::cout << y << ", ";
        }
        std::cout << std::endl;
    }
    
    std::cout << "triangleRatio: "<< y.FindTrianglesRatio() << std::endl;
    std::cout << "ClosestNode: "<< y.FindClosestNode() << std::endl;
    std::cout << "HighestInteres: "<< y.FindHighestInterest() << std::endl;
    std::cout << "pair: "<< y.FindDistanceRatio().first << ", " << y.FindDistanceRatio().second << std::endl;
    
    return 0;
    
}