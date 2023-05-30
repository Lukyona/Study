#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    char ch;

    ifstream inStrm;
    inStrm.open("file1", ios::in);
    if (!inStrm.is_open())
    {
        cout << "file1을 열 수 없습니다.";
        assert(false);
    }
    while (inStrm.get(ch))
    {
        cout.put(ch);
    }

    inStrm.close();

    return 0;

}