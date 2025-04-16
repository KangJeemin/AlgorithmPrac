// 트리의 지름을 찾는 기본 문제
// 노드의 아무 지점을 잡고 그 지점을 기준으로 최장길이을 갖는 노드를 구한다
// 위 과정에서 구한 노드를 지점으로 잡고 그 지점을 기준으로 다시 최장길이를 갖는 노드를 구하면 답이 된다.

#include <iostream>
#include <vector>
#define max 10001
using namespace std;

vector<pair<int, int>> tree[max];
int N;
vector<bool> visited;
vector<bool> visited2;
vector<int> treeWeight;
vector<int> treeWeight2;
void DFS(int node, vector<bool> &visited, vector<int> &treeWeight);

int main()
{

    cin >> N;
    visited.resize(N + 1, false);
    visited2.resize(N + 1, false);
    treeWeight.resize(N + 1, 0);
    treeWeight2.resize(N + 1, 0);

    for (int i = 0; i < N - 1; i++)
    {
        // a,b는 두 노드, c는 가중치
        int a, b, c;
        cin >> a >> b >> c;

        tree[a].push_back({b, c});
        tree[b].push_back({a, c});
    }

    DFS(1, visited, treeWeight);
    int findNode = 1;
    int findWeght = 0;

    for (int i = 1; i <= N; i++)
    {
        if (treeWeight[i] > findWeght)
        {
            findWeght = treeWeight[i];
            findNode = i;
        }
    }
    DFS(findNode, visited2, treeWeight2);
    int findNode2 = 1;
    int findWeght2 = 0;

    for (int i = 1; i <= N; i++)
    {
        if (treeWeight2[i] > findWeght2)
        {
            findWeght2 = treeWeight2[i];
            findNode2 = i;
        }
    }

    cout << findWeght2;

    // 루트를 시작으로 제일 긴 값 찾기
}
void DFS(int node, vector<bool> &visited, vector<int> &treeWeight)
{
    visited[node] = true;
    for (pair<int, int> child : tree[node])
    {
        if (!visited[child.first])
        {
            treeWeight[child.first] = treeWeight[node] + child.second;
            DFS(child.first, visited, treeWeight);
        }
    }
}
