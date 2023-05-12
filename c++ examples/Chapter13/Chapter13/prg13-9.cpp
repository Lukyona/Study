#include "smallest.h"
#include <iostream>

int main()
{
    Smallest smallest;

    cout << "지금까지 가장 작은 값은 " << smallest(5) << endl;
    cout << "지금까지 가장 작은 값은 " << smallest(9) << endl;
    cout << "지금까지 가장 작은 값은 " << smallest(4) << endl;

    return 0;
}