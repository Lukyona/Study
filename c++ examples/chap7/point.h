#include <iostream>
using namespace std;

#ifndef POINT_H
#define POINT_H

class Point
{
    private:
        int x;
        int y;

    public:
        Point(int x1, int y1);
        void print();
        void position(Point p);
        int getDst(Point p);
};
#endif