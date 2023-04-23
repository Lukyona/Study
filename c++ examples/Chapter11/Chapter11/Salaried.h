
#pragma once
#ifndef SALARIED_H
#define SALARIED_H
#include "Employee.h"
#include <random>

class Salaried : public Employee
{
private:
    Employee emp;
    int mSalary; // ���޿�
    float aBonus; // �������ʽ�
public:
    Salaried(string name, int eNum, string bDate, string hDate, int salary);

};

Salaried::Salaried(string name, int eNum, string bDate, string hDate, int salary)
    :mSalary(salary)
{
    emp = Employee(name, eNum, bDate, hDate);
    aBonus = (float)((rand() % 11) / 100);

}

#endif