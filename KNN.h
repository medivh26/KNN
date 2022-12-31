#ifndef KNN_H
#define KNN_H

#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <iomanip>
#include "Point.h"
#include "Graph.h"

class KNN
{
    friend std::ostream& operator<<(std::ostream& output, const KNN& knn);
    public:
    KNN(int k = 3);
    ~KNN();

    void createSamplePoints();
    void createTestingPoints();
    void setK(int k);
    int getK() const;
    std::vector<Point> getSamplePoints() const;
    std::vector<Point> getTestingPoints() const;
    void showGraph();
    void printData();
    void KNNRun();
    void classifyPoint(std::vector<Point> a, std::vector<Point> b);

    private:
    std::vector<Point> testing_points;
    std::vector<Point> samples;
    int K;
};

#endif
