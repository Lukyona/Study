#include "convert.h"

int main()
{
    string strg = toString(12);
    cout << "문자열: " << strg << endl;

    double data = toData<double>("15.67");
    cout << "데이터: " << data << endl;


    return 0;
}