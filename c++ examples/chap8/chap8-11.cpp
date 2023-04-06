#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void combineArr(int arr1[], int arr2[], int size)
{
    int newArr[size][2];

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j == 0)
            {
                newArr[i][j] = arr1[i];
            }
            else
            {
                newArr[i][j] = arr2[i];
            }
            cout << newArr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    int arr1[5];
    int arr2[5];

    srand(time(0));

    cout << "arr1" << endl;
    for (int i = 0; i < 5; i++)
    {
        arr1[i] = rand() % 100 + 100;
        cout << arr1[i] << " ";
    }
    cout << endl;

    cout << "arr2" << endl;
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = rand() % 100 + 100;
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << endl;

    cout << "combineArr" << endl;
    combineArr(arr1, arr2, 5);

    return 0;
}