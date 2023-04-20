#include "Student.h"

Student::Student(string nm)
    :name(nm)
{
    schedule = new StudentSchedule;
}

Student::~Student()
{
}

string Student::getName() const
{
    return name;
}

StudentSchedule* Student::getSchedule() const
{
    return schedule;
}

void Student::addCourse(string name)
{
    schedule->addCourse(name);
}

void Student::print() const
{
    cout << "�л� �̸�: " << name << endl;
    schedule->print();
}
