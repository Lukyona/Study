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
    :invalid_argument("����")
{

}

const char* DivByZero::what() const
{
    return "0���� ���� �� �����ϴ�.";
}

int main()
{
    int num1, num2, result;
    for (int i = 0; i < 3; i++)
    {
        cout << "������ �Է��ϼ���: ";
        cin >> num1;
        cout << "�� �ٸ� ������ �Է��ϼ���: ";
        cin >> num2;
        
        try
        {
            if (num2 == 0)
                throw DivByZero();

            result = num1 / num2;
            cout << "��� = " << result << endl;
        }
        catch (DivByZero& x)
        {
            cout << x.what() << endl;
        }
    }
    return 0;
}