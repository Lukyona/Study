#include <iostream>
using namespace std;

int main()
{
    int x;
    cout << "공백 없이 문자 5개 입력: ";
    for (int i = 0; i < 5; i++)
    {
        x = cin.get();
        cout << x << " ";
    }
    return 0;
}