#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> unionArray;

// Find 함수 (경로 압축 적용)
int find(int x) {
    if (unionArray[x] != x) {
        unionArray[x] = find(unionArray[x]);
    }
    return unionArray[x];
}

// Union 함수 (Union by Rank 적용)
void union_U(int a, int b) {
    a = find(a);
    b = find(b);

    if (a != b) {
        // 작은 번호의 루트를 기준으로 병합
        if (a < b) {
            unionArray[b] = a;
        }
        else {
            unionArray[a] = b;
        }
    }
}

// 두 원소가 같은 집합에 있는지 확인
bool union_F(int a, int b) {
    return find(a) == find(b);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    unionArray.resize(N + 1);

    // 초기 유니온 배열을 자기 자신으로 초기화
    for (int i = 0; i <= N; i++) {
        unionArray[i] = i;
    }

    for (int j = 0; j < M; j++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (b > c) swap(b, c);

        if (a == 0) {
            union_U(b, c); // 집합 병합
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
