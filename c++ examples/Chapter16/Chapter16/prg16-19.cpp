#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    istringstream iss("Hello yaros!"); // 생성
    cout << iss.str() << endl; // 리턴
    iss.str("Hello luko!"); // 변경
    cout << iss.str() << endl; // 리턴

    ostringstream oss("Bye yaros!");
    cout << oss.str() << endl;
    oss.str("Bye luko!");
    cout << oss.str() << endl;

    return 0;
}