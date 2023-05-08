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
    cout << "�̸� : " << firstName << endl;
    cout << "�̴ϼ� : " << initial << endl;
    cout << "�� : " << lastName << endl;
}

void SalaryHourlyEmployee::printSalary()
{
    cout << "���� : " << salary << endl;
    cout << endl;
}

void SalaryHourlyEmployee::printHourly()
{
    cout << "�ñ� : " << hourly << endl;
    cout << endl;
}
