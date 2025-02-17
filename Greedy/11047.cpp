#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> coin;
    int N, K;
    cin >> N >> K;
    coin.resize(N);
    int ans = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    for (int i = N - 1; i >= 0; i--)
    {
        if (K == 0)
            break;
        if (K >= coin[i])
        {
            ans += K / coin[i];
            K = K % coin[i];
        }
    }
    cout << ans;
}
