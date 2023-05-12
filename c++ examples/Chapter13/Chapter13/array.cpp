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
        cout << "��ȿ���� ���� �ε����Դϴ�. ���α׷��� �ߴ��մϴ�.";
        assert(false);
    }
    return ptr[index];
}

double& Array::operator[](int index)
{
    if (index < 0 || index >= size)
    {
        cout << "��ȿ���� ���� �ε����Դϴ�. ���α׷��� �ߴ��մϴ�.";
        assert(false);
    }
    return ptr[index];
}
