#include <iostream>
//#include <cstring>
using namespace std;

int main()
{
    char str1[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    const char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};

    const char* str3 = "Goodbye";
    const char* str4 = "Goodbye\0 my friend";

    cout << "str1: " << str1 << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

    char str5[20];
    cout << "str5의 값 입력: ";
    cin >> str5;
    cout << "str5: " << str5;

    return 0;
}