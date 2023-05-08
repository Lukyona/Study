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
    cout << "이름 : " << firstName << endl;
    cout << "이니셜 : " << initial << endl;
    cout << "성 : " << lastName << endl;
    cout << "월급 : " << salary << endl;
    cout << endl;
}
