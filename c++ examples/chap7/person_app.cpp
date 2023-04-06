#include "person.h"

int main()
{
    Person Lee("이정현", 23);
    Person Im("임수정", 23);

    cout << "Lee의 이름은 " << Lee.getName() << ", 나이는 " << Lee.getAge() << endl;
    cout << "Im의 이름은 " << Im.getName() << ", 나이는 " << Im.getAge() << endl;

    Im.setName("빙구");
    Lee.setAge(21);

    cout << "Lee의 나이는 " << Lee.getAge() << endl;
    cout << "Im의 이름은 " << Im.getName() << endl;
    return 0;
}