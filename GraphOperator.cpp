#include "GraphOperator.h"
#include <stack>
#include <iostream>
GraphOperator::GraphOperator(int v, int h, 
std::vector< std::vector< std::pair<int,double> > >* a,
std::vector< std::vector<double> >* b ): adjacencyList(*a),hobbiesList(*b)
{
    vertices = v;
    hobbies = h;
    calculateDegrees();
}

void GraphOperator::calculateDegrees(){
    for(auto x: adjacencyList){
        degrees.push_back(x.size());
        //std::cout << x.size() << std::endl;
    }
}

void GraphOperator::calculateEccentricities(){
    for(int i = 0; i < vertices; i++){
        std::vector<int> distance(vertices,INT_MAX);
        int curr = i;
        for(auto x: adjacencyList[curr]){
            if(distance[x.first]>x.second+
        }
    }
}

void GraphOperator::DFS(){

}

double GraphOperator::FindAverageDegree(){
    int sum = 0;
    for(auto x: degrees){
        sum += x;
        //std::cout << x << std::endl;
    }
    //std::cout << sum << std::endl;
    //std::cout << degrees.size() << std::endl;
    double result = static_cast<double>(sum)/degrees.size();
    //std::cout << result << std::endl;
    return result;
}

int GraphOperator::FindHighestDegree(){
    int maxVal = 0;
    int vertex = 0;
    for(int i = 0; i < degrees.size(); i++){
        if(degrees.at(i) > maxVal){
            maxVal = degrees.at(i);
            vertex = i;
        }
        
    }
    return vertex;
}

int GraphOperator::FindConnectedNumber(){
    std::stack<int> s;
    std::vector<bool> visited(vertices,false);
    int connectednum = 1;
    s.push(0);
    visited[0]=true;
    int curr;
    //bool allvisited;
    while(!s.empty()){
        //allvisited = true;
        curr = s.top();
        s.pop();
        for(auto x: adjacencyList[curr]){
            if(visited[x.first]==false){
                s.push(x.first);
                visited[x.first] = true;
            }
        }

        if(s.empty()){
            for(int i = 0; i < vertices; i++){
                if(visited[i]==false){
                    //allvisited = false;
                    s.push(i);
                    visited[i]=true;
                    connectednum++;
                    break;
                    
                }
            }

        }


    }

    return connectednum;
}