#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    ofstream outStrm;
    
    outStrm.open("integerFile");
    if (!outStrm.is_open())
    {
        cout << "integetFile�� �� �� �����ϴ�.";
        assert(false);
    }

    for (int i = 1; i <= 10; i++)
    {
        outStrm << i * 10 << " ";
    }

    outStrm.close();

    return 0;
}