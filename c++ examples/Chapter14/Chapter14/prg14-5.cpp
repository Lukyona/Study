#include <iostream>
#include <stdexcept>
using namespace std;

class DivByZero : public invalid_argument
{
public:
    DivByZero();
    virtual const char* what() const;
};

DivByZero::DivByZero()
    :invalid_argument("오류")
{

}

const char* DivByZero::what() const
{
    return "0으로 나눌 수 없습니다.";
}

int main()
{
    int num1, num2, result;
    for (int i = 0; i < 3; i++)
    {
        cout << "정수를 입력하세요: ";
        cin >> num1;
        cout << "또 다른 정수를 입력하세요: ";
        cin >> num2;
        
        try
        {
            if (num2 == 0)
                throw DivByZero();

            result = num1 / num2;
            cout << "결과 = " << result << endl;
        }
        catch (DivByZero& x)
        {
            cout << x.what() << endl;
        }
    }
    return 0;
}