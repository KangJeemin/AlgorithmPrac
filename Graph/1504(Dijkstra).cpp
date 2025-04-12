#include <iostream>
#include <queue>
#include <climits>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> edge;

static int N, E;
static int node1, node2;

vector<int> dajikstra(int a)
{
    vector<int> visited;
    visited.resize(N + 1, 200000000);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> Q;

    visited[a] = 0;
    Q.push({0, a});

    while (!Q.empty())
    {

        auto [curDist, cur] = Q.top();
        Q.pop();

        if (visited[cur] < curDist)
            continue;

        for (auto [next, cost] : edge[cur])
        {
            if (visited[next] > visited[cur] + cost)
            {
                visited[next] = visited[cur] + cost;
                Q.push({visited[next], next});
            }
        }
    }
    return visited;
}

int main()
{
    cin >> N >> E;
    edge.resize(N + 1);
    int ans1 = 0;
    int ans2 = 0;

    for (int i = 0; i < E; i++)
    {
        int a, b, c;

        cin >> a >> b >> c;
        edge[a].push_back({b, c});
        edge[b].push_back({a, c});
    }
    cin >> node1 >> node2;

    vector<int> v1 = dajikstra(1);
    vector<int> v2 = dajikstra(node1);
    vector<int> v3 = dajikstra(node2);
    // 경로 1 : 1 -> node1 -> node2 -> N
    ans1 = v1[node1] + v2[node2] + v3[N];

    // 경로 2 : 1 -> node2 -> node1 -> N
    ans2 = v1[node2] + v3[node1] + v2[N];

    if (ans1 >= 200000000 && ans2 > 200000000)
    {
        cout << -1;
    }
    else
    {
        cout << min(ans1, ans2);
    }
}