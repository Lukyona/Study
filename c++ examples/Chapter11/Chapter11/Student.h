#pragma once
#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <iostream>
#include <cassert>
#include "StudentSchedule.h"
using namespace std;

class Student
{
private:
    string name;
    StudentSchedule* schedule;
public:
    Student(string name);
    ~Student();
    string getName() const;
    StudentSchedule* getSchedule() const;
    void addCourse(string name);
    void print() const;
};

#endif;