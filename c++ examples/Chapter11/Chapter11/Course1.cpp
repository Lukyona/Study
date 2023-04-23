#include "Course1.h"

Course1::Course1(int cap)
    :capacity(cap)
{
    students = new Student1[capacity];
}

void Course1::printAllStudentInfo()
{
    for (int i = 0; i < capacity; ++i)
    {
        students[i].printStudentInfo();
    }
}
