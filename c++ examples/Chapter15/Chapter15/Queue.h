#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Queue
{
private:
    int front;
    int rare;
    T* arr;
    int capacity;
    int count = 0;
    
public:
    Queue();
    Queue(int cap);
    ~Queue();

    void enqueue(T elem);
    T dequeue();

    void print();

};

template<typename T>
inline Queue<T>::Queue()
{
}

template<typename T>
inline Queue<T>::Queue(int cap)
    :capacity(cap)
{
    arr = new T[capacity];
    front = 0;
    rare = 0;
}

template<typename T>
inline Queue<T>::~Queue()
{
    delete[] arr;
}

template<typename T>
inline void Queue<T>::enqueue(T elem)
{
    try
    {
        if (count >= capacity)
            throw 1;

        arr[rare] = elem;
        rare++;
        if (rare == capacity)
            rare = 0;

        count++;
    }
    catch (int ex)
    {
        cout << "큐가 가득 차서 더 이상 추가할 수 없습니다." << endl;
        
    }
}

template<typename T>
inline T Queue<T>::dequeue()
{
    T result;

    try
    {
        if (count == 0)
            throw 1;

        result = arr[front];

        T tmp;

        arr[front] = tmp;
        front++;
        if (front == capacity)
            front = 0;

        count--;

    }
    catch (int ex)
    {
        cout << "큐가 비어서 요소를 제거할 수 없습니다." << endl;
        return T();
    }

    return result;

}

template<typename T>
inline void Queue<T>::print()
{
    for (int i = 0; i < capacity; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
