#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


int main()
{
    int N, score;

    cin >> N;

    vector<double> vec;

    for (int i = 0; i < N; i++)
    {
        cin >> score;
        vec.push_back((double)score);
    }

    double max = vec[0];
    for (int i = 1; i < N; i++)
    {
        if (max < vec[i])
            max = vec[i];
    }

    for (int i = 0; i < N; i++)
    {
        vec[i] = vec[i] / max * 100.0;
    }

    double sum = 0.0;
    for (int i = 0; i < N; i++)
    {
        sum += vec[i];
    }

    cout << setprecision(16) << sum / N;
    return 0;
}