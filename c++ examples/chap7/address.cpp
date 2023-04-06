#include "address.h"

Address::Address(int zCode, string state, string city, string street, int hNo)
: zipcode(zCode), stateName(state), cityName(city), streetName(street), houseNo(hNo)
{

}

Address::~Address()
{

}

void Address::printAddress() const
{
    cout << stateName << " " << cityName << " " << streetName << " " << houseNo << endl;
    cout << "우편번호 : " << zipcode << endl;
}