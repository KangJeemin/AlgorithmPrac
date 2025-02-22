#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> time(N + 1, 0);
    vector<int> step(N + 1, 0);
    vector<vector<int>> ArrayVector(N + 1);
    vector<int> resultTime(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        int a, b;
        cin >> a;
        time[i] = a;
        while (true)
        {
            cin >> b;
            if (b == -1)
                break;
            ArrayVector[b].push_back(i);
            step[i]++;
        }
    }

    queue<int> Q; // 위상정렬 수행

    // 진입 차수 만들기
    for (int i = 1; i <= N; i++)
    {
        if (step[i] == 0)
        {
            Q.push(i);
            resultTime[i] = time[i];
        }
    }

    while (!Q.empty())
    {
        // 생각해보니 다음단계를 실행하기 전처리에서, 다음단계의 최대시간을 구해야함
        int now = Q.front();
        Q.pop();

        for (int next : ArrayVector[now])
        {
            step[next]--;
            resultTime[next] = max(resultTime[next], resultTime[now] + time[next]);
            if (step[next] == 0)
            {
                Q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++)
    {
        cout << resultTime[i] << '\n';
    }

    return 0;
}