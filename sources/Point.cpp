#include "Point.hpp"
#include <stdexcept>
#include <cmath>
#include <vector>

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
    if(distance == -1){
        throw invalid_argument("Distance can't be zero\n");
    }
    if(distance >= src.distance(dest))
        return Point{dest.getX(), dest.getY()};
    double x1, x2, y1, y2;
    vector<double> arr;
    arr.resize(3);
    double m = ((dest.getY() - src.getY()) / (dest.getX() - src.getX()));
    // factor x^2
    arr[0] = (m * m) + 1;
    //factor x
    arr[1] = (2 * -src.getX()) + (2 * m * (m * -src.getX()));
    //num
    arr[2] = (src.getX() * src.getX()) + (m * -src.getX() * m * -src.getX()) - (distance * distance);
    if((arr[0] == 0) || ((arr[1] * arr[1] -4*(arr[0] * arr[2])) < 0)){
        throw runtime_error("Distance can't be zero or there is no solution to the equation\n");
    }
    x1 = (-arr[1] + sqrt((arr[1] * arr[1]) -4*(arr[0] * arr[2]))) / (2 * arr[0]);
    x2 = (-arr[1] - sqrt((arr[1] * arr[1]) -4*(arr[0] * arr[2]))) / (2 * arr[0]);
    y1 = m * (x1) + (m * -src.getX() + src.getY());
    y2 = m * (x2) + (m * -src.getX() + src.getY());
    Point p1 = Point(x1, y1);
    Point p2 = Point(x2, y2);
    double distanceX1 = dest.distance(p1);
    double distanceX2 = dest.distance(p2);
    arr.clear();
    return distanceX1 < distanceX2 ? p1 : p2;
}

string Point::print(){
    return "(" + to_string(this->x) + "," + to_string(this->y) + ")";
}



