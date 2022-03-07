#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    GraphGenerator x;
    x.readEdges("testedges.txt");
    x.readHobbies("testhobbies.txt");

    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());

    cout<<"The average degree:"<<endl;
    cout<<y.FindAverageDegree()<<endl;

    cout<<"The vertex with the highest degree:"<<endl;
    cout<<y.FindHighestDegree()<<endl;

    cout<<"The number of connected components:"<<endl;
    cout<<y.FindConnectedNumber()<<endl;

    
    


    return 0;
}
