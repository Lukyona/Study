#include <iostream>
#include <iomanip>
using namespace std;

void findStudentAverage(int const scores[][3], double stdAver[], int rowSize, int colSize)
{
    for(int i = 0; i < rowSize; i++)
    {
        int sum = 0;
        for(int j = 0; j < colSize; j++)
        {
            sum += scores[i][j];
        }
        double average = static_cast<double>(sum) / colSize;
        stdAver[i] = average;
    }
    return;
}

void findTestAverage(int const scores[][3], double tstAver[], int rowSize, int colSize)
{
    for(int j = 0; j < colSize; j++)
    {
        int sum = 0;
        for(int i = 0; i < rowSize; i++)
        {
            sum += scores[i][j];
        }
        double average = static_cast<double>(sum) / rowSize;
        tstAver[j] = average;
    }
}

int main()
{
    const int rowSize = 5;
    const int colSize = 3;
    int scores[rowSize][colSize] = {{82, 65, 72},
                                    {73, 70, 80},
                                    {91, 67, 40},
                                    {72, 72, 68},
                                    {65, 90, 80}};
                                
    double stdAver[rowSize];
    double tstAver[colSize];

    findStudentAverage(scores, stdAver, rowSize, colSize);
    findTestAverage(scores, tstAver, rowSize, colSize);

    cout << "                시험 점수            평균" << endl;
    cout << "       -------------------------  -----" << endl;
    for(int i = 0; i < rowSize; i++)
    {
        for(int j = 0; j < colSize; j++)
        {
            cout << setw(10) << scores[i][j];
        }
        cout << fixed << setprecision(2) << "    " << stdAver[i] << endl;
    }

    cout << "       --------------------------------" << endl;
    cout << "시험 평균 ";
    for(int j = 0; j < colSize; j++)
    {
        cout << fixed << setprecision(2) << tstAver[j] << "    ";
    }
    cout << endl;
    return 0;
}