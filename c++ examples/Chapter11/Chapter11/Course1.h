#pragma once
#ifndef COURSE1_H
#define COURSE1_H
#include "Student1.h"

class Course1
{
private:
    unsigned int capacity;
    Student1* students;
public:
    Course1(int cap);
    void printAllStudentInfo();

};

#endif