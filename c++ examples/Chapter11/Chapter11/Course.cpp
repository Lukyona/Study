#include "Course.h"

Course::Course(string nm, int ut)
    :name(nm), units(ut)
{
    roster = new CourseRoster;
}

Course::~Course()
{
}

string Course::getName() const
{
    return name;
}

CourseRoster* Course::getRoster() const
{
    return roster;
}

void Course::addStudent(string name)
{
    roster->addStudent(name);
}

void Course::print() const
{
    cout << "�ڽ� �̸�: " << name << endl;
    cout << "������ ����: " << units << endl;
    roster->print();
}
