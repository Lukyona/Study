#include <iostream>
using namespace std;

class First
{
private:
    int fr;
public:
    First(int fr);
    virtual ~First();
    virtual void print() const;
};

First::First(int _fr)
    :fr(_fr)
{
}

First::~First()
{
}

void First::print() const
{
    cout << fr << endl;
}


class Second : public First
{
private:
    int se;
public:
    Second(int fr, int se);
    ~Second();
    void print() const;
};

Second::Second(int fr, int _se)
    :First(fr), se(_se)
{
}

Second::~Second()
{
}

void Second::print() const
{
    First::print();
    cout << se << endl;
}

int main()
{
    //2��
    /*
    First first(1);
    Second  second(2, 3);

    First* ptr1 = &first;
    ptr1->print();
    //delete ptr1; // �� �޸𸮿� ������ �� �ƴ϶� ����
    
    ptr1 = &second;
    ptr1->print();
    //delete ptr1;
    */

    //3��

    First* ptr1 = new First(1);
    ptr1->print();
    delete ptr1;

    ptr1 = new Second(2,3);
    ptr1->print();
    delete ptr1;
    return 0;
}


