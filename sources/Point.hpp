#pragma once

#include <string>

using namespace std;

namespace ariel
{
    class Point
    {
    private:
        double x;
        double y;

    public:
        // constructors
        Point(double x11, double y11);

        // Getters and setters
        double getX();
        double getY();
        void setX(double x11);
        void setY(double y11);

        // functions
        double distance(Point dest);
        Point moveTowards(Point src, Point dest, double distance);
        string print();
    };
}