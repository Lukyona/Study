#ifndef PASCAL_H
#define PASCAL_H
#include <iostream>
using namespace std;

class Pascal
{
    private:
        int n;
        int** pascal;

    public:
        void print() const;
        Pascal(int num);

};
#endif