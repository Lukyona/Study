#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    void print() const { cout << "베이스 클래스" << endl; }
};

class Derived : public Base
{
public:
    void print() const { cout << "파생 클래스" << endl; }
};


int main()
{
    Base* ptr;

    ptr = new Base();
    ptr->print();
    delete ptr;

    ptr = new Derived();
    ptr->print();
    delete ptr;

    return 0;


    // 결과
    //  베이스 클래스 두 번 출력
}