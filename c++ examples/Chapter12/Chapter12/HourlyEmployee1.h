#pragma once
#include "Employee.h"
#include "HourlyType.h"

class HourlyEmployee1 : public Employee, public HourlyType
{
public:
    HourlyEmployee1(string fName, string ini, string lName, int hw);

    void printInfo();
    void printHourly();
};