#include <iostream>
#include <string>
using namespace std;


string RemoveOverlap(string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        for (int j = i + 1; j < str.size(); j++)
        {
            if (str[i] == str[j])
            {
                str.erase(j, 1);
                j--;
            }
        }
    }

    return str;
}


int main()
{
    string str;
    do
    {
        cout << "문자열 입력: ";
        getline(cin, str);

    } while (str.empty() == true);

    RemoveOverlap(str);

    cout << "중복 제거 후: " << str << endl;
}