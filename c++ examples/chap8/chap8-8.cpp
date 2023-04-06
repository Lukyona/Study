#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void rightToLeft(int arr[][6])
{
    int newArr[6];
    for (int i = 0, j = 5; i < 6; i++, j--)
    {
        newArr[i] = arr[i][j];
        cout << newArr[i] << " ";
    }
    cout << endl;
}

void leftToRight(int arr[][6])
{
    int newArr[6];
    for (int i = 0; i < 6; i++)
    {
        newArr[i] = arr[i][i];
        cout << newArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[6][6];
    srand(time(0));

    for(int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 6; j++)
        {
            array[i][j] = rand() % 100 + 100;
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    leftToRight(array);

    rightToLeft(array);

    return 0;
}

