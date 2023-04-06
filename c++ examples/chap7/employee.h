#include <iostream>
using namespace std;

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
    private:
        string name;
        int age;
        int serviceYear;
        int salary;
    public:
        Employee(string name, int age, int serviceYear, int salary);
        ~Employee();
        string getName() const;
        int getAge() const;
        int getServiceYear() const;
        int getSalary() const;
};
#endif