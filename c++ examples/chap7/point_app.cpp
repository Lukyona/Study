#include "point.h"

int main()
{
    Point p1(-3, -5);
    Point p2(9, 1);
    Point p3(5, -5);

    cout << "p1의 좌표는";
    p1.print();
    cout << "p2의 좌표는";
    p2.print();
    cout << "p3의 좌표는";
    p3.print();
    cout << endl;

    cout << "p1은 p2보다";
    p1.position(p2);
    cout << "p2은 p3보다";
    p2.position(p3);
    cout << "p3은 p1보다";
    p3.position(p1);
    cout << endl;

    cout << "p1과 p2의 거리는 " << p1.getDst(p2);
    cout << endl;
    cout << "p1과 p3의 거리는 " << p1.getDst(p3);
    cout << endl;
    cout << "p2과 p3의 거리는 " << p2.getDst(p3);
    cout << endl;

    return 0;
}