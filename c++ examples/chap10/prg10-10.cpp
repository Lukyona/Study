#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str1[20] = "This is ";
    const char* str2 = "a string";
    strcat(str1, str2);
    cout << "str1: " << str1 << endl;

    char str3[20] = "abcdefghijk";
    const char* str4 = "ABCDEFGHIJK";
    strncat(str3, str4, 4);
    cout << "str3: " << str3;

    return 0;
}