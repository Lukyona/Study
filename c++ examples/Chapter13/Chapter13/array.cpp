#include "array.h"

Array::Array(int s)
    :size(s)
{
    ptr = new double[size];
}

Array::~Array()
{
    delete[] ptr;
}

double& Array::operator[](int index) const
{
    if (index < 0 || index >= size)
    {
        cout << "유효하지 않은 인덱스입니다. 프로그램을 중단합니다.";
        assert(false);
    }
    return ptr[index];
}

double& Array::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        cout << "유효하지 않은 인덱스입니다. 프로그램을 중단합니다.";
        assert(false);
    }
    return ptr[index];
}
