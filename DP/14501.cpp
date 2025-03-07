#include <iostream>
using namespace std;
int map[16][2];
int dp[16];
int N;
int main()
{
    int ans = 0;

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a >> b;
        map[i][0] = a;
        map[i][1] = b;
    }

    for (int i = 1; i <= N; i++)
    {
        int ti = map[i][0];
        int pi = map[i][1];
        dp[i] = max(dp[i], ans);
        // 범위를 벗어나지 않을때
        if (i + ti <= N + 1)
        {
            dp[i + ti] = max(dp[i] + pi, dp[i + ti]);
        }

        ans = max(ans, dp[i + 1]);
    }

    cout << ans;
}