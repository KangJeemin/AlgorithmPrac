#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main() {
    vector<vector<long>> map;

    int N, M;
    cin >> N >> M;
    map.resize(N, vector<long>(N, LONG_MAX));

    for (int i = 0;i < N;i++) {
        map[i][i] = 0;
    }

    for (int i = 0;i < M;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        if (map[a - 1][b - 1] > c) {
            map[a - 1][b - 1] = c;
        }
    }
    for (int k = 0;k < N;k++) {
        for (int i = 0;i < N;i++) {
            for (int j = 0;j < N;j++) {
                if (map[i][k] != LONG_MAX && map[k][j] != LONG_MAX) { // 오버플로우 방지 조건
                    if (map[i][j] > map[i][k] + map[k][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }

            }
        }
    }

    for (int i = 0;i < N;i++) {
        for (int j = 0;j < N;j++) {
            if (map[i][j] == LONG_MAX) {
                cout << 0 << " ";
            }
            else {
                cout << map[i][j] << " ";
            }
        }
        cout << '\n';
    }




    return 0;
}