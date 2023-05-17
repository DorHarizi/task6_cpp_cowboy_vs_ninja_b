#include "Point.hpp"
#include <cmath>

using namespace ariel;
using namespace std;

Point::Point(double x11, double y11):x(x11), y(y11){}

double Point::getX(){
    return this->x;
}

double Point::getY(){
    return this->y;
}

void Point::setX(double x11){
    this->x = x11;
}

void Point::setY(double y11){
    this->y = y11;
}

double Point::distance(Point dest){
    double xDiff = dest.x - this->x;
    double yDiff = dest.y - this->y;
    double distance = sqrt(xDiff * xDiff + yDiff * yDiff);
    return distance;
}
Point Point::moveTowards(Point src, Point dest, double distance){
    return Point(0, 0);
}

string Point::print(){
    return "(" + to_string(int(this->x)) + "," + to_string(int(this->y)) + ")";
}


