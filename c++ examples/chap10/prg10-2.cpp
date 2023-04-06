#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    const char* str1 = "Hello my friends.";
    char str2[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    cout << "str1의 길이: " << strlen(str1) << endl;
    cout << "str2의 길이: " << strlen(str2);
}