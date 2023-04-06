#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inFile;
    inFile.open("inputFile.txt");

    if(!inFile)
    {
        cout << "파일을 여는 도중에 오류가 나타났습니다." << endl;
        cout << "프로그램을 종료합니다." << endl;
    }

    int histogram[10] = {0};
    int num;
    while(inFile >> num)
    {
        switch (num)
        {
            case 0:
                histogram[0] += 1;
                break;
            case 1:
                histogram[1] += 1;
                break;
            case 2:
                histogram[2] += 1;
                break;
            case 3:
                histogram[3] += 1;
                break;
            case 4:
                histogram[4] += 1;
                break;
            case 5:
                histogram[5] += 1;
                break;
            case 6:
                histogram[6] += 1;
                break;
            case 7:
                histogram[7] += 1;
                break;
            case 8:
                histogram[8] += 1;
                break;
            case 9:
                histogram[9] += 1;
        }
    }
    inFile.close();

    for(int i = 0; i < 10; i++)
    {
        cout << "숫자 "<< i << "은(는) " << histogram[i] << "개입니다." << endl;
    }

    cout << "가로 그래프로 나타내면(세로는 어려움^^;)" << endl;

    for(int i = 0; i < 10; i++)
    {
        cout << i << " | ";
        for(int j = 0; j < histogram[i]; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}