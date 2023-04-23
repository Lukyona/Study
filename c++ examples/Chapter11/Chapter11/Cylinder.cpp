#include "Cylinder.h"
#include "Circle.h"
using namespace std;

Cylinder::Cylinder(float r, float h)
    : height(h)
{
    circle = Circle::Circle(r);
}

Cylinder::~Cylinder()
{
}

float Cylinder::getSurface()
{
    return (height * circle.getPeri()) + circle.getArea();
}

float Cylinder::getVolume()
{
    return height * circle.getArea();
}
