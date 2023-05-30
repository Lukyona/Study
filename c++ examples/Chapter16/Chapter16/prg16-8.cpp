#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    ofstream outStrm;

    outStrm.open("file1", ios::out | ios::app);
    if (!outStrm.is_open())
    {
        cout << "file1을 열 수 없습니다.";
        assert(false);
    }
    
    outStrm << "\nMay 30, 2023";

    outStrm.close();

    return 0;

}