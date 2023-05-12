#include "Time.h"
#include <cassert>

Time::Time()
    :hour(0), minute(0), second(0), isPM(false)
{
}

Time::Time(int h, int m, int s, int ampm)
{
    if ((h < 1 || h > 12)
        || (m < 1 || m > 59)
        || (s < 1 || s > 59)
        || (ampm != 0 && ampm != 1))
    {
        assert(false);
    }

    hour = h;
    minute = m;
    second = s;
    isPM = ampm;
    
}

Time& Time::operator++()
{
    second++;
    return *this;
}

Time& Time::operator+=(const int sec)
{
    second += sec;
    normalize();
    return *this;
}

int Time::operator()()
{
   //자정으로부터 지난 초단위 시간을 반환
    int totalSec = 0;
    
    if (isPM)
    {
        totalSec += ((hour + 12) * 60 * 60);

    }
    else
    {
        totalSec += (hour * 60 * 60);
    }

    totalSec += (minute * 60);
    totalSec += second;

    return totalSec;
}

void Time::normalize()
{
    if (second > 59)
    {
        minute += (second/60);
        second -= 60 * (second/60);
    }
    if (minute > 59)
    {
        hour += (minute/60);
        minute -= 60 * (minute/60);
    }
    if (hour > 12)
    {
        hour -= 12;
        if (isPM) isPM = false;
        else isPM = true;
    }


}
