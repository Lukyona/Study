#include "SalaryEmployee1.h"
#include "HourlyEmployee1.h"
#include "SalaryHourlyEmployee.h"


int main()
{
    SalaryEmployee1 draco("드레이코", "D.M", "말포이", 5500);
    HourlyEmployee1 sougo("소고", "O.S", "오키타", 55);
    SalaryHourlyEmployee luko("루코엘라", "L.S", "산타크루즈", 6500, 60);

    draco.printInfo();
    draco.printSalary();

    sougo.printInfo();
    sougo.printHourly();

    luko.printInfo();
    luko.printSalary();
    luko.printHourly();

    return 0;
}