#include <iostream>
#include <string>
using namespace std;

void FindCommonCharacter(string &str1, string &str2)
{
    string common;
    int length1 = str1.size();
    int length2 = str2.size();

    if (str1.size() < str2.size())
    {
        length1 = str2.size();
        length2 = str1.size();
    }


    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            if (str1[i] == str2[j])
            {
                
                common.push_back(str1[i]);
                    
            }
        }   
    }

    for (int i = 0; i < common.size(); i++)
    {
        for (int j = i + 1; j < common.size(); j++)
        {
            if (common[i] == common[j])
            {
                common.erase(j, 1);
                j--;
            }
        }
    }
    cout << common << endl;
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

    cout << "공통 문자: ";
    FindCommonCharacter(str1, str2);
}