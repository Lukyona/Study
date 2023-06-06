#include "length.h"

length::length(int _n)
    :n(_n)
{
}

ostream& operator<<(ostream& stream, const length& len)
{
    stream.width(len.n);
    return stream;
}
