#include<iostream>
#include<vector>
#include<queue>

using namespace std;

vector<vector<int>> tree;
vector<bool> visited;
int start;
int N;
int cutNode;
int ans = 0;

void BFS(int startNode) {
    if (visited[startNode]) return;
    queue<int> Q;
    Q.push(startNode);
    visited[startNode] = true;

    while (!Q.empty()) {
        int node = Q.front();
        Q.pop();
        // 리프노드
        if (tree[node].size() == 0) {
            ans++;
            continue;
        }
        for (int i : tree[node]) {
            if (i == cutNode && tree[node].size() == 1) {
                ans++;
                continue;
            }
            if (!visited[i]) {
                visited[i] = true;

                Q.push(i);
            }
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    tree.resize(N);
    visited.resize(N, false);

    for (int i = 0;i < N;i++) {
        int a;
        cin >> a;

        if (a == -1) {
            start = i;
            continue;
        }
        tree[a].push_back(i);
    }

    cin >> cutNode;
    visited[cutNode] = true;
    BFS(start);

    cout << ans;

    return 0;
}