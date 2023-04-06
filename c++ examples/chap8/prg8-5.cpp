#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    const int CAPACITY = 50;
    int numbers[CAPACITY];
    int size = 0;

    int sum = 0;
    double average;
    int smallest = 10000000;
    int biggest = - 10000000;

    inputFile.open("numFile.txt");
    if(!inputFile)
    {
        cout << "입력 파일을 여는 동안 문제가 발생했습니다." << endl;
        cout << "프로그램을 중단합니다." << endl;
        return 0;
    }

    while(inputFile >> numbers[size])
    {
        size++;
    }
    inputFile.close();

    for(int i = 0; i < size; i++)
    {
        sum += numbers[i];
        if(numbers[i] < smallest)
        {
            smallest = numbers[i];
        }
        if(numbers[i] > biggest)
        {
            biggest = numbers[i];
        }
    }
    average = static_cast<double>(sum) / size;

    cout << "목록에 숫자가 " << size << "개 있습니다." << endl;
    cout << "합계: " << sum << endl;
    cout << "평균: " << average << endl;
    cout << "최소값: " << smallest << endl;
    cout << "최대값: " << biggest << endl;

    return 0;
}