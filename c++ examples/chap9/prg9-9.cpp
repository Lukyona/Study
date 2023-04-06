#include <iostream>
using namespace std;

int main()
{
    int numbers[5] = {10, 11, 12, 13, 14};

    cout << "인덱스를 사용해서 배열의 요소에 접근하기" << endl;
    for(int i = 0; i < 5; i++)
    {
        cout << numbers[i] << "  ";
    }
    cout << endl;

    cout << "포인터를 사용해서 배열의 요소에 접근하기" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << *(numbers + i) << "  ";
    }
    return 0;
}