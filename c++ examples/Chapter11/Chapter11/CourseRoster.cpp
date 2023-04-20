#include "CourseRoster.h"

CourseRoster::CourseRoster()
    : size(0)
{
    stdNames = new string[20];
}

CourseRoster::~CourseRoster()
{
    delete[] stdNames;
}

void CourseRoster::addStudent(string studentName)
{
    stdNames[size] = studentName;
    size++;
}

void CourseRoster::print() const
{
    cout << "수강하는 학생 목록" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << stdNames[i] << endl;
    }
    cout << endl;
}
