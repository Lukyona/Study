#include "Student2.h"
#include <iostream>
using namespace std;

Student2::Student2()
    :name(""), gpa(0.0), cNum(0)
{
    course = new Course2[4];
}

Student2::Student2(string _name, double _gpa)
    :name(_name), gpa(_gpa), cNum(0)
{
    course = new Course2[4];
}

Student2::~Student2()
{
    delete[] course;
}

void Student2::addCourse(Course2 c)
{
    if (cNum == 4)
    {
        Course2* tmp = new Course2[4 * 2];
        for (int i = 0; i < cNum; ++i)
        {
            tmp[i] = course[i];
        }
        delete[] course;
        course = tmp;
    }
    course[cNum] = c;
    ++cNum;
}

void Student2::printStudentInfo()
{
    cout << "�̸�: " << name << endl;
    cout << "��� ����: " << gpa << endl;
    cout << "���� ����(�Ʒ�)" << endl;
    for (int i = 0; i < cNum; ++i)
    {
        course[i].print();
    }
    cout << endl;
}
