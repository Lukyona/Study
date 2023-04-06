#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char* str1 = "Hello lice.";
    const char *str2 = "Hello John.";
    const char *str3 = "Hello Besty.";

    cout << "str1과 str2 비교: ";
    cout << strcmp(str1, str2) << endl;
    cout << "str2과 str3 비교: ";
    cout << strcmp(str2, str3) << endl;

    cout << "str1과 str2의 앞 5문자만 비교하기: ";
    cout << strncmp(str1, str2, 5) << endl;

    return 0;
}