#pragma once
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee
{
private:
    string name;
    int eNum; // ���� ��ȣ
    string bDate; // ����
    string hDate; //�����
public:
    Employee();
    Employee(string _name, int _eNum, string _bDate, string _hDate);
    ~Employee();

};

#endif