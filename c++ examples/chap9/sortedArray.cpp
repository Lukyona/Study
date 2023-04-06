#include "sortedArray.h"

SortedArray::SortedArray(int cap)
:capacity(cap), size(0)
{
    arr = new int[capacity];
}

void SortedArray::insert(int data)
{
    cout << endl;
    cout << "배열에 " << data << " 을/를 추가하려 한다." << endl;
    if (size == capacity)
    {
        cout << "배열이 꽉 차서 요소를 추가할 수 없다." << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] > data)
            {
                for(int j = size; j > i ; j--)
                {
                    arr[j] = arr[j - 1];                   
                }
                arr[i] = data;
                size++;
                return;
            }        
        }
        arr[size] = data;
        size++;
    }
}

void SortedArray::print() const
{
    cout << endl;
    cout << "현재 배열 상태" << endl;
    cout << "배열 크기" << size << endl;
    cout << "배열 용적" << capacity << endl;

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
}

void SortedArray::remove(int data)
{
    cout << endl;
    cout << "배열에서 " << data << " 을/를 삭제하려 한다." << endl;
    if (size <= 0)
    {
        cout << "배열에 아무 요소도 없다." << endl;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[i] == data)
            {
                for (int j = i; j < size - 1; j++)
                {
                    arr[j] = arr[j + 1];
                }
                arr[size-1] = 0;
                size--;
                cout << "해당 요소를 삭제하였습니다." << endl;
                return;
            }
        }
        cout << "배열에 해당 요소가 존재하지 않습니다." << endl;
    }
}