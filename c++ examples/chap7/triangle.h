#include <iostream>
#include <cmath>
#include <cassert>
using namespace std;

#ifndef TRIANGLE_H
#define TRIANGLE_H

class Triangle
{
    private:
        int firstSide;
        int secondSide;
        int thirdSide;

    public:
        Triangle(int first, int second, int third);
        void getSides() const;
        int getParameter() const;
        int getArea(int p) const;
};
#endif