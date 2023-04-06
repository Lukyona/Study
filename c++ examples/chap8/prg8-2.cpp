#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    const int CAPACITY = 50;
    int numbers[CAPACITY];
    int size = 0;
    ifstream inputFile;
    ofstream outputFile;

    inputFile.open("inFile.txt");
    if(!inputFile)
    {
        cout << "파일을 열 수 없습니다." << endl;
        cout << "프로그램을 중단합니다.";
        return 0;
    }

    while(inputFile >> numbers[size] && size <= 50)
    {
        size++;
    }
    
    inputFile.close();

    outputFile.open("outFile.txt");
    if(!outputFile)
    {
        cout << "파일을 열 수 없습니다." << endl;
        cout << "프로그램을 중단합니다.";
        return 0;
    }

    for(int i = size - 1; i >= 0; i--)
    {
        outputFile << numbers[i] << " ";
    }

    outputFile.close();
    return 0;
}