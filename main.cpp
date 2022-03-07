#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    GraphGenerator x;
    x.readEdges("edges.txt");
    x.readHobbies("hobbies.txt");

    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());

    cout<<"The average degree:"<<endl;
    cout<<y.FindAverageDegree()<<endl;

    cout<<"The vertex with the highest degree:"<<endl;
    cout<<y.FindHighestDegree()<<endl;

    cout<<"The number of connected components:"<<endl;
    cout<<y.FindConnectedNumber()<<endl;

    cout<<"The diameter, radius, and center(s) of each component:"<<endl;
    for(auto x:y.FindConnectedParameters())
    {
        for(auto y:x)
        {
            cout<<y<<",";
        }
        cout<<endl;
    }

    cout<<"The ratio between the number of open and closed triangles:"<<endl;
    cout<<y.FindTrianglesRatio()<<endl;

    cout<<"The closest node:"<<endl;
    cout<<y.FindClosestNode()<<endl;

    cout<<"A closest with the highest interest:"<<endl;
    cout<<y.FindHighestInterest()<<endl;

    cout<<"The pair of nodes x and y:"<<endl;
    cout<<y.FindDistanceRatio().first<<","<<y.FindDistanceRatio().second<<endl;

    return 0;
}
