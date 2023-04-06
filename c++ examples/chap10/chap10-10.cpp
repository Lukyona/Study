#include <iostream>
#include <string>
using namespace std;

int main()
{
    int dec = 0; // 10진수
    string oct;  // 8진수
    string set = "01234567";
    bool again = false;
    do
    {
        cout << "8진수 입력: ";
        cin >> oct;
      
    } while (oct.find_first_not_of(set) < oct.size()); // 8진수 유효성 검사

    while (dec != 0)
    {
        int temp = popFront(oct);
        

        dec += temp * (8); //8의 n(자릿수-1)제곱을 곱해야함.

       
    }


    cout << "16진수로 변환 : " << hex << endl;
}