#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int N, M;
vector<int> V;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    V.resize(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> V[i];
    }
    int startindex = 0;
    int endindex = 0;
    int sum = 0;
    int ans = N + 1;

    while (startindex <= endindex && endindex <= N)
    {
        // 조건 만족하지 못했을 경우
        if (sum < M)
        {
            sum += V[endindex];
            endindex++;
        }
        // 조건 만족했을경우
        else
        {
            ans = min(endindex - startindex, ans);
            sum -= V[startindex];
            startindex++;
        }
    }
    if (ans == N + 1)
    {
        cout << 0;
    }
    else
    {
        cout << ans;
    }
}