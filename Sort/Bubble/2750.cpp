// 버블정렬
// 시간복잡도 : O(N^2)

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // N개의 수 입력을 위한 변수 선언
    int N;
    vector<int> V;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }

    for (int i = N - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (V[j] > V[j + 1])
            {
                swap(V[j], V[j + 1]);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        cout << V[i] << '\n';
    }

    return 0;
}