#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
    GraphGenerator x;
    x.readEdges(argv[1]);
    x.readHobbies(argv[2]);

    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());

    cout<<"The average degree:"<<endl;
    //std::cout << std::fixed << std::showpoint;
    //std::cout << std::setprecision(2);
    cout<<y.FindAverageDegree()<<endl;

    cout<<"The vertex with the highest degree:"<<endl;
    cout << y.FindHighestDegree().at(0);
    for(int i = 1; i < y.FindHighestDegree().size();i++){
        cout<<", "<< y.FindHighestDegree().at(i);
    }
    cout << endl;
    

    cout<<"The number of connected components:"<<endl;
    cout<<y.FindConnectedNumber()<<endl;

    //std::cout << std::setprecision(1);
    cout<<"The diameter, radius, and center(s) of each component:"<<endl;
    for(auto x:y.FindConnectedParameters())
    {
        //std::cout << std::setprecision(1);
        cout << x[0];
        for(int i = 1; i < x.size();i++)
        {
        /*
            if(i==1){
                std::cout << std::setprecision(1);
                cout<<", "<<x[i];
            }
            else{
        */ 
            cout<<", "<<x[i];
            //}
            
        }
        cout<<endl;
    }

    //std::cout << std::setprecision(4);
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
