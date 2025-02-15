// 투포인터이용

#include <iostream>
#include <vector>
using namespace std;

void merge_sort(int start, int end);
static vector<int> A;
static vector<int> tmp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    A = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    merge_sort(1, N);

    for (int i = 1; i <= N; i++)
    {
        cout << A[i] << '\n';
    }
}

void merge_sort(int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    // int mid = (start + end) / 2 의 오버플로우를 방지하기 위해 위와 같이 작성.

    // 재귀 함수 형태로 구현

    merge_sort(start, mid);
    merge_sort(mid + 1, end);

    for (int i = start; i <= end; i++)
    {
        tmp[i] = A[i];
    }

    int k = start;
    int pointer1 = start;
    int pointer2 = mid + 1;

    // 두 그룹을 병합
    while (pointer1 <= mid && pointer2 <= end)
    {
        if (tmp[pointer1] > tmp[pointer2])
        {
            A[k] = tmp[pointer2];
            k++;
            pointer2++;
        }
        else
        {
            A[k] = tmp[pointer1];
            k++;
            pointer1++;
        }
    }

    // 한쪽 그룹이 모두 선택된 후 남아있는 값 정리하기
    while (pointer1 <= mid)
    {
        A[k] = tmp[pointer1];
        k++;
        pointer1++;
    }
    while (pointer2 <= end)
    {
        A[k] = tmp[pointer2];
        k++;
        pointer2++;
    }
}