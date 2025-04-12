#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int dp[100001][5][5];

int main()
{
    int DDRButton;
    int count = 1;
    int mp[5][5] = {{0, 2, 2, 2, 2}, {2, 1, 3, 4, 3}, {2, 3, 1, 3, 4}, {2, 4, 3, 1, 3}, {2, 3, 4, 3, 1}};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k <= 100000; k++)
            {
                dp[k][i][j] = 100001 * 4;
            }
        }
    }

    dp[0][0][0] = 0;
    while (true)
    {
        cin >> DDRButton;
        if (DDRButton == 0)
            break;

        // 오른발 이동
        for (int i = 0; i < 5; i++)
        {
            if (i == DDRButton)
                continue;
            for (int j = 0; j < 5; j++)
            {
                dp[count][i][DDRButton] = min(dp[count][i][DDRButton], dp[count - 1][i][j] + mp[j][DDRButton]);
            }
        }
        // 왼발 이동
        for (int i = 0; i < 5; i++)
        {
            if (i == DDRButton)
                continue;
            for (int j = 0; j < 5; j++)
            {
                dp[count][DDRButton][i] = min(dp[count][DDRButton][i], dp[count - 1][j][i] + mp[j][DDRButton]);
            }
        }
        count++;
    }
    count--;
    int minVal = INT_MAX;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            minVal = min(minVal, dp[count][i][j]);
        }
    }

    cout << minVal;
}
