#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    do
    {
        cout << "문자열 입력: ";
        getline(cin, str);

    } while (str.empty() == true);

    for(int i = 0; i < str.size(); i++)
    {
        str[i] = toupper(str[i]);
    }

    cout << "대문자로 변환 후 : " << str << endl;
}