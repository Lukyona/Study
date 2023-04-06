#include "multTable.h"
#include <iomanip>

MultTable::MultTable(int rows, int cols)
:rowSize(rows), colSize(cols)
{
    if(rows > 10 || cols > 10)
    {
        cout << "행과 열은 10 이하의 숫자여야 합니다." << endl;
        assert(false);
    }
    arr = new int*[rowSize];
    for(int i = 0; i < rowSize; i++)
    {
        arr[i] = new int[colSize];
    }
}

void MultTable::print() const
{
    for(int i = 0; i <= rowSize; i++)
    {
        for(int j = 0; j <= colSize; j++)
        {
            if(i == 0 && j < colSize)
            {
                cout << "     " << j+1;
            }
            else if(j == 0)
            {
                cout << i << "  ";
            }
            else if(i != 0)
            {
                cout << setw(3)  << i * j;
                cout << "   ";
            }
        }
        cout << endl;
    }
    cout << endl;
}