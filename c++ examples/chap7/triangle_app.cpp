#include "triangle.h"

int main()
{
    Triangle tri(3,4,5);

    tri.getSides();
    cout << "삼각형의 둘레는 " << tri.getParameter() << endl;
    cout << "삼각형의 넓이는 " << tri.getArea(tri.getParameter()) << endl;

    return 0;
}