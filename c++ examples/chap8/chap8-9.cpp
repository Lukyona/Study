#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void combineArr(int arr1[], int arr2[], int size)
{
    int newArr[size*2];
    for(int i = 0, j = 0; i < size * 2; i++)
    {
        if(i % 2 == 0)
        {
            newArr[i] = arr1[j];
        }
        if (i % 2 == 1)
        {
            newArr[i] = arr2[j];
           j++;
        }
        cout << newArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[5];
    int arr2[5];

    srand(time(0));

    for(int i = 0; i < 5; i++)
    {
        arr1[i] = rand() % 100 + 100;
        cout << arr1[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        arr2[i] = rand() % 100 + 100;
        cout << arr2[i] << " ";
    }
    cout << endl;

    combineArr(arr1, arr2, 5);

    return 0;
}