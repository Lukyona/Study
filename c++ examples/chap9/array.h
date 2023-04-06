#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>
using namespace std;

class Array
{
    private:
        int capacity;//용적, 배열의 최대 용량
        int size;//크기, 현재 사용하고 있는 양
        int* arr;

    public:
        void insert(int data);
        void print() const;
        Array(int cap);

};
#endif