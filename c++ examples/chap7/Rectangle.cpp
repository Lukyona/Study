#include <iostream>
#include <cassert>
using namespace std;

class Rectangle
{
    private:
        double length;
        double height;
        static int count; //정적 멤버

    public:
        Rectangle(double length, double height);
        Rectangle();
        Rectangle(const Rectangle& rect);
        ~Rectangle();
        void print() const;
        double getArea() const;
        double getPerimeter() const;
        static int getCount();
};

int Rectangle::count = 0; //정적 멤버는 전역 부분에서 초기화

Rectangle::Rectangle(double len, double hgt) //매개변수 있는 생성자
: length(len), height(hgt) //초기화 리스트(생성자 함수에서만)
{
    count++;
}

Rectangle::Rectangle()
: length(0.0), height(0.0)
{
    count++;
}

Rectangle::Rectangle(const Rectangle& rect)
: length(rect.length), height(rect.height)
{ 
    count++;
}

Rectangle::~Rectangle()
{
    count--;
}

int Rectangle::getCount()
{
    return count;
}

void Rectangle::print() const
{
    cout << "사각형의 너비: " << length << ", 높이: " << height << endl;
}

double Rectangle::getArea() const
{
    return (length * height);
}

double Rectangle::getPerimeter() const
{
    return (2 * (length + height));
}

int main()
{
    {
        Rectangle rect1(3.2, 1.2);
        Rectangle rect2(1.5, 2.1);
        Rectangle rect3;
        Rectangle rect4(rect1);
        Rectangle rect5(rect2);

        cout << "객체의 수: " << rect1.getCount() << endl;

    }

    cout << "객체의 수: " << Rectangle::getCount() << endl;

    return 0;
}