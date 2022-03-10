#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::duration;


int main(int argc, char const *argv[])
{
    GraphGenerator x;
    x.readEdges("edges1.txt");
    x.readHobbies("hobbies1.txt");
    
    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());
    
    auto t1 = high_resolution_clock::now();
    std::cout << "avg: " << y.FindAverageDegree() << std::endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout<<"avg time: "<<ms_double.count()<<std::endl;


    t1=high_resolution_clock::now();
    std::cout<<"The vertex with the highest degree:"<<std::endl;
    std::cout << y.FindHighestDegree().at(0);
    for(int i = 1; i < y.FindHighestDegree().size();i++){
        std::cout<<", "<< y.FindHighestDegree().at(i);
    }
    std::cout << std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"highest time: "<<ms_double.count()<<std::endl;

    t1=high_resolution_clock::now(); 
    std::cout << "connectednum: " << y.FindConnectedNumber()<< std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"connectednum time: "<<ms_double.count()<<std::endl;


    t1=high_resolution_clock::now(); 
    std::cout << "parameter: "<< std::endl; 


    for(auto x: y.FindConnectedParameters()){
        for(auto y:x){
            // std::cout << y << ", ";
        }
        // std::cout << std::endl;
    }
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"parameter time: "<<ms_double.count()<<std::endl; 

    t1=high_resolution_clock::now(); 
    std::cout << "triangleRatio: "<< y.FindTrianglesRatio() << std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"ratio time: "<<ms_double.count()<<std::endl; 

    t1=high_resolution_clock::now(); 
    std::cout << "ClosestNode: "<< y.FindClosestNode() << std::endl;
    t2=high_resolution_clock::now(); 
    ms_double = t2 - t1; 
    std::cout<<"closestNode time: "<<ms_double.count()<<std::endl; 

    t1=high_resolution_clock::now();  
    std::cout << "HighestInteres: "<< y.FindHighestInterest() << std::endl;
    t2=high_resolution_clock::now(); 
    ms_double = t2 - t1; 
    std::cout<<"HighestInteres time: "<<ms_double.count()<<std::endl; 

    t1=high_resolution_clock::now();  
    std::cout << "pair: "<< y.FindDistanceRatio().first << ", " << y.FindDistanceRatio().second << std::endl;
    t2=high_resolution_clock::now();  
    ms_double = t2 - t1; 
    std::cout<<"pair time: "<<ms_double.count()<<std::endl;  

    return 0;
    
}