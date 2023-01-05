#ifndef GRAPH_H
#define GRAPH_H

#include <opencv2/core.hpp> /// Basic OpenCV structures (cv::Mat, Scalar)
#include <opencv2/imgproc.hpp> /// Gaussian Blur
#include <opencv2/highgui.hpp> /// OpenCV window I/O
#include <iostream> /// for standard I/O
#include <vector> /// for vectors
#include <algorithm> /// for sorting
#include <sstream>  /// for string streams
#include "KNN.h" /// include the KNN class
#include "Point.h" /// include the Point class

using namespace std; /// standard namespace

/// Graph class
class Graph
{
    /// public members of Graph class
    public:
        Graph(); /// constructor
        ~Graph(); /// destructor
        void printGraph(vector<Point>,vector<Point>); /// function to print the graph
    /// private members of Graph class
    private:
        void MyFilledCircle(cv::Mat img, cv::Point center, int); /// function to draw a circle
        void MyFilledRectangle(cv::Mat img, cv::Point center, int); /// function to draw a rectangle
};

#endif
