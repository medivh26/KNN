#ifndef KNN_H
#define KNN_H

#include <vector> // include the vector library
#include <map> // include the map library
#include <set> // include the set library
#include <algorithm> // include the algorithm library
#include <cstdlib> // include the cstdlib library
#include <ctime> // include the ctime library
#include <cmath> // include the cmath library
#include <iomanip> // include the iomanip library
#include "Point.h" // include the Point class
#include "Graph.h" // include the Graph class

// KNN class
class KNN
{
    friend std::ostream& operator<<(std::ostream& output, const KNN& knn); // friend function to overload the << operator

    // public members of KNN class
    public: 
    KNN(int k = 3); // constructor
    ~KNN(); // destructor

    void createSamplePoints(); // function to create sample points
    void createTestingPoints(); // function to create testing points
    void setK(int k); // function to set the K
    int getK() const; // function to get the K
    std::vector<Point> getSamplePoints() const; // function to get the sample points
    std::vector<Point> getTestingPoints() const; // function to get the testing points
    void showGraph(); // function to show the graph
    void printData(); // function to print the data
    void KNNRun(); // function to run the KNN algorithm
    void classifyPoint(std::vector<Point> a, std::vector<Point> b); // function to classify the points

    // private members of KNN class
    private:
    std::vector<Point> testing_points; // vector to store the testing points
    std::vector<Point> samples; // vector to store the sample points
    int K; // K value
};

#endif
