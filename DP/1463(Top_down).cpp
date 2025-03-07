#include <iostream>
using namespace std;
static int N;

int dp[1000001];

static int DFS(int N)
{
    static int res = 1000001;
    if (N == 1)
    {
        return dp[N];
    }
    // 3으로 나누어 지는 경우
    if (N % 3 == 0)
    {
        if (dp[N / 3] == 0)
        {
            dp[N / 3] = dp[N] + 1;
            res = min(res, DFS(N / 3));
        }
    }
    // 2로 나누어 지는 경우
    else if (N % 2 == 0)
    {
        if (dp[N / 2] == 0)
        {
            dp[N / 2] = dp[N] + 1;
            res = min(res, DFS(N / 2));
        }
    }
    // -1 하는 경우
    else
    {
        if (dp[N - 1] == 0)
        {
            dp[N - 1] = dp[N] + 1;
            res = min(res, DFS(N - 1));
        }
    }
    return res;
}

int main()
{
    cin >> N;

    int ans = DFS(N);
    cout << ans;
}