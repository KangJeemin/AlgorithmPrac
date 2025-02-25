#include <iostream>
#include <vector>
#include <climits>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
static int N, M;
static vector<long> mdistance;
static vector<edge> edges;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    mdistance.resize(N + 1);
    fill(mdistance.begin(), mdistance.end(), INT_MAX); // 최단 거리 배열 초기화

    for (int i = 0; i < M; i++)
    {
        int start, end, time;
        cin >> start >> end >> time;
        edges.push_back(make_tuple(start, end, time));
    }

    mdistance[1] = 0;

    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int time = get<2>(medge);

            // 더 가까운 최단 거리가 있다면 갱신
            if (mdistance[start] != INT_MAX && mdistance[end] > mdistance[start] + time)
            {
                mdistance[end] = mdistance[start] + time;
            }
        }
    }

    bool mCycle = false;

    for (int i = 0; i < M; i++)
    {
        edge medge = edges[i];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int time = get<2>(medge);

        if (mdistance[start] != INT_MAX && mdistance[end] > mdistance[start] + time)
        {
            mCycle = true;
        }
    }

    if (!mCycle)
    {
        for (int i = 2; i <= N; i++)
        {
            if (mdistance[i] == INT_MAX)
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << mdistance[i] << '\n';
            }
        }
    }
    else
    {
        cout << -1 << '\n';
    }
}