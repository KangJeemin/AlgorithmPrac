#include <iostream>
using namespace std;
#define max 100000

int tree[max][2];
int N;
int ans = 0;
void inOrder(int node);
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        tree[a][0] = b;
        tree[a][1] = c;
    }
    inOrder(1);

    cout << ans;
}
void inOrder(int node)
{
    if (node == -1)
        return;
    ans++;

    // 재귀를 끝내고 부모 노드로 다시 돌아갈때 , 이동수를 증가 ?
    // => 우측방문 하는 경우는 최하단 에 접근했을떄 끝내야함
    inOrder(tree[node][0]);
    // inOrder(tree[node][1]);

    // 되돌아가는 수 증가
    ans++;
}