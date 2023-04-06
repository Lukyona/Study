#include <iostream>
using namespace std;

int main()
{
    bool flag = true;
    int score = 92;
    double average = 82.56;

    cout << "bool variable" << endl;
    cout << "size: " << sizeof(flag) << "\t";
    cout << "value: " << flag << "\t";
    cout << "address: " << &flag << endl << endl;

    cout << "int variable" << endl;
    cout << "size: " << sizeof(score) << "\t";
    cout << "value: " << score << "\t";
    cout << "address: " << &score << endl << endl;

    cout << "double variable" << endl;
    cout << "size: " << sizeof(average) << "\t";
    cout << "value: " << average << "\t";
    cout << "address: " << &average << endl << endl;



    return 0;
}