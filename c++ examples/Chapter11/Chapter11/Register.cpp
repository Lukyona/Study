#include "Register.h"

Register::Register()
{
}

Register::~Register()
{
}

void Register::enroll(Student student, Course course)
{
    (course.getRoster())->addStudent(student.getName());
    (student.getSchedule()->addCourse(course.getName()));
}
