#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> minDeq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N, L;
    cin >> N >> L;

    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        while (minDeq.size() && minDeq.back().second > a)
        {
            minDeq.pop_back();
        }
        minDeq.push_back({i, a});

        if (minDeq.front().first <= i - L)
        {
            minDeq.pop_front();
        }

        cout << minDeq.front().second << " ";
    }
}