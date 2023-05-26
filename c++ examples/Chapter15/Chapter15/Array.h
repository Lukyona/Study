#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Array
{
private:
    int capacity;
    T* arr;
    int count = 0;

public:
    Array(int cap);
    ~Array();

    void add(T elem);
    void print();
};

template<typename T>
inline Array<T>::Array(int cap)
    :capacity(cap)
{
    arr = new T[capacity];
}

template<typename T>
inline Array<T>::~Array()
{
    delete[] arr;
}

template<typename T>
inline void Array<T>::add(T elem)
{
    arr[count] = elem;
    count++;
}

template<typename T>
inline void Array<T>::print()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
