#include "Point.h"

Point::Point(int index, int x, int y)
{
    setIndex(index);
    setCoordinates(x, y);
}

Point::~Point()
{
}

void Point::setCategoryID(int category)
{
    category_ID = category;
}

void Point::setCoordinates(int x, int y)
{
    coordinates.push_back(x);
    coordinates.push_back(y);
}

void Point::setIndex(int a)
{
    index = a;
}

void Point::setDistance(double dis)
{
    distance = dis;
}

int Point::getCategoryID() const
{
    return category_ID;
}

double Point::getCoordinate(int i) const
{
    return coordinates[i];
}

int Point::getIndex() const
{
    return index;
}

double Point::getDistance() const
{
    return distance;
}