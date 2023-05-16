#include "Set.h"
#ifndef SET_H
#define SET_H

#include <iostream>

Set::Set()
    :N(2), count(0)
{
    arr = new int[2];
}

Set::Set(int n)
    :N(n), count(0)
{
    arr = new int[N];
}

Set::~Set()
{
   // delete arr;
}

Set& Set::operator+=(int elem)
{
    for (int i = 0; i < count; i++)
    {
        if (elem == arr[i])
            return *this;
    }
    arr[count] = elem;
    count++;
    return *this;
}

Set& Set::operator-=(int elem)
{
    for (int i = 0; i < count; i++)
    {
        if (elem == arr[i])
        {
            arr[i] = 0;
            count--;
            return *this;
        }
    }
    return *this;
}


void Set::print()
{
    std::cout << "count : " << count << std::endl;
    for (int i = 0; i < count; i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

Set operator*(const Set& first, const Set& second)
{
    int size;
    if (first.count <= second.count) size = first.count;
    else size = second.count;

    Set result(size);

    for (int i = 0; i < first.count; i++)
    {
        for (int j = 0; j < second.count; j++)
        {
            if (first.arr[i] == second.arr[j])
            {
                result += first.arr[i];
            }
        }
    }
    return result;
}

Set operator+(const Set& first, const Set& second)
{
    int size = first.count + second.count;
    Set result(size);

    for (int i = 0; i < first.count; i++)
    {
        result += first.arr[i];
    }

    bool existed = false;
    for (int i = 0; i < second.count; i++)
    {
        existed = false;
        for (int j = 0; j < result.count; j++)
        {
            if (second.arr[i] == result.arr[j])
            {
                existed = true;
                break;
            }
        }
        if (!existed)
        {
            result += second.arr[i];
        }

    }

    return result;
}

Set operator-(const Set& first, const Set& second)
{
    Set result(first.count);
    for (int i = 0; i < first.count; i++)
    {
        result += first.arr[i];
    }

    for (int i = 0; i < first.count; i++)
    {
        for (int j = 0; j < second.count; j++)
        {
            if (result.arr[i] == second.arr[j])
            {
                result.arr[i] = 0;
            }
        }
    }

    return result;
}
#endif // !1