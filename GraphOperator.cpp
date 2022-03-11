#include "GraphOperator.h"
#include <stack>
#include <iostream>
#include <cmath>
#include <climits>
#include <chrono>
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;
using std::chrono::duration_cast;
using std::chrono::duration;

GraphOperator::GraphOperator(int v, int h, 
std::vector< std::vector< std::pair<int,double> > >* a,
std::vector< std::vector<double> >* b ): adjacencyList(*a),hobbiesList(*b)
{
    vertices = v;
    hobbies = h;
    hobby--;
    startNode--;
    auto t1 = high_resolution_clock::now();
    calculateDegrees();
    auto t2 = high_resolution_clock::now();
    calculateConnected();
    auto t3 = high_resolution_clock::now();
    calculateEccentricities();
    auto t4 = high_resolution_clock::now();
    duration<double, std::milli> ms_double1 = t2 - t1;
    duration<double, std::milli> ms_double2 = t3 - t2;
    duration<double, std::milli> ms_double3 = t4 - t3;
    std::cout<<"calculate degree time: "<<ms_double1.count()<<std::endl;
    std::cout << "calculate connected time: "<<ms_double2.count()<<std::endl;
    std::cout << "calculate eccentricity time: "<<ms_double3.count()<<std::endl;
}

//O(V)
void GraphOperator::calculateDegrees(){
    for(auto x: adjacencyList){
        degrees.push_back(x.size());
        //std::cout << x.size() << std::endl;
    }
}

//O(V^2+E)
void GraphOperator::calculateEccentricities(){
    eccentricities.resize(vertices);
    for(auto s: connected){
        /*
        std::vector<int> shouldVisit(vertices,false);
        for(auto element: s){
            shouldVisit[element] = true;
        }
        */
        for(auto element: s){
            //std::cout << "loop: " << element << std::endl;
            std::vector<double> distance(vertices,INT_MAX);
            std::vector<bool> visited(vertices, false);
            distance[element]=0;
            bool finished = false;
            while(!finished){
                double min_val = INT_MAX;
                int min_pos = -1;
                for(auto e: s){
                    if(visited[e]==false && distance[e]<=min_val){
                        min_pos = e;
                        min_val = distance[e];
                    }
                }
                //std::cout << min_pos << std::endl;
                visited[min_pos] = true;
                for(auto x: adjacencyList[min_pos]){
                    if(distance[x.first]>x.second+distance[min_pos]){
                        distance[x.first]=x.second+distance[min_pos];
                        //std::cout << "x" << x.first << ", " << x.second << std::endl;
                    }

                }
                finished = true;
                for(auto e: s){
                    if(visited[e]==false){
                        finished = false;
                        continue;
                    }
                }
                
            }
            
            double max_distance = -1;
            for(auto e: s){
                if(distance[e]>max_distance){
                    max_distance = distance[e];
                }
            }
            //std::cout << "here" << std::endl;
            eccentricities[element]=max_distance;
            //std::cout << "i: " << element << "\neccentricity: " << max_distance << std::endl;
        }
    }

}

//O(V)
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
    int temp = result * 1000;
    if(temp%10>=5){
        temp = (temp+10)/10;
    } 
    else{
        temp = temp/10;
    }
    result = static_cast<double>(temp)/100;
    return result;
}

//O(V)
std::vector<int> GraphOperator::FindHighestDegree(){
    //std::cout << "here" << std::endl;
    std::vector<int> vertices;
    int maxVal = 0;
    int vertex = 0;
    for(size_t i = 0; i < degrees.size(); i++){
        //std::cout << "loop0" << std::endl;
        if(degrees.at(i) > maxVal){
            maxVal = degrees.at(i);
            vertex = i;
            vertices.clear();
            vertices.push_back(i+1);
        }
        else if(degrees.at(i)==maxVal){
            vertices.push_back(i+1);
        }
        
    }
    for(int i = vertices.size()-1;i>0;i--){
        //std::cout << "loop1" << std::endl;
        for(int j = 0; j < i; j++){
            //std::cout << "loop2" << std::endl;
            if(vertices[j]>vertices[j+1]){
                //std::cout << "if" << std::endl;
                std::swap(vertices[j],vertices[j+1]);
            }
        }
    }
    return vertices;
}

