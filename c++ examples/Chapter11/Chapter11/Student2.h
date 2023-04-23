#pragma once
#ifndef STUDENT2_H
#define STUDENT2_H
#include <string>
#include "Course2.h"
using namespace std;

class Student2
{
private:
    string name;
    double gpa;
    Course2* course;
    unsigned int cNum; // 수강 과목 수
public:
    Student2();
    Student2(string _name, double _gpa);
    ~Student2();


    void addCourse(Course2 c);
    void printStudentInfo();

};

#endif