#include "zeller.h"
#include <cassert>

Zeller::Zeller(int y, int m, int d)
: year(y), month(m), day(d)
{
    if(y < 0 || m < 0 || d < 0)
    {
        assert(false);
    }
}

string Zeller::getWeekday() const
{
    string result = "";
    int weekday = (day + 26 * (month + 1) / 10 + year + year / 4 - year / 100 + year / 400) % 7;
    switch (weekday)
    {
        case 0:
            result = "토요일";
            break;
        case 1:
            result = "일요일";
            break;
        case 2:
            result = "월요일";
            break;
        case 3:
            result = "화요일";
            break;
        case 4:
            result = "수요일";
            break;
        case 5:
            result = "목요일";
            break;
        case 6:
            result = "금요일";
            break;
        default:
            break;
    }

    return result;
}