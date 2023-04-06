#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strg;
    cout << "한 줄 입력: ";
    getline(cin, strg);
    cout << strg << endl << endl;

    cout << "여러 줄을 입력(종료는 $): " << endl;
    getline(cin, strg, '$');
    cout << strg;

    return 0;
}