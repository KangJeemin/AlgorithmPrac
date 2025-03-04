#include <iostream>
#include <vector>
#include <tuple>
#include <climits>
#include <algorithm>
using namespace std;

typedef tuple<int, int, int> edge;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, start, end, M;
    vector<edge> edges;
    vector<int> makeMoney;
    vector<int> mMoney;
    cin >> N >> start >> end >> M;
    edges.resize(M);
    makeMoney.resize(N);
    mMoney.resize(N);
    fill(mMoney.begin(), mMoney.end(), INT_MAX);

    // 간선 입력 받기
    for (int i = 0; i < M; i++)
    {
        int start, end, distance;
        cin >> start >> end >> distance;
        edges[i] = make_tuple(start, end, distance);
    }
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        a = a * -1;
        makeMoney[i] = a;
    }

    mMoney[start] = makeMoney[start];
    // 시작 위치

    for (int i = 0; i < N - 1; i++)
    {
        for (int j = 0; j < M; j++)
        {
            edge medge = edges[j];
            int start = get<0>(medge);
            int end = get<1>(medge);
            int distance = get<2>(medge);
            if (mMoney[start] != INT_MAX && mMoney[end] > mMoney[start] + distance + makeMoney[end])
            {
                mMoney[end] = mMoney[start] + distance + makeMoney[end];
            }
        }
    }
    bool isGee = false;
    for (int j = 0; j < M; j++)
    {
        edge medge = edges[j];
        int start = get<0>(medge);
        int end = get<1>(medge);
        int distance = get<2>(medge);
        if (mMoney[end] > mMoney[start] + distance + makeMoney[end])
        {
            isGee = true;
        }
    }
    if (mMoney[end] == INT_MAX)
    {
        cout << "gg";
        return 0;
    }
    if (isGee)
    {
        cout << "Gee";
        return 0;
    }

    cout << mMoney[end] * -1;
    return 0;
}