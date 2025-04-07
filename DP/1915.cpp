#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
static int map[1000][1000];
static int dp[1000][1000];
static int ans;
void init();

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();

    for (int i = 1; i < N; i++)
    {
        for (int j = 1; j < M; j++)
        {
            if (map[i][j] == 0)
            {
                dp[i][j] = 0;
                continue;
            }
            dp[i][j] = min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]}) + 1;

            ans = max(ans, dp[i][j]);
        }
    }

    cout << ans * ans;
}
void init()
{
    cin >> N >> M;
    ans = 0;
    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; j++)
        {
            int b = a[j] - '0';
            map[i][j] = b;
        }
    }

    for (int i = 0; i < N; i++)
    {
        dp[i][0] = map[i][0];
        ans = max(ans, dp[i][0]);
    }
    for (int j = 0; j < M; j++)
    {
        dp[0][j] = map[0][j];
        ans = max(ans, dp[0][j]);
    }
}