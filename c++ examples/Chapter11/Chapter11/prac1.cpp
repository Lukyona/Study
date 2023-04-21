#include <iostream>
using namespace std;

class First
{
private:
    int a;
public:
    void set(int a);
    void print() const;
};

void First::set(int _a)
{
    a = _a;
}

void First::print() const
{
    cout << a << endl;
}


class Second : public First
{
private:
    int b;
public:
    void set(int a, int b);
    void print() const;
};

void Second::set(int _a, int _b)
{
    First::set(_a);

    b = _b;
}

void Second::print() const
{
    First::print();

    cout << b << endl;
}