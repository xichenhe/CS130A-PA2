#include "GraphGenerator.h"
#include <fstream>
#include <iostream>
void GraphGenerator::readEdges(std::string filename){
    adjacencyList.resize(vertices);
    
    std::ifstream file;
    std::string temp;
    int a,b;
    double weight;
    file.open(filename);
    if(file.is_open()){
        while(getline(file,temp)){
            if(temp==""){
                break;
            }
            //std::cout << temp.substr(0,temp.find(',')) << std::endl;
            a = std::stoi(temp.substr(0,temp.find(',')));
            
            temp.erase(temp.begin(),temp.begin()+1+temp.find(','));

            //std::cout << temp.substr(0,temp.find(',')) << std::endl;
            b = std::stoi(temp.substr(0,temp.find(',')));
            
            temp.erase(temp.begin(),temp.begin()+1+temp.find(','));
            //std::cout << temp << std::endl;
            weight = std::stod(temp);
            AddEdge(a,b,weight);
            /*
            std::cout << "a:" << a 
                    << "\nb:" << b 
                    << "\nc:" << weight << std::endl;
            */

        }
    }

}

void GraphGenerator::AddEdge(int a, int b, double weight){
    adjacencyList[a].push_back(std::pair<int,double>(b,weight));
    adjacencyList[b].push_back(std::pair<int,double>(a,weight));

}


void GraphGenerator::readHobbies(std::string filename){
    hobbiesList.resize(vertices);
    std::ifstream file;
    std::string temp;
    double val;
    int linenum(0);
    file.open(filename);
    if(file.is_open()){
        
        while(getline(file,temp)){
            for(int i = 0; i < hobbies; i++){
                val = std::stod(temp.substr(0,temp.find(',')));
                hobbiesList[linenum].push_back(val);
                //std::cout << "line:" << linenum <<"\nval:" << val << std::endl;
                if(i!=hobbies-1){
                    temp.erase(temp.begin(),temp.begin()+temp.find(',')+1);
                }
            }
            linenum++;
        }
    }

}


/*
int main(int argc, char const *argv[])
{   
    GraphGenerator x;
    x.readHobbies("hobbies.txt");
    return 0;
}*/
