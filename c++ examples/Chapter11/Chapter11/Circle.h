#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H
#include <iostream>
using namespace std;

class Circle
{
private:
    float radius;
public:
    Circle();
    Circle(float r);
    ~Circle();

    float getPeri();
    float getArea();
    float getRadius();
};

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
    return 2 * 3.14 * radius;
}

float Circle::getArea()
{
    return 3.14 * radius * radius;
}

float Circle::getRadius()
{
    return radius;
}
#endif