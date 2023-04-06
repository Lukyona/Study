#include <iostream>
#include <string>
using namespace std;

void Replace(string &str1, string &str2, string &str3)
{
    int start, end = 0;

    for(int i = 0; i < str1.size(); i++)
    {
        if(str1[i] == str2[0])
        {
            start = i;
            for(int j = 1; j < str2.size(); j++)
            {
                if(str1[i + j] == str2[j])
                {
                    if(j == (str2.size() - 1)) end = i + j;
                }
                else
                {
                    break;    
                }
            }
        }
    }

    if(end != 0)
    {
        str1.replace(start, (end - start + 1), str3); 
    }
    
}

int main()
{
    string str1;
    string str2;
    string str3;

    do
    {
        cout << "첫 번째 문자열 입력: ";
        getline(cin, str1);

        cout << "두 번째 문자열 입력: ";
        getline(cin, str2);

        cout << "세 번째 문자열 입력: ";
        getline(cin, str3);

    } while (str1.empty() == true || str2.empty() == true || str3.empty() == true);

    Replace(str1, str2, str3);

    cout << "결과: " << str1 << endl;
}