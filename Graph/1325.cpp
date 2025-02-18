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
        count++;  // ��ŷ ������ ��� ���� ������Ŵ

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

    vector<vector<int>> V(N + 1); // ��ǻ�� ��ȣ�� 1���� N����
    vector<int> resultArray(N + 1, 0);

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        V[b].push_back(a);  // b�� a�� �ŷ���
    }

    int MaxCount = 0;

    for (int i = 1; i <= N; i++) {
        vector<int> visited(N + 1, 0);
        int count = 0;  // �� ��ǻ�Ϳ��� ��ŷ ������ ��ǻ�� ���� ���

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
