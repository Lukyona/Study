#include "smallest.h"

Smallest::Smallest()
{
    current = numeric_limits<int>::max();
}

int Smallest::operator()(int next)
{
    if (next < current)
        current = next;
    return current;
}
