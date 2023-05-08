#pragma once
#include "Employee.h"
#include "SalaryType.h"

class SalaryEmployee1 : public Employee, public SalaryType
{
public:
    SalaryEmployee1(string fName, string ini, string lName, int sal);

    void printInfo();
    void printSalary();
};