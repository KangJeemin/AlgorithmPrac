#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    int ans = 0;
    vector<pair<int, int>> V(N);

    for (int i = 0; i < N; i++)
    {
        cin >> V[i].first;
        V[i].second = i;
    }

    sort(V.begin(), V.end());

    for (int i = 0; i < N; i++)
    {
        int laterIndex = V[i].second;
        ans = max(laterIndex - i, ans);
    }

    cout << ans + 1;

    return 0;
}