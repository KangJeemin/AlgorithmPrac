#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// "연속된 소수의 합으로 N값을 만들 수 있는 지 확인하는 문제"
// 연속된 소수로 출력할 수 없으면 0을 출력한다

// 투포인터 + 에라토스체

vector<bool> odd;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    odd.resize(N + 1, false);
    int startindex = 0;
    int endindex = 0;
    int sum = 0;
    int count = 0;
    odd[0] = true;
    odd[1] = true;

    // 에라토스체로 소수 구하기 시간복잡도 = O(Nlog*logN)
    for (int i = 2; i <= sqrt(N); i++)
    {
        for (int j = i * i; j <= N; j += i)
        {
            if (!odd[j])
            {
                odd[j] = true;
            }
        }
    }

    // 슬라이딩 윈도우
    while (startindex <= endindex && endindex <= N)
    {
        // startindex 증가시키기
        if (sum >= N)
        {
            // 조건에 만족한 경우
            if (sum == N)
            {
                count++;
            }

            int nextindex = startindex;
            // 다음으로 설정될 소수 찾기
            while (true)
            {
                nextindex++;
                if (nextindex > N || !odd[nextindex])
                {
                    break;
                }
            }
            if (nextindex > N)
                break;
            sum -= nextindex;
            startindex = nextindex;
        }
        // endindex 증가시키기
        else
        {
            int nextindex = endindex;
            // 다음으로 설정될 소수 찾기
            while (true)
            {
                nextindex++;
                if (nextindex > N || !odd[nextindex])
                {
                    break;
                }
            }
            if (nextindex > N)
                break;
            endindex = nextindex;
            sum += endindex;
        }
    }

    // for (int i = 0; i <= N; i++)
    // {
    //     cout << odd[i];
    // }

    cout << count;
}