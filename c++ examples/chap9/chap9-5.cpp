#include "sortedArray.h"

int main()
{
    SortedArray arr1(6);
    SortedArray arr2(4);

    arr1.insert(1);
    arr1.insert(7);
    arr1.insert(2);
    arr1.insert(5);
    arr1.insert(3);
    arr1.insert(4);
    arr1.insert(9);
    arr1.insert(100);

    arr1.print();

    arr1.remove(100);
    arr1.remove(3);
    arr1.remove(4);
    arr1.print();

    arr2.insert(10);
    arr2.insert(13);
    arr2.insert(11);
    arr2.insert(56);
    arr2.insert(100);
    arr2.print();

    arr2.remove(10);
    arr2.remove(56);
    arr2.remove(1);
    arr2.print();

    return 0;
}