#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    istringstream iss("Hello yaros!"); // ����
    cout << iss.str() << endl; // ����
    iss.str("Hello luko!"); // ����
    cout << iss.str() << endl; // ����

    ostringstream oss("Bye yaros!");
    cout << oss.str() << endl;
    oss.str("Bye luko!");
    cout << oss.str() << endl;

    return 0;
}