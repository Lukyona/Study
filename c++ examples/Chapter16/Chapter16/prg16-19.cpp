#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    istringstream iss("Hello yaros!"); // 积己
    cout << iss.str() << endl; // 府畔
    iss.str("Hello luko!"); // 函版
    cout << iss.str() << endl; // 府畔

    ostringstream oss("Bye yaros!");
    cout << oss.str() << endl;
    oss.str("Bye luko!");
    cout << oss.str() << endl;

    return 0;
}