#include "fraction.h"

Fraction& larger(Fraction&, Fraction&);

int main()
{
    Fraction fract1(3, 13); //분자, 분모 
    Fraction fract2(5, 17);
    cout << "첫 번째 쌍에서 더 큰 분수: ";
    larger(fract1, fract2).print();

    Fraction fract3(4, 9);
    Fraction fract4(1, 6);
    cout << "두 번째 쌍에서 더 큰 분수: ";
    larger(fract3, fract4).print();


    return 0;
}

Fraction& larger(Fraction& fract1, Fraction& fract2)//denom 분모 
{
    if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom())//엇갈려 곱하기를 통한 분수 크기 비교
    {
        return fract1;
    }
    return fract2;
}