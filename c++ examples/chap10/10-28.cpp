#include "customized.h"
#include <string>
#include <iostream>
using namespace std;

char findChar(int digit)
{
    return char(digit + 48);
}

int main()
{
    int demical;
    int base = 2;
    string strg;

    do
    {
        cout << "10진수 정수 입력: ";
        cin >> demical;
    } while (demical <= 0);
    
    while(demical > 0)
    {
        int digit = demical % base;
        cout << digit << endl;
        char ch = findChar(digit);
        cout << ch << endl;

        pushFront(strg, ch);
        cout << strg << endl;

        demical /= base;
        cout << demical << endl;

    }
    cout << "2진수: " << strg;
    return 0;
}