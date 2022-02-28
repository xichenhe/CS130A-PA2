#ifndef GRAPHGENERATOR_H
#define GRAPHGENERATOR_H

#include <vector>
#include <utility>
#include <string>
class GraphGenerator{
    private:
        int vertices = 5;
        int hobbies = 20;
        std::vector< std::vector< std::pair<int,double> > > adjacencyList;
        std::vector< std::vector<double> > hobbiesList;
    public:
        void readEdges(std::string filename);
        void readHobbies(std::string filename);
        void AddEdge(int a, int b, double weight);
        std::vector< std::vector< std::pair<int,double> > >* getAdjacencyList(){
            return &adjacencyList;
        };

        std::vector< std::vector<double> >* getHobbiesList(){
            return &hobbiesList;
        };
        int getVertices(){
            return vertices;
        };
        int getHobbies(){
            return hobbies;
        };
    


};

#endif