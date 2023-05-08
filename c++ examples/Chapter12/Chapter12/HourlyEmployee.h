#pragma once
#include "Employee.h"


class HourlyEmployee : public Employee
{
protected:
    int hourly;
public:
    HourlyEmployee(string fName, string ini, string lName, int hw);

    void printInfo();
};

