#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> V;
vector<int> edgedistance;
int N;
int BFS(int node);
void init()
{
    cin >> N;
    V.resize(N + 1);
    edgedistance.resize(N + 1);

    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a;
        while (true)
        {
            cin >> b;
            if (b == -1)
            {
                break;
            }
            cin >> c;
            V[a].push_back({ b, c });
        }
    }
}

int BFS(int node)
{
    queue<edge> myqueue;
    vector<bool> visited(N + 1, false);
    int startpoint = node;
    int checkdistance = 0;

    myqueue.push({ node, 0 });
    visited[node] = true;
    edgedistance[node] = 0;
    while (!myqueue.empty())
    {
        int mnode = myqueue.front().first;
        int mdistance = myqueue.front().second;
        myqueue.pop();

        if (checkdistance < mdistance)
        {
            startpoint = mnode;
            checkdistance = mdistance;
        }

        for (edge i : V[mnode])
        {
            if (visited[i.first])
                continue;
            visited[i.first] = true;
            int nextnode = i.first;
            int nextdistance = i.second + mdistance;
            edgedistance[nextnode] = nextdistance;
            myqueue.push({ nextnode, nextdistance });
        }
    }

    return startpoint;
}

int main()
{
    init();
    int findstart = BFS(1);
    fill(edgedistance.begin(), edgedistance.end(), 0);
    int findlongestpoint = BFS(findstart);

    cout << edgedistance[findlongestpoint];

    return 0;
}