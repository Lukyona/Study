#include "Employee.h"

Employee::Employee()
    :name(""), eNum(0), bDate("000000"), hDate("000000")
{
}

Employee::Employee(string _name, int _eNum, string _bDate, string _hDate)
    :name(_name), eNum(_eNum), bDate(_bDate), hDate(_hDate)
{
}

Employee::~Employee()
{
}
