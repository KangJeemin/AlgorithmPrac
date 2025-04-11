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
    sort(V.begin(), V.end());
    int startindex = 0;
    int endindex = 1;
    int sum;
    int ans = INT_MAX;


    // 조건문에 같다 안 붙히면, 틀림
    // startindex와 endindex가 같을 경우 바로 탐색을 종료하기 때문에, 최적의 케이스가 이후에 있어도 탐색하지 못하고 끝남.
    while (startindex <= endindex && endindex < N)
    {
        sum = V[endindex] - V[startindex];
        // 합이 M보다 크거나 같을떄
        if (sum >= M)
        {
            ans = min(ans, sum);
            startindex++;
        }
        else
        {
            endindex++;
        }
    }
    cout << ans;
}