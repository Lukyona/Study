#include <iostream>
using namespace std;

template <typename T>
void minSelectSort(T* arr, int size)
{
    T min;
    int idx = 0;
    for (int i = 0; i < size; i++)
    {
        min = arr[i];
        idx = i;
        for (int j = i + 1; j < size; j++)
        {
            if (min > arr[j])
            {
                min = arr[j];
                idx = j;
            }
        }
        arr[idx] = arr[i];
        arr[i] = min;
    }

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

    minSelectSort(arr1, 4);
    minSelectSort(arr2, 5);
    minSelectSort(arr3, 4);

    return 0;
}