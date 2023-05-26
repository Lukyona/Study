#include <iostream>
using namespace std;

template <typename T>
int minIndex(T* arr, int size)
{
    T min = arr[0];
    int idx = 0;
    for (int i = 1; i < size; i++)
    {
        if (min > arr[i])
        {
            min = arr[i];
            idx = i;
        }
    }

    return idx;
}


int main()
{
    int arr1[4] = { 3, 0, 2, 1 };
    double arr2[5] = { 0.1, 5.5, 2.0, 100.0, 0.01 };
    char arr3[4] = { 'e', 'q', 'z', 'c'};


    cout << "int�迭�� �ּҰ� �ε����� " << minIndex(arr1, 4) << endl;
    cout << "double�迭�� �ּҰ� �ε����� " << minIndex(arr2, 5) << endl;
    cout << "char�迭�� �ּҰ� �ε����� " << minIndex(arr3, 4) << endl;

    return 0;
}