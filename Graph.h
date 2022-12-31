#ifndef GRAPH_H
#define GRAPH_H
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream> 
#include "KNN.h"
#include "Point.h"
using namespace std;

class Graph
{
    public:
        Graph();
        ~Graph();
        void printGraph(vector<Point>,vector<Point>);
    private:
        void MyFilledCircle(cv::Mat img, cv::Point center, int);
        void MyFilledRectangle(cv::Mat img, cv::Point center, int);
};

#endif
