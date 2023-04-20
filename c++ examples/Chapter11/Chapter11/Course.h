#pragma once
#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <iostream>
#include "CourseRoster.h"
using namespace std;

class Course
{
private:
    string name;
    int units;
    CourseRoster* roster;
public:
    Course(string name, int units);
    ~Course();
    string getName() const;
    CourseRoster* getRoster() const;
    void addStudent(string name);
    void print() const;
};

#endif