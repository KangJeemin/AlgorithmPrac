#include <iostream>
#include <vector>
#include <algorithm>

#define max 1000001

using namespace std;
// 얼리어답터가 아닌 노드는 자식이 얼리어답터이여야 한.
// 얼리어탑터인 노드는 자식이 얼리어탑더이든 아니든 상관없다.

// tree + DP 문제.

// 트리 관계를 나타내는 배열을 선언하고
// DFS를 이용하여 트리를 탐색하며 DP배열을 만들어 나간다.
// DP[node][0] => 자식이 얼리어답터이여야 하는 경우
// DP[node][1] => 내가 얼리어답터이기 떄문에 자식이 얼리어답터이든 아니든 상관 없는 경우

vector<int> Tree[max];
int dp[max][2];
bool visited[max];
int N;
void DFS(int node);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
        Tree[b].push_back(a);
    }

    // 최상위 노드부터 시작
    DFS(1);

    cout << min(dp[1][0], dp[1][1]);
}

void DFS(int node)
{
    dp[node][0] = 0;
    dp[node][1] = 1;
    visited[node] = true;

    for (int child : Tree[node])
    {
        if (!visited[child])
        {
            visited[child] = true;
            DFS(child);
            // 자식이 얼리어답터여야함
            dp[node][0] += dp[child][1];

            // 자식이 얼리어답터이든 아니든 상관 없음
            dp[node][1] += min(dp[child][0], dp[child][1]);
        }
    }
}