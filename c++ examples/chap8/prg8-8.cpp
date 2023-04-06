#include <iostream>
using namespace std;

void reverse(const int array1[], int array2[], int size)
{
    for(int i = 0, j = size - 1; i < size; i++, j--)
    {
        array2[j] = array1[i];
    }
    return;
}

void print(const int numbers[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;
    return;
}

int main()
{
    int array1[5] = {150, 170, 190, 110, 130};
    int array2[5];

    reverse(array1, array2, 5);

    print(array1, 5);
    print(array2, 5);

    return 0;
}