#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char str[] = "Hello friends of mine";

    char* sPtr = strstr(str, "friends");
    cout << "서브 문자열의 시작 인덱스: " << sPtr - str; 

    return 0;
}