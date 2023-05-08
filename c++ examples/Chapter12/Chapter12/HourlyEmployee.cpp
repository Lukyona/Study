#include "HourlyEmployee.h"
#include <iostream>


HourlyEmployee::HourlyEmployee(string fName, string ini, string lName, int hw)
{
    firstName = fName;
    initial = ini;
    lastName = lName;
    hourly = hw;
}

void HourlyEmployee::printInfo()
{
    cout << "이름 : " << firstName << endl;
    cout << "이니셜 : " << initial << endl;
    cout << "성 : " << lastName << endl;
    cout << "시급 : " << hourly << endl;
    cout << endl;
}
