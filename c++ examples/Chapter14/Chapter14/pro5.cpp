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
        cout << "������ �ε��� : ";
        cin >> index;

        char ch = str.at(index-1);
    }
    catch (out_of_range ex)
    {
        cout << "�߸��� �ε����Դϴ�." << endl;
    }


    return 0;
}
