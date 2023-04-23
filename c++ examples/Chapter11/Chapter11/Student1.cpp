#include "Student1.h"
#include <iostream>
using namespace std;

Student1::Student1()
    :name(""), gpa(0.0)
{
}

Student1::Student1(string _name, double _gpa)
    :name(_name), gpa(_gpa)
{

}

void Student1::printStudentInfo()
{
    cout << "이름: " << name << endl;
    cout << "평균 학점: " << gpa << endl;
}
