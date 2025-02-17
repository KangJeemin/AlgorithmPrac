#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> V;

void init()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        V.push_back(a);
    }
}

void quickSort(int left, int right)
{
    int pl = left;
    int pr = right;
    // 피벗은 배열 중 어떤 값으로 선정하던 상관 없음
    int pibut = V[(pl + pr) / 2];

    // pl 이 pr을 역전하면 종료
    do
    {
        while (V[pl] < pibut)
            pl++;
        while (V[pr] > pibut)
            pr--;

        if (pl <= pr)
        {
            swap(V[pl], V[pr]);
            pl++;
            pr--;
        }
    } while (pl <= pr);

    if (left < pr)
    {
        quickSort(left, pr);
    }
    if (pl < right)
    {
        quickSort(pl, right);
    }
}

int main(int argc, char **argv)
{
    init();
    quickSort(0, N - 1);

    for (int i = 0; i < V.size(); i++)
    {
        cout << V[i] << " ";
    }

    return 0;
}