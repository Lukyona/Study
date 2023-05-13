#include <iostream>
using namespace std;


int main()
{
    // 10811번, 벡터 가변배열과 스왑 함수 썼더라..

    int N, M, i, j;
    cin >> N >> M;

    int* arr = new int[N];
    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    for (int q = 0; q < M; q++)
    {
        cin >> i >> j;
        j--;
        for (int w = i -1; w < j; w++, j--)
        {
            int tmp = arr[w];
            arr[w] = arr[j];
            arr[j] = tmp;
        }
    }

    for (int e = 0; e < N; e++)
    {
        cout << arr[e] << " ";
    }

    return 0;
}