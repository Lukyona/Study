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
    cout << "�̸� : " << firstName << endl;
    cout << "�̴ϼ� : " << initial << endl;
    cout << "�� : " << lastName << endl;
    cout << "�ñ� : " << hourly << endl;
    cout << endl;
}
