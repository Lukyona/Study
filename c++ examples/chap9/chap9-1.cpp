#include <iostream>
using namespace std;

int& FindBigNum(int& a, int& b, int& c)
{
    if(a > b)
    {
        if(a > c)
        {
            return a;
        }
        else
        {
            return c;
        }
    
        
    }
    else if(b > c)
    {
        return b;
    }
    else
    {
        return c;
    }
    

    
}

int main()
{
    int one, two, three = 0;
    cin >> one;
    cin >> two;
    cin >> three;

    cout << "가장 큰 정수는 " << FindBigNum(one, two, three) << endl;

    return 0;
}