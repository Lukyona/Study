#pragma once
#include <string>
using namespace std;

class Employee
{
protected:
    string firstName;
    string initial;
    string lastName;

public:
    virtual void printInfo() = 0;
};