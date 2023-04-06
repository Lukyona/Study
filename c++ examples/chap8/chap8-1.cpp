#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int arr[100] = {0, };

    int low = 100;
    int high = 200;

    //랜덤 숫자 생성 
    srand(time(0));
    for(int i = 0; i < 100; i++)
    {
        int tmp = rand();
        arr[i] = tmp % (high - low + 1) + low;

    }

    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            cout << arr[j + (i * 10)] << " ";
        }
        cout << endl;
    }

    return 0;
}