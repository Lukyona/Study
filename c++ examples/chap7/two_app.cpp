#include "two.h"

int main()
{
    Two two(3, 'r');
    cout << "x의 값: " << two.getX() << ", " << "a의 값: " << two.getA() << endl;

    two.setX(6);
    two.setA('s');

    cout << "변경된 x의 값: " << two.getX() << ", " << "변경된 a의 값: " << two.getA() << endl;
    return 0;
}