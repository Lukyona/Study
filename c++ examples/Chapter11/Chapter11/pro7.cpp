#include "Student2.h"
#include "Course2.h"


int main()
{
    Student2 luko("Lukoella", 4.4);
    Student2 draco("Draco", 4.0);
    Student2 sougo("Sougo", 4.0);

    Course2 history("History of Magic", 2);
    Course2 flying("Flying", 3);
    Course2 training("Training", 3);
    Course2 potions("Potions", 3);

    luko.addCourse(history);
    luko.addCourse(training);
    luko.addCourse(potions);

    draco.addCourse(history);
    draco.addCourse(flying);
    draco.addCourse(training);

    sougo.addCourse(flying);
    sougo.addCourse(training);
    sougo.addCourse(potions);

    luko.printStudentInfo();
    draco.printStudentInfo();
    sougo.printStudentInfo();

    return 0;
}