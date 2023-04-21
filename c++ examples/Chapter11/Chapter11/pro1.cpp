#include <iostream>
using namespace std;

class Square // Á¤»ç°¢Çü
{
private:
    float side;
public:
    Square();
    Square(float s);
    ~Square();

    float getPeri(); // µÑ·¹
    float getArea(); // ³ĞÀÌ
    float getSide();
};

Square::Square()
    :side(0.0f)
{}

Square::Square(float s)
    :side(s)
{}

Square::~Square()
{}

float Square::getPeri()
{
    return 4 * side;
}

float Square::getArea()
{
    return side * side;
}

float Square::getSide()
{
    return side;
}

class Cube : public Square
{
public:
    Cube();
    Cube(float s);
    ~Cube();

    float getArea(); // °Ñ³ĞÀÌ
    float getVolume(); // ºÎÇÇ
};

Cube::Cube()
{
    Square();
}

Cube::Cube(float s)
{
    Square(s);
}

Cube::~Cube()
{}

float Cube::getArea()
{
    return Square::getArea() * 6;
}

float Cube::getVolume()
{
    return Square::getArea() * Square::getSide();
}