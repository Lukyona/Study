#include "array.h"

Array::Array(int cap)
:capacity(cap), size(0)
{
    arr = new int[capacity];
}

void Array::insert(int data)
{
    if(size == capacity)
    {
        cout << endl;
        cout << "배열이 꽉 차서 요소를 추가할 수 없다." << endl;
    }
    else
    {
        arr[size] = data;
        size++;
    }
}

void Array::print() const
{
    cout << endl;
    cout << "현재 배열 상태" << endl;
    cout << "배열 크기" << size << endl;
    cout << "배열 용적" << capacity << endl;

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}