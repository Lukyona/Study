#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "Hello friends.";

    char* cPtr = strchr(str, 'e');
    *cPtr = 'E';
    cout << "첫 변경 후 : " << str << endl;

    cPtr = strrchr(str, 'e');
    *cPtr = 'E';
    cout << "두번째 변경 후 : " << str << endl;
}