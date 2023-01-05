#ifndef POINT_H
#define POINT_H
#include <vector> /// include the vector library

/// Point class
class Point
{
    /// public members of Point class
    public:
    Point(int index, int x, int y); /// constructor
    ~Point(); /// destructor

    /// Setter functions
    void setIndex(int index);
    void setCategoryID(int category);
    void setCoordinates(int x, int y);
    void setDistance(double distance);

    /// Getter functions
    int getIndex() const;
    int getCategoryID() const;
    double getCoordinates(int i) const;
    double getDistance() const;

    /// private members of Point class
    private:
    std::vector<double> coordinates; /// vector to store the coordinates
    int index; /// index of the point
    int catID; /// category ID of the point
    double distance; /// distance of the point from the testing point
};

#endif