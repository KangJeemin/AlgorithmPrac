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
        // pair<int, int> a = Q.top();
        // Q.pop();
        // int DDist = a.first;
        // int DtargetNode = a.second;
        // for (int i = 0; i < edge[DtargetNode].size(); i++)
        // {
        //     int dist = edge[DtargetNode][i].first;
        //     int targetNode = edge[DtargetNode][i].second;
        //     // 다음 방문 노드가 이미 최적의 경로를 보장할 경우
        //     if (visited[targetNode] < DDist + dist)
        //         continue;
        //     visited[targetNode] = DDist + dist;
        //     Q.push({DDist + dist, targetNode});
        // }
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

    vector<int> a = dajikstra(1);
    vector<int> b = dajikstra(node1);
    vector<int> c = dajikstra(node2);
    // 경로 1 : 1 -> node1 -> node2 -> N
    ans1 = a[node1] + b[node2] + c[N];

    // 경로 2 : 1 -> node2 -> node1 -> N
    ans2 = a[node2] + c[node1] + b[N];

    if (ans1 >= 200000000 && ans2 > 200000000)
    {
        cout << -1;
    }
    else
    {
        cout << min(ans1, ans2);
    }
}