#pragma once
#ifndef REGISTER_H
#define REGISTER_H
#include "Course.h"
#include "Student.h"

class Register
{
public:
    Register();
    ~Register();

    void enroll(Student student, Course course);
};

#endif