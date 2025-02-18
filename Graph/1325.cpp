#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;

void BFS(int i, vector<int>& visited, vector<vector<int>>& V, int& count) {
    queue<int> Queue;
    Queue.push(i);
    visited[i] = 1;

    while (!Queue.empty()) {
        int a = Queue.front();
        Queue.pop();
        count++;  // 해킹 가능한 노드 수를 증가시킴

        for (int j = 0; j < V[a].size(); j++) {
            if (!visited[V[a][j]]) {
                Queue.push(V[a][j]);
                visited[V[a][j]] = 1;
            }
        }
    }
}

int main() {
    cin >> N >> M;

    vector<vector<int>> V(N + 1); // 컴퓨터 번호는 1부터 N까지
    vector<int> resultArray(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        V[b].push_back(a);  // b가 a를 신뢰함
    }

    int MaxCount = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> visited(N + 1, 0);
        int count = 0;  // 이 컴퓨터에서 해킹 가능한 컴퓨터 수를 기록

        BFS(i, visited, V, count);

        resultArray[i] = count;
        if (MaxCount < count) {
            MaxCount = count;
        }
    }

    for (int i = 1; i <= N; i++) {
        if (resultArray[i] == MaxCount) {
            cout << i << " ";
        }
    }

    return 0;
}
