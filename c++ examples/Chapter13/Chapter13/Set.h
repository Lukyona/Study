#pragma once
class Set
{
private:
    int N;
    int* arr;
    int count;
public:
    Set();
    Set(int n);
    ~Set();

    Set& operator +=(int elem);
    Set& operator -=(int elem);
    void print();

    friend Set operator *(const Set& first, const Set& second);
    friend Set operator +(const Set& first, const Set& second);
    friend Set operator -(const Set& first, const Set& second);
};

