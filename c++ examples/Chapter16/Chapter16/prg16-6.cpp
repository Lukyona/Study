#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    int data;

    ifstream inStrm;
    inStrm.open("integerFile");
    if (!inStrm.is_open())
    {
        cout << "integetFile�� �� �� �����ϴ�.";
        assert(false);
    }
    for (int i = 1; i <= 10; i++)
    {
        inStrm >> data;
        cout << data << " ";
    }

    inStrm.close();

    return 0;

}