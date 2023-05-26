#include <iostream>
using namespace std;

template <typename T>
int search(T* arr, int size, T val)
{
    for (int i = 0; i < size; i++)
    {
        if(val == arr[i])
            return i;
    }

    return -1;
}


int main()
{
    int arr1[4] = { 3, 0, 2, 1 };
    double arr2[5] = { 0.1, 5.5, 2.0, 100.0, 0.01 };
    char arr3[4] = { 'e', 'q', 'z', 'c' };


    cout << "int�迭�� ��� 2�� �ε����� " << search(arr1, 4, 2) << endl;
    cout << "char�迭�� ��� 'b'�� �ε����� " << search(arr3, 4, 'b') << endl;

    return 0;
}