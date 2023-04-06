#include <iostream>
#include <string>
using namespace std;

void Insert(string &str1, string &str2)
{
    if(str1.size() % 2 != 0)
    {
        str1.push_back(str1[str1.size()-1]);
    }

    str1.insert(str1.size()/2, str2);

}

int main()
{
    string str1;
    string str2;
    do
    {
        cout << "첫 번째 문자열 입력: ";
        getline(cin, str1);

        cout << "두 번째 문자열 입력: ";
        getline(cin, str2);

    } while (str1.empty() == true || str2.empty() == true);

    Insert(str1, str2);
    cout << "결과 : " << str1 << endl;
}