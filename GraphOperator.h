#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include <vector>
#include <utility>
#include <set>

class GraphOperator{
    private:
        int vertices;
        int hobbies;
        int connectedNumber;
        const std::vector< std::vector< std::pair<int,double> > > adjacencyList;
        const std::vector< std::vector<double> > hobbiesList;
        std::vector<int> degrees;
        std::vector< std::set<int> > connected;
        std::vector<double> eccentricities;
        void calculateDegrees();
        void calculateEccentricities();
        void calculateConnected();
    public:
        GraphOperator(int v, int h, std::vector< std::vector< std::pair<int,double> > >* a,std::vector< std::vector<double> >* b );

        double FindAverageDegree();
        int FindHighestDegree();
        int FindConnectedNumber();
        std::vector< std::vector<double> > FindConnectedParameters();

        /*
        FindAverageDegree
        FindHighestDegree
        FindConnectedNumber
        FindConnectedParameters
        FindTrianglesRatio
        FindClosestNode
        FindHighestInterest
        FindDistanceRatio
        */
};

#endif