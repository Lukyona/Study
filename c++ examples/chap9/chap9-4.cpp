#include "array.h"

int main()
{  
    Array array(6);
    array.insert(1);
    array.insert(2);
    array.insert(3);
    array.insert(4);
    array.print();

    array.insert(5);
    array.insert(6);

    array.print();
    
    array.insert(7);

    array.print();

    return 0;
}