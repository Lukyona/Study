#include <iostream>
using namespace std;

void print(const int numbers[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    return;
}

int main()
{
    int numbers[15] = {5, 7, 9, 11, 13};
    print(numbers, 5);
    return 0;
}