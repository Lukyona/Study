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
    cout << "�̸� : " << firstName << endl;
    cout << "�̴ϼ� : " << initial << endl;
    cout << "�� : " << lastName << endl;
}

void HourlyEmployee1::printHourly()
{
    cout << "�ñ� : " << hourly << endl;
    cout << endl;
}
