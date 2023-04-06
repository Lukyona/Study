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

        cout << "제거할 문자: ";
        getline(cin, ch);
        
    } while (str.empty() == true || ch.empty() == true);

    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ch[0])
        {
            str.erase(i,1);
            i = 0;
        }
    }

    cout << "제거 후: " << str << endl;
}