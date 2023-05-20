#include <stdexcept>
#include <iostream>
using namespace std;

int quotient(int first, int second);

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
            cout << "결과 = " << quotient(num1, num2) << endl;
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
        throw invalid_argument("오류: 0으로 나눌 수 없습니다.");
    }
    return first / second;
}
