#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
    int size = 10;
    int arr[size];

    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();
    int minIndex = 0;
    int maxIndex= 0;

    srand(time(0));
    for(int i = 0; i < size; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
        
        if(min > arr[i])
        {
            min = arr[i];
            minIndex = i;
        }
        if(max < arr[i])
        {
            max = arr[i];
            maxIndex = i;
        }
    }
    cout << endl;
    
    for(int i = minIndex + 1; i < size; i++)
    {
        arr[i - 1] = arr[i];
    }
    size--;

    for (int i = maxIndex + 1; i < size; i++)
    {
        arr[i - 1] = arr[i];
    }
    size--;

    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}