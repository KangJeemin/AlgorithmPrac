#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<algorithm>

using namespace std;
typedef pair<int, int> edge;

vector<vector<pair<int, int>>> route;
vector<int> mdistance;
vector<bool> visited;


priority_queue < edge, vector<edge>, greater<edge>> Q;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int V, E;
    cin >> V >> E;

    int start;
    route.resize(V + 1);
    mdistance.resize(V + 1, INT_MAX);
    visited.resize(V + 1, false);
    cin >> start;
    mdistance[start] = 0;


    for (int i = 0;i < E;i++) {
        int start, end, weight;
        cin >> start >> end >> weight;
        route[start].push_back({ end,weight });
    }

    Q.push({ 0,start });

    while (!Q.empty()) {
        edge current = Q.top();
        Q.pop();
        int weight = current.first; // 우선순위큐를 사용할때 거리가 짧은 순서대로 경로를 조사하기 위함
        int node = current.second;


        if (visited[node]) continue;  // 방문했던 경로는 재방문 하지 않음.
        visited[node] = true;

        for (pair<int, int> i : route[node]) {
            int next = i.first;
            int Nweight = i.second;

            mdistance[next] = min(mdistance[next], mdistance[node] + Nweight);
            Q.push({ weight + Nweight, next });
        }
    }

    for (int i = 1;i <= V;i++) {
        if (!visited[i]) {
            cout << "INF\n";
        }
        else {
            cout << mdistance[i] << '\n';
        }
    }





    return 0;
}