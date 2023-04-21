#pragma once
#ifndef SPHERE_H
#define SPHERE_H
#include "Circle.h"

class Sphere
{
private:
    Circle circle;
public:
    Sphere(float r);
    ~Sphere();

    float getSurface();
    float getVolume();
};

#endif