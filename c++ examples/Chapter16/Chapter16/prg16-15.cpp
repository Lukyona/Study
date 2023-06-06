#include <iostream>
#include <string>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    int int1 = 12325;
    double double1 = 45.78;

    ofstream strmOut("sample2", ios::out | ios::binary);
    if (!strmOut.is_open())
    {
        cout << "������ �� �� �����ϴ�.";
        assert(false);
    }

    strmOut.write(reinterpret_cast<char*>(&int1), sizeof(int));
    strmOut.write(reinterpret_cast<char*>(&double1), sizeof(double));
    strmOut.close();

    int int2;
    double double2;

    ifstream strmIn("sample2", ios::in | ios::binary);
    if (!strmIn.is_open())
    {
        cout << "������ ���� �� �����ϴ�.";
        assert(false);
    }
    
    strmIn.read(reinterpret_cast<char*>(&int2), sizeof(int));
    strmIn.read(reinterpret_cast<char*>(&double2), sizeof(double));
    strmIn.close();

    cout << "int2�� ��: " << int2 << endl;
    cout << "double2�� ��: " << double2 << endl;

    return 0;
}