//O(V+E)
void GraphOperator::calculateConnected(){
    std::stack<int> s;
    std::vector<bool> visited(vertices,false);
    std::set<int> currentSet;
    int connectednum = 1;
    s.push(0);
    currentSet.insert(0);
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
                currentSet.insert(x.first);
                visited[x.first] = true;
            }
        }

        if(s.empty()){
            connected.push_back(currentSet);
            currentSet.clear();
            for(int i = 0; i < vertices; i++){
                if(visited[i]==false){
                    //allvisited = false;
                    s.push(i);
                    currentSet.insert(i);
                    visited[i]=true;
                    connectednum++;
                    break;
                    
                }
            }

        }


    }
    connectedNumber = connectednum;
}


int GraphOperator::FindConnectedNumber(){
    return connectedNumber;
}

//O(V)
std::vector< std::vector<double> > GraphOperator::FindConnectedParameters(){
    std::vector<double> data;
    std::vector< std::vector<double> > output;
    for(auto s: connected){
        double min = *s.begin();
        double max = *s.begin();
        for(auto x : s){
            // std::cout << "x" << x << std::endl;
            // std::cout << "eccentricity" << eccentricities[x] << std::endl;
            // std::cout << "minval" << min << std::endl;
            if(eccentricities[x]>eccentricities[max]){
                max = x;
            }
            if(eccentricities[x]<eccentricities[min]){
                min = x;
                //std::cout << "entered" << min << std::endl;
            }
        }
        // std::cout << "max" << max << std::endl;
        // std::cout << "min" << min << std::endl;
        int temp = eccentricities[max] * 100;
        if(temp%10>=5){
            temp = (temp+10)/10;
        } 
        else{
        temp = temp/10;
        }
        
        double maxval = static_cast<double>(temp) /10; 
        temp = eccentricities[min] * 100;
        if(temp%10>=5){
            temp = (temp+10)/10;
        }
        else{
        temp = temp/10;
        }
        double minval = static_cast<double>(temp) /10; 
        data.push_back(maxval);
        data.push_back(minval);
        for(auto x: s){
            if(eccentricities[x]==eccentricities[min]){
                data.push_back(x+1);
                
            }
        }
        for( int i = data.size()-1; i > 2; i--){
            for( int j = 2; j < i; j++ ){
                if(data[j]>data[j+1]){
                    std::swap(data[j],data[j+1]);
                }
            }
        }
        /*
        for(auto m : data){
           std::cout << m << ", ";
        }
        std::cout << std::endl;
        */
        output.push_back(data);
        data.clear();
    }
    for( int i = output.size()-1; i > 0; i--){
        for( int j = 0; j < i; j++ ){
            if(output[j][0]>output[j+1][0]){
                std::swap(output[j],output[j+1]);
            }
        }
    }
    return output;
}

//O(V+E)
double GraphOperator::FindTrianglesRatio(){
    int closed = 0;
    int open = 0;
    std::set<int> firstDepth;
    for(auto x : adjacencyList){
        for(auto y : x){
            firstDepth.insert(y.first);
        }
        for(auto m: firstDepth){
            for(auto n : adjacencyList[m]){
                if(firstDepth.find(n.first)!=firstDepth.end()){
                    closed++;
                }
            }
        }
        firstDepth.clear();
    }
    closed = closed/6;
    //std::cout << closed << std::endl;
    int total = 0;
    for(auto x : adjacencyList){
        int n = x.size();
        total += n*(n-1)/2;

    }
    open = total-closed*3;
    //std::cout << open << std::endl;
    int temp = static_cast<double>(open)/closed * 100000;
    if(temp%10>=5){
        temp = (temp+10)/10;
    }
    else{
        temp = temp/10;
    }
    double result = static_cast<double>(temp) / 10000;

    return result;

}

