#include <iostream>
#include <fstream>
#include <cassert>
using namespace std;

int main()
{
    fstream fstr;

    fstr.open("intFile", ios::in | ios::out);
    if (!fstr.is_open())
    {
        cout << "intFile�� �� �� �����ϴ�.";
        assert(false);
    }

    int num;
    int sum = 0;
    while (fstr >> num)
    {
        sum += num;
    }

    fstr.clear();
    fstr << "\n������ �� ";
    fstr << sum;
    fstr.close();

    return 0;

}