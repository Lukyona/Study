#include "SalaryEmployee1.h"
#include "HourlyEmployee1.h"
#include "SalaryHourlyEmployee.h"


int main()
{
    SalaryEmployee1 draco("�巹����", "D.M", "������", 5500);
    HourlyEmployee1 sougo("�Ұ�", "O.S", "��ŰŸ", 55);
    SalaryHourlyEmployee luko("���ڿ���", "L.S", "��Ÿũ����", 6500, 60);

    draco.printInfo();
    draco.printSalary();

    sougo.printInfo();
    sougo.printHourly();

    luko.printInfo();
    luko.printSalary();
    luko.printHourly();

    return 0;
}