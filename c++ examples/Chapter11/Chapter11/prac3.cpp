#include <iostream>
using namespace std;

class First
{
private:
    int a;
public:
    First();
    First(int a);
    void print() const;
};

First::First()
    :a(0)
{
}

First::First(int _a)
    :a(_a)
{
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
    Second();
    Second(int a, int b);
    void print() const;
};

Second::Second()
{
}

Second::Second(int _a, int _b)
{
    First::First(_a);
    b = _b;
}

void Second::print() const
{
    First::print();
    cout << b << endl;
}

class Third : public Second
{
private:
    int c;
public:
    Third();
    Third(int a, int b, int c);
    void print() const;
};

Third::Third() {}

Third::Third(int _a, int _b, int _c)
    : c(_c)
{
    Second::Second(_a, _b);
}

void Third::print() const
{
    Second::print();
    cout << c << endl;
}