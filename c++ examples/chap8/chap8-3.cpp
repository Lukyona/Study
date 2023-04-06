#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

int main()
{
    int arr[10];
    int sum = 0;
    int average;

    srand(time(0));
    for(int i = 0; i < 10; i++)
    {
        arr[i] = rand() % 100 + 1;
        cout << arr[i] << " ";
        sum += arr[i];
    }
    cout << endl;

    average = sum / 10;

    cout << "평균 : " << average << endl;

 
    sum = 0;
    for(int i = 0; i < 10; i++)
    {
        sum += pow(arr[i] - average, 2);
    }

    int var = sum / 10; //분산 
    double stdDev = sqrt(var); //표준 편차 

    cout << "표준 편차 : " << stdDev << endl;

    return 0;
}