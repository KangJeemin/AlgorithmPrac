#include <iostream>
#include <vector>
#include <queue>

using namespace std;
vector<int> Tree[1000001];
vector<int> visited;
int N, M;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    visited.resize(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        Tree[a].push_back(b);
    }

    // 덩어리 트리 만들기
    int group = 1;
    int cutcount = 0;
    for (int i = 1; i <= N; i++)
    {

        if (!visited[i])
        {
            queue<int> Q;
            Q.push(i);
            visited[i] = group;
            while (!Q.empty())
            {
                int node = Q.front();
                Q.pop();

                for (int child : Tree[node])
                {
                    if (!visited[child])
                    {
                        Q.push(child);
                        visited[child] = group;
                    }
                    else
                    {
                        cutcount++;
                    }
                }
            }
            group++;
        }
    }

    cout << group - 2 + cutcount;
}