#pragma once
#include "Employee.h"
#include "SalaryType.h"
#include "HourlyType.h"
#ifndef SALARYHOURLYEMPLOYEE_H
#define SALARYHOURLYEMPLOYEE_H

class SalaryHourlyEmployee : public Employee, public SalaryType, public HourlyType
{
public:
    SalaryHourlyEmployee(string fName, string ini, string lName, int sal, int hw);

    void printInfo();
    void printSalary();
    void printHourly();
};
#endif