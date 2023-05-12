#pragma once
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
#include <cassert>
using namespace std;

class Array
{
private:
    double* ptr;
    int size;
public:
    Array(int size);
    ~Array();
    double& operator[](int index) const; // 설정자
    double& operator[](int index);       // 접근자
};

#endif // !