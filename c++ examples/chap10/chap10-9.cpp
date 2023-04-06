#include <iostream>
#include <string>
using namespace std;

int main()
{
    int dec = 0; // 10진수
    string hex;  // 16진수
    do
    {
        cout << "10진수 입력: ";
        cin >> dec;

    } while (dec == 0);

    while (dec != 0)
    {
        int val = dec % 16;

        if (val >= 10)
        {
            switch (val)
            {
                case 10:
                    hex.append("A");
                    break;
                case 11:
                    hex.append("B");
                    break;
                case 12:
                    hex.append("C");
                    break;
                case 13:
                    hex.append("D");
                    break;
                case 14:
                    hex.append("E");
                    break;
                case 15:
                    hex.append("F");
                    break;
            
            }
        }
        else
        {
            hex.append(to_string(val));
        }

        dec /= 16;
    }

    reverse(hex.begin(), hex.end());

    cout << "16진수로 변환 : " << hex << endl;
}