#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
int LtoR[100001] = {
    0,
};
int RtoL[100003] = {
    0,
};

int inputArray[100001] = {
    0,
};

int main()
{
    int N;
    cin >> N;
    int ans;
    for (int i = 1; i <= N; i++)
    {
        cin >> inputArray[i];
    }

    LtoR[1] = inputArray[1];
    ans = inputArray[1];
    RtoL[N] = inputArray[N];

    // 주어진 수열에서 1번인덱스 부터 끝 인덱스까지 수열의 최대 합 조사하기
    for (int i = 2; i <= N; i++)
    {
        // 내가 이걸 떠올리지 못했음
        LtoR[i] = max(LtoR[i - 1] + inputArray[i], inputArray[i]);
        ans = max(LtoR[i], ans);
    }
    // 주어진 수열의 끝 부터 1번 인덱스까지 역으로 수열의 최대 합 조사하기
    for (int i = N - 1; i >= 1; i--)
    {
        RtoL[i] = max(RtoL[i + 1] + inputArray[i], inputArray[i]);
    }

    for (int i = 1; i <= N - 1; i++)
    {

        ans = max(LtoR[i] + RtoL[i + 2], ans);
    }
    cout << ans;
    return 0;
}