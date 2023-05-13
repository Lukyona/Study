#include <iostream>
using namespace std;


int main()
{
    // 3052¹ø 
    int arr[10];

    for (int i = 0; i < 10; i++)
    {
        cin >> arr[i];
        arr[i] %= 42;
    }

    int num = 1;
    int tmp;
    bool exist = false;
    for (int i = 1; i < 10; i++)
    {
        exist = false;
        tmp = arr[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (tmp == arr[j])
            {
                exist = true;
                break;
            }

        }
        if (!exist) num++;
    }
    cout << num;
    return 0;
}