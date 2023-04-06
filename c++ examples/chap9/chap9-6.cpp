#include "multTable.h"

int main()
{
    MultTable mlt1(4,4);
    MultTable mlt2(6,2);
    MultTable mlt3(10, 8);
    MultTable mlt4(10, 10);
    //MultTable mlt5(13,8);

    mlt1.print();
    mlt2.print();
    mlt3.print();
    mlt4.print();

    return 0;
}