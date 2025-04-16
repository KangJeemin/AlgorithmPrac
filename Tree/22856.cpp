#include <iostream>
#include <vector>
#define max 100001

using namespace std;

int N;
vector<int> Tree[max];
vector<int> visitRootNode;
vector<bool> visited;
vector<int> parentNode;
int ans = 0;

// 마지막 방문 노드를 알아내기 위함
void inorder(int node)
{
    if (node == -1)
        return;
    inorder(Tree[node][0]);        // 왼쪽
    visitRootNode.push_back(node); // 루트
    inorder(Tree[node][1]);        // 오른쪽
}

int main()
{
    cin >> N;
    visited.resize(N + 1, false);
    parentNode.resize(N + 1, 0);
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Tree[a].push_back(b);
        Tree[a].push_back(c);
        parentNode[b] = a;
        parentNode[c] = a;
    }

    inorder(1);
    int lastNode = visitRootNode.back();

    int cur = 1;
    visited[cur] = true;
    // 마지막 노드에 도달했을때, 바로 종료하면 안됨
    // while(cur==lastNode)
    while (true)
    {
        // 종료 조건: 현재 노드가 마지막 노드이고 더 이상 이동할 자식이 없을 때
        if (cur == lastNode &&
            (Tree[cur][0] == -1 || visited[Tree[cur][0]]) &&
            (Tree[cur][1] == -1 || visited[Tree[cur][1]]))
        {
            break;
        }

        if (!visited[Tree[cur][0]] && Tree[cur][0] != -1)
        {
            cur = Tree[cur][0];
        }
        else if (!visited[Tree[cur][1]] && Tree[cur][1] != -1)
        {

            cur = Tree[cur][1];
        }
        else
        {
            cur = parentNode[cur];
        }
        ans++;
        visited[cur] = true;
    }

    cout << ans;
}