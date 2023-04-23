#pragma once
#ifndef STUDENT1_H
#define STUDENT1_H
#include <string>
using namespace std;

class Student1
{
private:
    string name;
    double gpa;
public:
    Student1();
    Student1(string nm, double _gpa);
    void printStudentInfo();

};

#endif