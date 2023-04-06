#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strg("Yaro Family");
    cout << "인덱스 5 위치의 문자: " << strg[5] << endl;
    cout << "인덱스 8 위치의 문자: " << strg.at(8) << endl;

    return 0;
}