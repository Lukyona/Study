#include "Course2.h"
#include <iostream>
using namespace std;

Course2::Course2()
    :name(""), units(0)
{
}

Course2::Course2(string nm, int uni)
    :name(nm), units(uni)
{
}

Course2::~Course2()
{
}

void Course2::print()
{
    cout << name << ", " << units << endl;
}
