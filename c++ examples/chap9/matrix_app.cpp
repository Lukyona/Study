#include "matrix.h"

int main()
{
    cout << "matrix1" << endl;
    Matrix matrix1(3,4);
    matrix1.setUp();
    matrix1.print();

    cout << "matrix2" << endl;
    Matrix matrix2(3, 4);
    matrix2.setUp();
    matrix2.print();

    cout << "matrix3" << endl;
    Matrix matrix3(4, 2);
    matrix3.setUp();
    matrix3.print();

    cout << "matrix1 + matrix2" << endl;
    Matrix addResult(3,4);
    matrix1.add(matrix2, addResult);
    addResult.print();

    cout << "matrix1 - matrix2" << endl;
    Matrix subResult(3, 4);
    matrix1.subtract(matrix2, subResult);
    subResult.print();

    cout << "matrix1 * matrix3" << endl;
    Matrix mulResult(3, 2);
    matrix1.multiply(matrix3, mulResult);
    mulResult.print();

    return 0;
}