#include "HourlyEmployee1.h"
#include <iostream>

HourlyEmployee1::HourlyEmployee1(string fName, string ini, string lName, int hw)
{
    firstName = fName;
    initial = ini;
    lastName = lName;
    hourly = hw;
}

void HourlyEmployee1::printInfo()
{
    cout << "이름 : " << firstName << endl;
    cout << "이니셜 : " << initial << endl;
    cout << "성 : " << lastName << endl;
}

void HourlyEmployee1::printHourly()
{
    cout << "시급 : " << hourly << endl;
    cout << endl;
}
