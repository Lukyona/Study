#include "SalaryEmployee.h"
#include <iostream>


SalaryEmployee::SalaryEmployee(string fName, string ini, string lName, int sal)
{
    firstName = fName;
    initial = ini;
    lastName = lName;
    salary = sal;
}

void SalaryEmployee::printInfo()
{
    cout << "�̸� : " << firstName << endl;
    cout << "�̴ϼ� : " << initial << endl;
    cout << "�� : " << lastName << endl;
    cout << "���� : " << salary << endl;
    cout << endl;
}
