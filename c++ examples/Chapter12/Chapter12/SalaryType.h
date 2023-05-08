#pragma once
#ifndef SALARYTYPE_H
#define SALARYTYPE_H

class SalaryType
{
protected:
    int salary;
public:
    virtual void printSalary() = 0;
};


#endif // !SALARYTYPE_H
