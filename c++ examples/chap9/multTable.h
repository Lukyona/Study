#ifndef MULTTABLE_H
#define MULTTABLE_H
#include <iostream>
#include <cassert>
using namespace std;

class MultTable
{
    private:
        int rowSize;
        int colSize;
        int** arr;

    public:
        MultTable(int rows, int cols);
        void print() const;
};
#endif