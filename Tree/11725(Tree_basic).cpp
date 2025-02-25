#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;
int N;


int DFS(int parentNode) {
    for (int i = 0;i < tree[parentNode].size();i++) {
        int childNode = tree[parentNode][i];
        if (visited[childNode]) continue;
        visited[childNode] = true;
        int child = DFS(childNode);
        parent[child] = parentNode;
    }
    return parentNode;
}

// 더 가독성 좋은 버전
void DFS2(int number) {
    visited[number] = true;

    for (int i : tree[number]) {
        if (!visited[i]) {
            parent[i] = number;
            DFS(i);
        }
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    tree.resize(N + 1);
    parent.resize(N + 1, 0);
    visited.resize(N + 1, false);

    for (int i = 1;i < N;i++) {
        int a, b;
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }

    DFS(1);

    for (int i = 2;i <= N;i++) {
        cout << parent[i] << " ";
    }


    return 0;
}