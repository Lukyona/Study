#include "point.h"
#include <cmath>

Point::Point(int x1, int y1)
: x(x1), y(y1)
{

}

void Point::print()
{
    cout << "(" << x << ", " << y << ")" << endl;
}

void Point::position(Point p)
{
    if(y < p.y)
    {
        cout << "아래에 있습니다." << endl;
    }
    else if(y > p.y)
    {
        cout << "위에 있습니다." << endl;
    }
    else
    {
        if(x < p.x)
        {
            cout << "왼쪽에 있습니다." << endl;
        }
        if (x > p.x)
        {
            cout << "오른쪽에 있습니다." << endl;
        }
    }
}

int Point::getDst(Point p)
{
    int distance = sqrt(pow((p.x - x), 2) + pow((p.y - y), 2));
    return distance;
}