#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main()
{
    int arr[10] = {0, };

    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        int tmp = rand();
        arr[i] = tmp % 10 + 1;
        cout << arr[i] << " ";
    }
    
    int min = numeric_limits<int>::max();
    int max = numeric_limits<int>::min();

    for(int i = 0; i < 10; i++)
    {
        if(min > arr[i])
        {
            min = arr[i];
        }
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    cout << endl;
    cout << "min : " << min << endl;
    cout << "max : " << max << endl;

    return 0;
}