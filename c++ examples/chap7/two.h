#include <iostream>
using namespace std;

#ifndef TWO_H
#define TWO_H

class Two
{
    private:
        int x;
        char a;

    public:
        Two(int x, char a);
        int getX() const;
        char getA() const;
        void setX(int v);
        void setA(char v);
};
#endif