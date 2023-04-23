#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int eNum; // 직원 번호
    string bDate; // 생일
    string hDate; //고용일
public:
    Employee();
    Employee(string _name, int _eNum, string _bDate, string _hDate);
    ~Employee();

};

#endif