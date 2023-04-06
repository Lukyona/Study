#include <iostream>
using namespace std;

void swap(int* pX, int* pY)
{
    int* tmp = pX;
    *pX = *pY;
    *pY = *tmp;
}

int main()
{
    int x = 10;
    int y = 20;

    cout << "스왑 전" << endl;
    cout << "x: " << x << " y: " << y << endl;

    swap(&x, &y);

    cout << "스왑 후" << endl;
    cout << "x: " << x << " y: " << y << endl;

    return 0;
}