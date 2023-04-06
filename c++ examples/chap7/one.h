#include <iostream>
using namespace std;

#ifndef ONE_H
#define ONE_H

class One
{
    private:
        int x;
        int y;
    public:
        One(int x, int y);
        One();
        One(const One& one);
        ~One();
        int getX() const;
        int getY() const;
};
#endif