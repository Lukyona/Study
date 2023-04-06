#include "customized.h"
#include <string>
#include <iostream>
using namespace std;

int findValue(char ch)
{
    return static_cast<int>(ch) - 48;
}

int main()
{
    string binary;
    do
    {
        cout << "2진수 숫자 입력: ";
        getline(cin, binary);
    } while (binary.find_first_not_of("01") < binary.size());
    
    int base = 2;
    int demical = 0;
    while(!binary.empty())
    {
        demical *= base;
        char ch = popFront(binary);
        demical += findValue(ch);
    }
    cout << "10진수 값 : " << demical;
    return 0;
}