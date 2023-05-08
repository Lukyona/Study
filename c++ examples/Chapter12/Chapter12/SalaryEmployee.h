#pragma once
#include "Employee.h"


class SalaryEmployee : public Employee
{
protected:
    int salary;
public:
    SalaryEmployee(string fName, string ini, string lName, int salary);

    void printInfo();
};

