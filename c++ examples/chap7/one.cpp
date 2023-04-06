#include <iostream>
#include "one.h"

One::One(int x1, int y1)
: x(x1), y(y1)
{

}

One::One()
: x(0), y(0)
{

}

One::One(const One& one)
: x(one.x), y(one.y)
{

}

One::~One()
{

}

int One::getX() const
{
    return x;
}

int One::getY() const
{
    return y;
}