#include <string>
#include <iostream>
using namespace std;

int main()
{
    string first, last;
    char init;

    cout << "First Name : ";
    cin >> first;
    cout << "Last Name : ";
    cin >> last;
    cout << "Initial : ";
    cin >> init;

    cout << endl;

    cout << "첫 번째 형식의 Full Name: ";
    cout << first + " " + init + "." + " " + last << endl;

    cout << "두 번째 형식의 Full Name: ";
    cout << last + "," + first + " " + init + "." << endl;
    
    return 0;
}