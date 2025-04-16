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
    {
        return;
    }
    visitRootNode.push_back(node);
    for (int child : Tree[node])
    {
        inorder(child);
    }
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
    while (cur != lastNode)
    {
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