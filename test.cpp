#include "GraphGenerator.h"
#include "GraphOperator.h"
#include <iostream>
#include <chrono>
#include <fstream>

using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::duration;


int main(int argc, char const *argv[])
{   
    GraphGenerator x;
    int vertices = x.getVertices();
    //std::cout<<"type in the number of vertices:";
    //std::cin>>vertices;
    std::ofstream edges;
    edges.open ("edges1.txt");
    for(int i=0;i<vertices-1;i++)
    {
        if(i==vertices-2)
        {
           edges << i+1<<","<<i+2<<","<<0.6;
        }
        else{
            edges << i+1<<","<<i+2<<","<<0.5<<"\n";
        }
        
    }
    edges.close();

    std::ofstream hobbies;
    hobbies.open("hobbies1.txt");
    for(int i=0;i<vertices;i++)
    {
        // if(i==0)
        // {
        //    hobbies << "0.6341,0.10712,0.26737,0.63847,0.13748,0.45337,0.9913,0.8308,0.1927,0.59,0.5507,0.9127,0.8015,0.7327,0.0311,0.9494,0.6349,0.0877,0.0205,0.3";  
        // }
        if(i==vertices-1)
        {
            hobbies << "0.634,0.1071,0.2677,0.6847,0.1748,0.4537,0.9913,0.8308,0.1927,0.59,0.5507,0.9127,0.8015,0.7327,0.0311,0.9494,0.6349,0.0877,0.0205,0.3"; 
        }
        else{
            hobbies << "0.634,0.1071,0.2677,0.6847,0.1748,0.4537,0.9913,0.8308,0.1927,0.59,0.5507,0.9127,0.8015,0.7327,0.0311,0.9494,0.6349,0.0877,0.0205,0.3\n";
        }
    }
    hobbies.close();
    


    // Here is the original part
    
    x.readEdges("edges1.txt");
    x.readHobbies("hobbies1.txt");
    GraphOperator y(x.getVertices(),x.getHobbies(),x.getAdjacencyList(),x.getHobbiesList());


    std::ofstream record;
    record.open("record.txt"); 


    auto t1 = high_resolution_clock::now();
    std::cout << "avg: " << y.FindAverageDegree() << std::endl;
    auto t2 = high_resolution_clock::now();
    duration<double, std::milli> ms_double = t2 - t1;
    std::cout<<"avg time: "<<ms_double.count()<<std::endl;
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now();

    std::cout << "highest: " << y.FindHighestDegree().at(0)<< std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"highest time: "<<ms_double.count()<<std::endl;
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now(); 
    std::cout << "connectednum: " << y.FindConnectedNumber()<< std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"connectednum time: "<<ms_double.count()<<std::endl;
    record<<ms_double.count()<<" ";


    t1=high_resolution_clock::now(); 
    std::cout << "parameter: "<< std::endl; 


    for(auto x: y.FindConnectedParameters()){
        for(auto y:x){
            std::cout << y << ", ";
        }
        std::cout << std::endl;
    }
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"parameter time: "<<ms_double.count()<<std::endl; 
    std::cout<<ms_double.count()<<std::endl;
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now(); 
    std::cout << "triangleRatio: "<< y.FindTrianglesRatio() << std::endl;
    t2=high_resolution_clock::now();
    ms_double = t2 - t1; 
    std::cout<<"ratio time: "<<ms_double.count()<<std::endl; 
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now(); 
    std::cout << "ClosestNode: "<< y.FindClosestNode() << std::endl;
    t2=high_resolution_clock::now(); 
    ms_double = t2 - t1; 
    std::cout<<"closestNode time: "<<ms_double.count()<<std::endl; 
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now();  
    std::cout << "HighestInteres: "<< y.FindHighestInterest() << std::endl;
    t2=high_resolution_clock::now(); 
    ms_double = t2 - t1; 
    std::cout<<"HighestInteres time: "<<ms_double.count()<<std::endl; 
    record<<ms_double.count()<<" ";

    t1=high_resolution_clock::now();  
    std::cout << "pair: "<< y.FindDistanceRatio().first << ", " << y.FindDistanceRatio().second << std::endl;
    t2=high_resolution_clock::now();  
    ms_double = t2 - t1; 
    std::cout<<"pair time: "<<ms_double.count()<<std::endl; 
    record<<ms_double.count()<<"\n"; 
    record.close();



    return 0;
    
}