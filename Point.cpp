#include "Point.h" // include the Point class

// Constructor
Point::Point(int index, int x, int y)
{
    setIndex(index);
    setCoordinates(x, y);
}

// Destructor
Point::~Point()
{
}

// Set function that sets the category ID of the point
void Point::setCategoryID(int category)
{
    category_ID = category;
}

// Set function that sets the coordinates of the point
void Point::setCoordinates(int x, int y)
{
    coordinates.push_back(x);
    coordinates.push_back(y);
}

// Set function that sets the index of the point
void Point::setIndex(int a)
{
    index = a;
}
// Set function that sets the distance of the point from the testing point
void Point::setDistance(double dis)
{
    distance = dis;
}

// Get function that returns the category ID of the point
int Point::getCategoryID() const
{
    return category_ID;
}

// Get function that returns the coordinates of the point
double Point::getCoordinate(int i) const
{
    return coordinates[i];
}

// Get function that returns the index of the point
int Point::getIndex() const
{
    return index;
}

// Get function that returns the distance of the point from the testing point
double Point::getDistance() const
{
    return distance;
}