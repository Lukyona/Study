#include "two.h"

Two::Two(int x1, char a1)
: x(x1), a(a1)
{

}

int Two::getX() const
{
    return x;
}

char Two::getA() const
{
    return a;
}

void Two::setX(int v)
{
    x = v;
}

void Two::setA(char v)
{
    a = v;
}