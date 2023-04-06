#include "zeller.h"

int main()
{
    Zeller date1(2021, 11, 24);
    cout << "2021/11/24 : " << date1.getWeekday() << endl;

    Zeller date2(2021, 11, 20);
    cout << "2021/11/20 : " << date2.getWeekday() << endl;

    return 0;
}
