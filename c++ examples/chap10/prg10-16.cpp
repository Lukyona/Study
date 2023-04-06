#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    cout << "한 줄 입력: ";
    getline(cin, line);
    
    for(int i = 0; i < line.size(); i++)
    {
        line[i] = toupper(line[i]);
    }

    cout << line << endl;

    return 0;
}