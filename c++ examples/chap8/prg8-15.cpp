#include <iostream>
using namespace std;

void leanearization_row(const int d2array[2][4], int d1array[8])
{
    int h = 0; //1차원 배열의 인덱스
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            d1array[h] = d2array[i][j];
            h++;
        }
    }
}

void leanearization_col(const int d2array[2][4], int d1array[8])
{
    int h = 0; //1차원 배열의 인덱스
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            d1array[h] = d2array[j][i];
            h++;
        }
    }
}

int main()
{
    int d2_array[2][4] = {{0, 1, 2, 3},
                      {10, 11, 12, 13}};

    int d1_array[8];

    cout << "기존 2차원 배열" << endl;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << d2_array[i][j] << " ";
        }
        cout << endl;
    }

    cout << "2차원 배열을 행방향으로 선형 변환한 1차원 배열" << endl;
    leanearization_row(d2_array, d1_array);

    for(int i = 0; i < 8; i++)
    {
        cout << d1_array[i] << " ";
    }
    cout << endl;

    cout << "2차원 배열을 열방향으로 선형 변환한 1차원 배열" << endl;
    leanearization_col(d2_array, d1_array);

    for (int i = 0; i < 8; i++)
    {
        cout << d1_array[i] << " ";
    }
    cout << endl;

    return 0;
}