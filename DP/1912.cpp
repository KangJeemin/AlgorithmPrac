#include <iostream>
#include <algorithm>

#define maxV 100000
using namespace std;
static int N;
int dp[maxV] = {
    0,
};
static int ans;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        if (i == 1)
        {
            dp[i] = a;
            ans = a;
            continue;
        }

        dp[i] = max(a, a + dp[i - 1]);
        ans = max(ans, dp[i]);
    }
    cout << ans;
}