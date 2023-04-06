#ifndef SORTEDARRAY_H
#define SORTEDARRAY_H
#include <iostream>
using namespace std;

class SortedArray
{
private:
    int capacity; //용적, 배열의 최대 용량
    int size;     //크기, 현재 사용하고 있는 양
    int *arr;

public:
    void insert(int data);
    void print() const;
    void remove(int data);
    SortedArray(int cap);
};
#endif