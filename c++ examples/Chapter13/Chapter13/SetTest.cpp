#include "Set.h"

int main()
{
    Set set1(5);
    Set set2(6);

    set1 += 1;
    set1 += 2;
    set1 += 5;
    set1 += 5;
    set1 += 4;
    set1 += 3;
    set2 += 9;
    set2 += 6;
    set2 += 3;
    set2 += 1;
    set2 += 11;
    set2 += 10;
    set1.print();
    set2.print();

    (set1 + set2).print();
    (set1 * set2).print();

    (set1 - set2).print();

    (set2 - set1).print();


    return 0;
}