#include <iostream>
using namespace std;

class Rectangle // Á÷»ç°¢Çü
{
private:
    float length;
    float width;
public:
    Rectangle();
    Rectangle(float l, float w);
    ~Rectangle();

    float getPeri(); // µÑ·¹
    float getArea(); // ³ÐÀÌ
    float getWidth();
};

Rectangle::Rectangle()
    :length(0.0f), width(0.0f)
{}

Rectangle::Rectangle(float l, float w)
    :length(l), width(w)
{}

Rectangle::~Rectangle()
{}

float Rectangle::getPeri()
{
    return (length * 2) + (width * 2);
}

float Rectangle::getArea()
{
    return length * width;
}

float Rectangle::getWidth()
{
    return width;
}

class Cuboid : public Rectangle
{
private:
    float height;
public:
    Cuboid(float l, float w, float h);
    ~Cuboid();

    float getArea(); // °Ñ³ÐÀÌ
    float getVolume(); // ºÎÇÇ
};

Cuboid::Cuboid(float l, float w, float h)
    : height(h)
{
    Rectangle::Rectangle(l, w);
}

Cuboid::~Cuboid()
{}

float Cuboid::getArea()
{
    return (Rectangle::getArea() * 2) + ((Rectangle::getWidth() * height) * 4);
}

float Cuboid::getVolume()
{
    return Rectangle::getArea() * height;
}