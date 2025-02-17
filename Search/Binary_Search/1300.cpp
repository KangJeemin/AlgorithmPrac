#include <iostream>
#include <algorithm>

using namespace std;

// 2차원 배열에서 k번째수는 k를 넘지 못한다.
// => 2차원 배열의 1~k 번째 안에 정답이 있다.
// => 1~N^2 범위에서 이진탐색으로 정답을 구할 수 있다.

// 2차원 배열에서 기준 값보다 작거나 같은 개수 구하기

// 최초의 중앙값은 4 이며, 각 행에서 중앙값보다 작거나 같은 수의 개수는 중앙값을 각 행의 첫 번째 값으로 나눈 값이다.
// 1의 배수형태 --> 1 2 3 -- > 4/1 = 4 이지만 한 행의 크기가 3이므로 3개
// 2의 배수형태 --> 2 4 6 -- > 4/2 = 2
// 3의 배수형태 --> 3 6 9 -- > 4/3 = 1
// 4보다 작거나 같은 개수 => 3 + 2 + 1 =6

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