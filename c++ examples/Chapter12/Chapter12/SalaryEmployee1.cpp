#include "SalaryEmployee1.h"
#include <iostream>

SalaryEmployee1::SalaryEmployee1(string fName, string ini, string lName, int sal)
{
    firstName = fName;
    initial = ini;
    lastName = lName;
    salary = sal;
}

void SalaryEmployee1::printInfo()
{
    cout << "�̸� : " << firstName << endl;
    cout << "�̴ϼ� : " << initial << endl;
    cout << "�� : " << lastName << endl;

}

void SalaryEmployee1::printSalary()
{
    cout << "���� : " << salary << endl;
    cout << endl;
}
