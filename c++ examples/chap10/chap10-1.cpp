#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    string ch;
    do
    {
        cout << "문자열 입력: ";
        getline(cin, str);

        cout << endl;

        cout << "찾을 문자: ";
        getline(cin, ch);
    } while (str.empty() == true || ch.empty() == true);

    int count = 0;
    for(int i = 0; i < str.length(); i++)
    {
        if(str[i] == ch[0])
            count++;
    }

    cout << ch << "의 개수: " << count << "개" << endl;


}