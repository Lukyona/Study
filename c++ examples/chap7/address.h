#include <iostream>
using namespace std;

#ifndef ADDRESS_H
#define ADDRESS_H

class Address
{
    private:
        int zipcode;
        string stateName;
        string cityName;
        string streetName;
        int houseNo;

    public:
        Address(int zCode, string state, string city, string street, int hNo);
        ~Address();
        void printAddress() const;
};
#endif