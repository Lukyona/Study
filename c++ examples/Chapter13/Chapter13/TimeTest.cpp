#include "Time.h"
#include <iostream>
using namespace std;

int main()
{
    Time time(1, 10, 10, 0);

    Time time1 = ++time;
    time += 1;

    cout << time() << endl;


}