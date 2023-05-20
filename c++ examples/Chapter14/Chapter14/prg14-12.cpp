#include <stdexcept>
#include <iostream>
using namespace std;

int quotient(int first, int second);

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
            cout << "��� = " << quotient(num1, num2) << endl;
        }
        catch (invalid_argument ex)
        {
            cout << ex.what() << endl;
        }
    }

    return 0;
}

int quotient(int first, int second)
{
    if (second == 0)
    {
        throw invalid_argument("����: 0���� ���� �� �����ϴ�.");
    }
    return first / second;
}
