#include <iostream>
using namespace std;


int main()
{
    int a,b;
    int bArr[3] = {0, }; //차례로 일, 십, 백의 자리 숫자 저장
    int sum = 0;

    cin >> a >> b;

    for(int i = 0; i < 3; i++) //일, 십, 백의 자리 숫자 추출
    {
        bArr[i] = b % 10;
        b /= 10;
        cout << a * bArr[i] << endl; 
    }

    cout << a * bArr[0] + ((a * bArr[1]) * 10) + ((a * bArr[2]) * 100); 

    return 0;
}