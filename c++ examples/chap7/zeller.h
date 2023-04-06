#include <iostream>
using namespace std;

#ifndef ZELLER_H
#define ZELLER_H

class Zeller
{
    private:
        int year;
        int month;
        int day;
    public:
        Zeller(int year, int month, int day);
        string getWeekday() const;
};
#endif