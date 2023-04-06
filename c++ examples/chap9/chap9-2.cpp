#include "fraction.h"

Fraction& larger(Fraction& fract1, Fraction& fract2, Fraction& fract3) // denom 분모
{
    if (fract1.getNumer() * fract2.getDenom() > fract2.getNumer() * fract1.getDenom()) //엇갈려 곱하기를 통한 분수 크기 비교
    {
        if (fract1.getNumer() * fract3.getDenom() > fract3.getNumer() * fract1.getDenom())
        {
            return fract1;
        }
        return fract3;
    }
    else if (fract2.getNumer() * fract3.getDenom() > fract3.getNumer() * fract2.getDenom())
    {
        return fract2;
    }
    else
    {
        return fract3;
    }

}

int main()
{
    Fraction one(6,10);
    Fraction two(7, 10);
    Fraction three(9, 10);

    cout << "가장 큰 분수는 ";
    larger(one, two, three).print();

    return 0;
}