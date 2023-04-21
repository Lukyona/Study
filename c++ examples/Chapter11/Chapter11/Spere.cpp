#include "Sphere.h"

Sphere::Sphere(float r)
{
    circle = Circle::Circle(r);
}

Sphere::~Sphere()
{}

float Sphere::getSurface()
{
    return 2 * circle.getRadius() * circle.getPeri();
}

float Sphere::getVolume()
{
    return (4 / 3) * circle.getRadius() * circle.getArea();
}