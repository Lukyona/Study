#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    int arr1[10];

    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        arr1[i] = rand() % 100 + 1;
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    int arr2[10];
    for(int i = 0, j = 9; i < 10, j >= 0; i++, j--)
    {
        arr2[i] = arr1[j];
        cout << arr2[i] << " ";
    }

    return 0;
}