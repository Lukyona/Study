#pragma once
#ifndef CYLINDER_H
#define CYLINDER_H
#include "Circle.h"

class Cylinder
{
private:
    float height;
    Circle circle;

public:
    Cylinder(float r, float h);
    ~Cylinder();
    float getSurface();
    float getVolume();
};

#endif