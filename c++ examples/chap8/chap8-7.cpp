#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int arr[20];
    int sizeOdd = 0;
    int sizeEven = 0;

    srand(time(0));
    for(int i = 0; i < 20; i++)
    {
        arr[i] = rand() % 100 + 1;
        if(arr[i] % 2 == 0)
        {
            sizeEven++;
        }
        else
        {
            sizeOdd++;
        }
        cout << arr[i] << " ";
    }
    cout << endl;

    int arrOdd[sizeOdd];
    int arrEven[sizeEven];
    int countEven = 0;
    int countOdd = 0;

    for (int i = 0; i < 20; i++)
    {
        if (arr[i] % 2 == 0)
        {
            arrEven[countEven] = arr[i];
            countEven++;
        }
        else
        {
            arrOdd[countOdd] = arr[i];
            countOdd++;
        }
    }

    for(int i = 0; i < sizeEven; i++)
    {
        cout << arrEven[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < sizeOdd; i++)
    {
        cout << arrOdd[i] << " ";
    }

    return 0;
}