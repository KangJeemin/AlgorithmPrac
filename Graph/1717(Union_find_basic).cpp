#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> unionArray;

// Find �Լ� (��� ���� ����)
int find(int x) {
    if (unionArray[x] != x) {
        unionArray[x] = find(unionArray[x]);
    }
    return unionArray[x];
}

// Union �Լ� (Union by Rank ����)
void union_U(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        // ���� ��ȣ�� ��Ʈ�� �������� ����
        if (a < b) {
            unionArray[b] = a;
        }
        else {
            unionArray[a] = b;
        }
    }
}

// �� ���Ұ� ���� ���տ� �ִ��� Ȯ��
bool union_F(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    unionArray.resize(N + 1);

    // �ʱ� ���Ͽ� �迭�� �ڱ� �ڽ����� �ʱ�ȭ
    for (int i = 0; i <= N; i++) {
        unionArray[i] = i;
    }

    for (int j = 0; j < M; j++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > c) swap(b, c);

        if (a == 0) {
            union_U(b, c); // ���� ����
        }
        else {
            if (union_F(b, c)) {
                cout << "YES\n";
            }
            else {
                cout << "NO\n";
            }
        }
    }

    return 0;
}
