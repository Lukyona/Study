#include "Array.h"
using namespace std;


int main()
{
    Array<int> arr1(6);
    arr1.add(1);
    arr1.add(10);
    arr1.add(5);
    arr1.add(3);
    arr1.add(7);
    arr1.add(8);

    arr1.print();

    Array<double> arr2(3);
    arr2.add(1.4);
    arr2.add(10.0);
    arr2.add(5.3);

    arr2.print();

    Array<char> arr3(4);
    arr3.add('d');
    arr3.add('y');
    arr3.add('g');
    arr3.add('r');

    arr3.print();

    return 0;
}