#include "convert.h"

int main()
{
    string strg = toString(12);
    cout << "���ڿ�: " << strg << endl;

    double data = toData<double>("15.67");
    cout << "������: " << data << endl;


    return 0;
}