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
        cout << "intFile을 열 수 없습니다.";
        assert(false);
    }

    int num;
    int sum = 0;
    while (fstr >> num)
    {
        sum += num;
    }

    fstr.clear();
    fstr << "\n숫자의 합 ";
    fstr << sum;
    fstr.close();

    return 0;

}