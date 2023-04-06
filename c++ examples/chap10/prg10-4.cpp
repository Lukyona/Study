#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char lines[3][80];

    for(int i = 0; i < 3; i++)
    {
        cout << "한 줄을 입력하세요: ";
        cin.getline(lines[i], 80);
    }

    cout << endl;
    cout << "출력: " << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << lines[i] << endl;
    }
    return 0;
}