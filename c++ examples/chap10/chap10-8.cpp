#include <iostream>
#include <string>
using namespace std;

int main()
{
    int dec = 0; //10진수
    string oct; //8진수
    do
    {
        cout << "10진수 입력: ";
        cin >> dec;

    } while (dec == 0);


    while(dec != 0)
    {
        oct.append(to_string(dec % 8));
        dec /= 8;
    }

    reverse(oct.begin(), oct.end());

    cout << "8진수로 변환 : " << oct << endl;
}