#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "2022년 3월 18일";
    char* p;

    p = strtok(str, " ");
    while(p)
    {
        cout << p << endl;
        p = strtok(0, " ");
    }

    return 0;
}