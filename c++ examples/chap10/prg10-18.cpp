#include <iostream>
#include <string>
using namespace std;

int main()
{
    string strg("Yaro Family");
    cout <<  strg.substr(8) << endl;
    cout << strg.substr(4, 7) << endl;

    return 0;
}