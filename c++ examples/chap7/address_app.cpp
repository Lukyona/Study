#include "address.h"
#include <string>

int main()
{
    string state = "경기도";
    string city = "고양시";
    string street = "냥냥로";

    Address address(12035, state, city, street, 2000);

    address.printAddress();

    return 0;
}