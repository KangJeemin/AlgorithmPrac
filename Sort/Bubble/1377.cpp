#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int N;
    int ans = 0;
    vector<int> V;
    cin >> N;
    V.resize(N + 1, 0);

    for (int i = 1; i < N + 1; i++)
    {
        cin >> V[i];
    }

    // 원래의 배열과, 정렬 후의 배열간의 인덱스 차이를 이용해 답을 구할 것임
    vector<int> V1 = V;

    sort(V.begin(), V.end());

    for (int i = 1; i < N + 1; i++)
    {

        int laterIndex = lower_bound(V.begin(), V.end(), V1[i]) - V.begin();
        int indexGap = i - laterIndex;
        ans = max(ans, indexGap);
    }

    cout << ans + 1;

    return 0;
}