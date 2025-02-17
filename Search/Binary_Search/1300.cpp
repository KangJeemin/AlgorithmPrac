#include <iostream>
#include <algorithm>

using namespace std;

long N, K;

long binarySearch(int target)
{
    long left = 1;
    long right = N * N;

    while (left <= right)
    {
        long mid = (left + right) / 2;
        int count = 0;

        for (long i = 1; i <= N; i++)
        {
            count += min(N, mid / i);
        }

        if (target <= count)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return left;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N >> K;
    cout << binarySearch(K);

    return 0;
}