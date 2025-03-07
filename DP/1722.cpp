#include <iostream>
#include <vector>
using namespace std;

int N, a;
long dp[21];
bool used[21];
int main()
{
    cin >> N >> a;
    dp[0] = 1;
    for (int i = 1; i < N; i++)
    {
        dp[i] = dp[i - 1] * i;
    }

    if (a == 1)
    {
        long k;
        cin >> k;
        vector<int> findN(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (used[j])
                    continue;

                if (k > dp[N - i - 1])
                {
                    k -= dp[N - i - 1];
                    continue;
                }
                else
                {
                    findN[i] = j;
                    used[j] = true;
                    break;
                }
            }
        }
        for (int q = 0; q < N; q++)
        {
            cout << findN[q] << " ";
        }
    }
    else
    {
        long ans = 0;
        for (int i = 1; i <= N; i++)
        {
            long k;
            cin >> k;
            for (int j = 1, count = 0; j <= N; j++)
            {
                if (used[j])
                    continue;
                if (k == j)
                {
                    ans += count * dp[N - i];
                    used[j] = true;
                    break;
                }
                else
                {
                    count++;
                }
            }
        }
        cout << ans + 1;
    }
}