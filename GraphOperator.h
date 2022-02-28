#ifndef GRAPHOPERATOR_H
#define GRAPHOPERATOR_H

#include <vector>
#include <utility>

class GraphOperator{
    private:
        int vertices;
        int hobbies;
        const std::vector< std::vector< std::pair<int,double> > > adjacencyList;
        const std::vector< std::vector<double> > hobbiesList;
        std::vector<int> degrees;
        std::vector<double> eccentricities;
    public:
        GraphOperator(int v, int h, std::vector< std::vector< std::pair<int,double> > >* a,std::vector< std::vector<double> >* b );
        void calculateDegrees();
        void calculateEccentricities();
        double FindAverageDegree();
        int FindHighestDegree();
        int FindConnectedNumber();

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