#include "customized.h"
#include <string>
#include <iostream>
using namespace std;

int main()
{
    string strg("abcdefgh");

    cout << "pushFront 전 문자열: " << strg << endl;
    pushFront(strg, 'A');
    cout << "pushFront 후 문자열: " << strg << endl;
    cout << endl;

    cout << "pushBack 전 문자열: " << strg << endl;
    pushBack(strg, 'Z');
    cout << "pushBack 후 문자열: " << strg << endl;
    cout << endl;

    cout << "popFront 전 문자열: " << strg << endl;
    char c1 = popFront(strg);
    cout << "popFront 후 문자열: " << strg << endl;
    cout << "추출한 문자: " << c1 << endl;
    cout << endl;

    cout << "popBack 전 문자열: " << strg << endl;
    char c2 = popBack(strg);
    cout << "popBack 후 문자열: " << strg << endl;
    cout << "추출한 문자: " << c2 << endl;
    cout << endl;

    return 0;
}