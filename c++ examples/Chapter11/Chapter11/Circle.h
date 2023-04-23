#pragma once
#ifndef CIRCLE_H
#define CIRCLE_H

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

#endif