#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;


int main()
{
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    int index;

    try
    {
        cout << "접근할 인덱스 : ";
        cin >> index;

        char ch = str.at(index-1);
    }
    catch (out_of_range ex)
    {
        cout << "잘못된 인덱스입니다." << endl;
    }


    return 0;
}
