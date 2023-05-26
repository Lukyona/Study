#include <iostream>
using namespace std;

template <typename T>
void swap(T* arr, int idx1, int idx2)
{
    T tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;    
}

template <typename T>
void reverse(T* arr, int size)
{
    for (int i = 0, j = size - 1; i < (size / 2); i++, j--)
    {
        swap(arr, i, j);
    }
}

template <typename T>
void print(T* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[4] = { 3, 0, 2, 1 };
    double arr2[5] = { 0.1, 5.5, 2.0, 100.0, 0.01 };
    char arr3[4] = { 'e', 'q', 'z', 'c' };
    string arr4[3] = { "hello", "fuck", "you"};

    reverse(arr1, 4);
    reverse(arr2, 5);
    reverse(arr3, 4);
    reverse(arr4, 3);

    cout << "int배열 뒤집기 ";
    print(arr1, 4);
    cout << "double배열 뒤집기 ";
    print(arr2, 5);
    cout << "char배열 뒤집기 ";
    print(arr3, 4);
    cout << "string배열 뒤집기 ";
    print(arr4, 3);

    return 0;
}