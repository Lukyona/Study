#include <iostream>
#include <string>
using namespace std;

class Base
{
public:
    virtual void print() const { cout << "베이스 클래스" << endl; }
};

class Derived : public Base
{
public:
    // 파생 클래스에서는 virtual 키워드 생략해도 무관
    virtual void print() const { cout << "파생 클래스" << endl; }
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


    // 출력 결과
    // 베이스 클래스
    // 파생 클래스
}