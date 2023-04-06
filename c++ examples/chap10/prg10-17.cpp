#include <iostream>
#include <string>
using namespace std;

void reverse(string& strg);

int main()
{
    string strg;
    cout << "문자열 입력: ";
    getline(cin, strg);
    cout << "원본 문자열: " << strg << endl;

    reverse(strg);
    cout << "뒤집은 문자열: " << strg;

    return 0;
}

void reverse(string &strg)
{
    string temp(strg);
    int size = strg.size();
    for(int i = 0; i < size; i++)
    {
        strg[i]  = temp[size - 1 - i];
    }
}