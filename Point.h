#ifndef POINT_H
#define POINT_H

#include <vector>

class Point
{
    public:
    Point(int index, int x, int y);
    ~Point();

    void setCategoryID(int category);
    void setCoordinates(int x, int y);
    void setIndex(int index);
    void setDistance(double distance);

    int getCategoryID() const;
    double getCoordinate(int i) const;
    int getIndex() const;
    double getDistance() const;

    private:
    std::vector<double> coordinates;
    int index;
    int category_ID;
    double distance;
};

#endif