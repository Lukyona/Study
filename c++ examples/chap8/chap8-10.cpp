#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void combineArr(int arr1[], int arr2[], int size)
{
    int newArr[2][size];
    
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < size; j++)
        {
            if(i == 0)
            {
                newArr[i][j] = arr1[j];
            }
            else
            {
                newArr[i][j] = arr2[j];
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