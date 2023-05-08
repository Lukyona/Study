#include "SalaryEmployee.h"
#include "HourlyEmployee.h"


int main()
{
    SalaryEmployee luko("Luko", "L.S", "Santacruz", 6000);
    SalaryEmployee draco("Draco", "D.M", "Malfoy", 5000);
    HourlyEmployee sougo("Sougo", "O.S", "Okita", 45);
    HourlyEmployee me("Sujeong", "S.I", "Im", 30);

    luko.printInfo();
    draco.printInfo();
    sougo.printInfo();
    me.printInfo();



    return 0;
}