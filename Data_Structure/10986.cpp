// 누적합과 모듈러 연산을 이용하여 문제를 해결한다.

#include <iostream>
#include <vector>

using namespace std;

int N, M;

vector<long> sum;
vector<long> mod;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> M;
    long ans = 0;
    sum.resize(N + 1, 0);
    mod.resize(M, 0);

    for (int i = 1; i <= N; i++)
    {
        int a;
        cin >> a;
        sum[i] = sum[i - 1] + a;
    }
    for (int i = 1; i <= N; i++)
    {
        int sumMod = sum[i] % M;
        if (sumMod == 0)
            ans++;
        mod[sumMod]++;
    }

    for (int i = 0; i < M; i++)
    {
        if (mod[i] > 1)
        {
            ans += (mod[i] * (mod[i] - 1)) / 2;
        }
    }

    cout << ans;
    return 0;
}