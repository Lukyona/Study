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
    cout << "이름 : " << firstName << endl;
    cout << "이니셜 : " << initial << endl;
    cout << "성 : " << lastName << endl;

}

void SalaryEmployee1::printSalary()
{
    cout << "월급 : " << salary << endl;
    cout << endl;
}
