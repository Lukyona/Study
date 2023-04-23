#pragma once
#ifndef COURSE2_H
#define COURSE2_H
#include <string>
using namespace std;

class Course2
{
private:
    string name;
    int units; // 과목 학점
public:
    Course2();
    Course2(string nm, int uni);
    ~Course2();
    
    void print();

};

#endif