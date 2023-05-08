#include "SalaryHourlyEmployee.h"
#include <iostream>

SalaryHourlyEmployee::SalaryHourlyEmployee(string fName, string ini, string lName, int sal, int hw)
{
    firstName = fName;
    initial = ini;
    lastName = lName;
    salary = sal;
    hourly = hw;
}

void SalaryHourlyEmployee::printInfo()
{
    cout << "이름 : " << firstName << endl;
    cout << "이니셜 : " << initial << endl;
    cout << "성 : " << lastName << endl;
}

void SalaryHourlyEmployee::printSalary()
{
    cout << "월급 : " << salary << endl;
    cout << endl;
}

void SalaryHourlyEmployee::printHourly()
{
    cout << "시급 : " << hourly << endl;
    cout << endl;
}
