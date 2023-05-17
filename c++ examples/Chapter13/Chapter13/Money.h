#pragma once
class Money
{
private:
    int USD;
    int cent;
public:
    Money();
    Money(int d, int c);

    Money operator + (const Money& other);
    Money operator - (const Money& other);
    Money& operator *= (int num);
    Money& operator /= (int num);

    bool operator < (const Money& other);
    bool operator > (const Money& other);
    bool operator == (const Money& other);
    bool operator != (const Money& other);
};

