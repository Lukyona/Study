#include "triangle.h"

Triangle::Triangle(int first, int second, int third)
: firstSide(first), secondSide(second), thirdSide(third)
{
    if(((firstSide + secondSide) < thirdSide) || ((firstSide + thirdSide) < secondSide) || ((thirdSide + secondSide) < firstSide))
    {
        cout << "프로그램 종료" << endl;
        assert(false);
    }
}

void Triangle::getSides() const
{
    cout << "첫번째 변: " << firstSide << endl;
    cout << "두번째 변: " << secondSide << endl;
    cout << "세번째 변: " << thirdSide << endl;
}

int Triangle::getParameter() const
{
    int parameter = firstSide + secondSide + thirdSide;
    return parameter;
}

int Triangle::getArea(int p) const
{
    p /= 2;
    int area = sqrt((p) * (p - firstSide) * (p - secondSide) * (p - thirdSide));
    return area;
}