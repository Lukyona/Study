#include <iostream>
using namespace std;

int main()
{
    int arr[5];

    for(int i = 0; i < 5; i++)
    {
        cout << "포인터 연산을 사용한 주소: " << i;
        cout << arr + i << endl;
        cout << "& 연산자를 사용한 주소: " << i;
        cout << &arr[i] << endl;
    }

    return 0;
}