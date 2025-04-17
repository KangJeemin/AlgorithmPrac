#include <iostream>
#include <vector>

using namespace std;
vector<int> parent;
static int N, M;

int find(int node);

bool unionset(int a, int b);
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    parent.resize(N + 1, 0);

    int cutcount = 0;

    // 자기 자신으로 초기화
    for (int i = 1; i <= N; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        // 사이클이 발견되어 잘라야하는 경우
        if (!unionset(a, b))
            cutcount++;
    }
    // 연결 요소 개수 세기
    int components = 0;
    for (int i = 1; i <= N; i++)
    {
        if (find(i) == i)
            components++;
    }

    int add = components - 1; // 이어야 하는 간선 수
    cout << add + cutcount;
}

int find(int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    parent[node] = find(parent[node]);
    return parent[node];
}
bool unionset(int a, int b)
{
    int pa = find(a);
    int pb = find(b);

    // 사이클 발견
    if (pa == pb)
        return false;

    if (pa > pb)
    {
        parent[pb] = pa;
    }
    else
    {
        parent[pa] = pb;
    }
    return true;
}