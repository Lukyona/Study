#include <iostream>
#include <string>
using namespace std;

int main()
{
    //11
    // string str = "";
    // cout << "문자열 입력: ";
    // getline(cin, str);

    // if(str.size() % 2 != 0)
    // {
    //     str.insert(0, " ");
    // }

    // string str1 = str.substr(0, str.size() / 2);
    // string str2 = str.substr(str.size() / 2, str.size());

    // cout << "앞 : " << str1 << endl;
    // cout << "뒤 : " << str2 << endl;

    // 12
    string str = "";
    do
    {
        cout << "문자열 입력(4문자 이상): ";
        getline(cin, str);
    }while(str.size() < 4);


    cout << "처음 4문자:" << str.substr(0, 4) << endl;
    cout << "마지막 4문자:" << str.substr((str.size() - 4), str.size()) << endl;
}