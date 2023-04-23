#include "Circle.h"


Circle::Circle()
    :radius(0.0f)
{}

Circle::Circle(float r)
    :radius(r)
{
}

Circle::~Circle()
{}

float Circle::getPeri()
{
    return 2 * 3.14f * radius;
}

float Circle::getArea()
{
    return 3.14f * radius * radius;
}

float Circle::getRadius()
{
    return radius;
}