//O(V)
int GraphOperator::FindClosestNode(){
    double min_dis= INT_MAX;
    std::vector<int> possibleAnswers;
    int pos = -1;
    for(size_t i = 0; i < connected.size();i++){
        if(connected[i].find(startNode)!=connected[i].end()){
            pos = i;
            break;
        }
    }
    //std::cout << "pos: " << pos << std::endl;
    if(pos==-1){
        return -1;
    }

    //for(auto element: connected[pos]){
            //std::cout << "loop: " << element << std::endl;
            std::vector<double> distance(vertices,INT_MAX);
            std::vector<bool> visited(vertices, false);
            distance[startNode]=0;
            bool finished = false;
            while(!finished){
                double min_val = INT_MAX;
                int min_pos = -1;
                for(auto e: connected[pos]){
                    if(visited[e]==false && distance[e]<=min_val){
                        min_pos = e;
                        min_val = distance[e];
                    }
                }
                //std::cout << min_pos << std::endl;
                visited[min_pos] = true;
                //std::cout << "min: " <<min_pos << ", "<< distance[min_pos] << std::endl;
                if(hobbiesList[min_pos][hobby]>=threshold){
                    if(distance[min_pos]<=min_dis){
                        min_dis = distance[min_pos];
                        //std::cout << "min: " <<min_pos << ", "<< distance[min_pos] << std::endl;
                    }
                    else{
                        break;
                    }
                    possibleAnswers.push_back(min_pos+1);
                    
                    //std::cout << "hobby: " << hobbiesList[min_pos][hobby] << std::endl;
                    //return min_pos+1;
                }
                for(auto x: adjacencyList[min_pos]){
                    if(distance[x.first]>x.second+distance[min_pos]){
                        distance[x.first]=x.second+distance[min_pos];
                        //std::cout << "x" << x.first << ", " << x.second << std::endl;
                    }

                }
                finished = true;
                for(auto e: connected[pos]){
                    if(visited[e]==false){
                        finished = false;
                        continue;
                    }
                }
                
            }

            

            
            
            //std::cout << "i: " << element << "\neccentricity: " << max_distance << std::endl;
    //}
    for(int i = possibleAnswers.size()-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(possibleAnswers[j]>possibleAnswers[j+1]){
                std::swap(possibleAnswers[j],possibleAnswers[j+1]);
            }
        }
    }

    //std::sort(possibleAnswers.begin(),possibleAnswers.end(),[](int a, int b){return a<b;});
    return possibleAnswers[0];

}

//O(V)
int GraphOperator::FindHighestInterest(){
    double max = -1;
    int pos = - 1;
    for(int i = 0; i < vertices; i++){
        if(hobbiesList[i][hobby]>max){
            max = hobbiesList[i][hobby];
            pos = i;
        }
    }
    return pos+1;
}

//O(V^2)
std::pair<int,int> GraphOperator::FindDistanceRatio(){
    double minRatio = INT_MAX;
    std::pair<int,int> anspair;
    for(auto s: connected){
        /*
        std::vector<int> shouldVisit(vertices,false);
        for(auto element: s){
            shouldVisit[element] = true;
        }
        */
        for(auto element: s){
            //std::cout << "loop: " << element << std::endl;
            std::vector<double> distance(vertices,INT_MAX);
            std::vector<bool> visited(vertices, false);
            distance[element]=0;
            bool finished = false;
            while(!finished){
                double min_val = INT_MAX;
                int min_pos = -1;
                for(auto e: s){
                    if(visited[e]==false && distance[e]<=min_val){
                        min_pos = e;
                        min_val = distance[e];
                    }
                }
                //std::cout << min_pos << std::endl;
                visited[min_pos] = true;
                for(auto x: adjacencyList[min_pos]){
                    if(distance[x.first]>x.second+distance[min_pos]){
                        distance[x.first]=x.second+distance[min_pos];
                        //std::cout << "x" << x.first << ", " << x.second << std::endl;
                    }

                }
                finished = true;
                for(auto e: s){
                    if(visited[e]==false){
                        finished = false;
                        continue;
                    }
                }
                
            }
            double sum = 0;
            double hobbydist = 0;
            
            for(auto y : s){
                double edgedist = distance[y];
                for(int l = 0; l < hobbies; l++){
                    sum += pow(hobbiesList[y][l]-hobbiesList[element][l],2);
                }
                hobbydist = sqrt(sum);
                double ans = hobbydist/edgedist;
                if(ans < minRatio){
                    minRatio = ans;
                    anspair={element+1,y+1};
                }
            }
            
        }
        

    }
    if(anspair.first>anspair.second){
        std::swap(anspair.first,anspair.second);
    }
    return anspair;
}
