#ifndef POINT_H
#define POINT_H
#include <vector> // include the vector library

// Point class
class Point
{
    // public members of Point class
    public:
    Point(int index, int x, int y); // constructor
    ~Point(); // destructor

    // Setter functions
    void setCategoryID(int category);
    void setCoordinates(int x, int y);
    void setIndex(int index);
    void setDistance(double distance);

    // Getter functions
    int getCategoryID() const;
    double getCoordinate(int i) const;
    int getIndex() const;
    double getDistance() const;

    // private members of Point class
    private:
    std::vector<double> coordinates; // vector to store the coordinates
    int index; // index of the point
    int category_ID; // category ID of the point
    double distance; // distance of the point from the testing point
};

#endif