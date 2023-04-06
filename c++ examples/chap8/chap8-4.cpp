#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void print(int arr[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void roundShift(int arr[], int size)
{   
    int tmp1;
    int tmp2 = arr[0];
    for(int i = 1; i < size; i++)
    {
        if(i % 2 == 0)//짝수 인덱스, 0
        {
            tmp2 = arr[i];
            arr[i] = tmp1;
        }
        else
        {
            tmp1 = arr[i];
            arr[i] = tmp2;
        }

        if (i == size - 1)
        {
            arr[0] = tmp1;
        }
    }
}

int main()
{
    int arr[10];

    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
    }
    print(arr, 10);
    roundShift(arr, 10);
    print(arr, 10);
    return 0;
}