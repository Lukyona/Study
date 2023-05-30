#include <iostream>
using namespace std;

int main()
{
    char c;
    cout << "여러 줄의 글자 입력(종료는 ctrl+Z)" << endl;
    char pre = ' ';

    while (cin.get(c))
    {
        if (pre == ' ' || pre == '/n')
            cout.put(toupper(c));
        else
            cout.put(c);

        pre = c;
    }

    return 0;
}