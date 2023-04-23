#pragma once
#ifndef HOURLY_H
#define HOURLY_H
#include "Employee.h"
#include <random>

class Hourly : public Employee
{
private:
    Employee emp;
    int hWage; // 시급
    float overtimeRate; // 추가 시급 비율
public:
    Hourly(string name, int eNum, string bDate, string hDate, int hWage);
};

Hourly::Hourly(string name, int eNum, string bDate, string hDate, int hWage)
{
    emp = Employee(name, eNum, bDate, hDate);
    overtimeRate = (float)(((rand() % 6) + 5) / 100);
}
#endif