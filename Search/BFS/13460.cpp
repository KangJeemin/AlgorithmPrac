#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 구조체를 생성 후 , 빨,파 구슬의 x,y좌표, count 값을 갖는 5개의 변수를 갖는 구초제 생성
// BFS로 구슬의 움직임 구현
// 4차원 배열로 구슬 방문 여부 판단

// 4방향 탐색 중
// 한 방향에 대해 무한 반복문을 만든 후 배열의 끝까지 탐색
// 탐색 중 벽을 만나거나, 구멍을 만나면 탐색 멈춤
// -> 만약 멈춘 곳이 벽 떄문에 멈춘거면, -1을 취해, 벽으로의 이동을 막음

// -> 만약 멈춘 곳이 구멍 때문에 멈춘거였다면, 두 구슬이 모두 빠지는지 확인
// --> 두 구슬이 모두 빠지고, 파란 구슬이 빠진다면 조건을 만족하지 못하는 것 .
struct INFO
{
    int redX;
    int redY;
    int blueX;
    int blueY;
    int count;
};

int N, M;
INFO init;
vector<vector<char>> map;

int BFS()
{
    queue<INFO> Q;
    int visited[10][10][10][10] = {
        0,
    };

    // 동 서 남 북
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    init.count = 0;
    int ans = -1;
    Q.push(init);
    visited[init.redX][init.redY][init.blueX][init.blueY] = 1;

    while (!Q.empty())
    {
        INFO cur = Q.front();
        Q.pop();

        if (cur.count > 10)
            break;

        // 빨간 구슬만 탈출한 경우
        if (map[cur.redX][cur.redY] == 'O' && map[cur.blueX][cur.blueY] != 'O')
        {
            ans = cur.count;
            break;
        }

        for (int dir = 0; dir < 4; dir++)
        {
            int nextX = direction[dir][0];
            int nextY = direction[dir][1];
            INFO next;
            next.redX = cur.redX;
            next.redY = cur.redY;
            next.blueX = cur.blueX;
            next.blueY = cur.blueY;
            next.count = cur.count + 1;

            // 빨간 구슬
            while (true)
            {
                if (map[next.redX][next.redY] == '#' || map[next.redX][next.redY] == 'O')
                {
                    break;
                }
                next.redX += nextX;
                next.redY += nextY;
            }

            if (map[next.redX][next.redY] == '#')
            {
                next.redX -= nextX;
                next.redY -= nextY;
            }
            // 파란 구슬
            while (true)
            {
                if (map[next.blueX][next.blueY] == '#' || map[next.blueX][next.blueY] == 'O')
                {
                    break;
                }
                next.blueX += nextX;
                next.blueY += nextY;
            }

            if (map[next.blueX][next.blueY] == '#')
            {
                next.blueX -= nextX;
                next.blueY -= nextY;
            }

            // 빨간색 구슬, 파란색 구슬 모두 벽 or 구멍인 경우임
            if (next.redX == next.blueX && next.redY == next.blueY)
            {
                // 해당 곳이 벽인지, 구멍에 빠진건지 확인
                if (map[next.blueX][next.blueY] == 'O')
                {
                    // BFS 그만 돌림
                    continue;
                }
                // 벽이거나 구슬이 위치하면
                else
                {
                    // 둘다 벽이면 어떤 구슬이 후순위에 있었는지 확인
                    int red_dist = abs(cur.redX - next.redX) + abs(cur.redY - next.redY);
                    int blue_dist = abs(cur.blueX - next.blueX) + abs(cur.blueY - next.blueY);
                    // 빨간색 구슬이 후순위에 위치 해 있었건 것.
                    if (red_dist > blue_dist)
                    {
                        next.redX -= nextX;
                        next.redY -= nextY;
                    }
                    // 파란색 구슬이 후순위에 위치 해 있었건 것.
                    else if (red_dist < blue_dist)
                    {
                        next.blueX -= nextX;
                        next.blueY -= nextY;
                    }
                }
            }
            if (map[next.blueX][next.blueY] == 'O')
            {
                continue;
            }

            if (!visited[next.redX][next.redY][next.blueX][next.blueY])
            {
                visited[next.redX][next.redY][next.blueX][next.blueY] = 1;
                Q.push(next);
            }
        }
    }
    return ans;
}
int main()
{

    cin >> N >> M;
    map.resize(N, vector<char>(M, ' '));

    for (int i = 0; i < N; i++)
    {
        string a;
        cin >> a;
        for (int j = 0; j < M; j++)
        {
            if (a[j] == 'R')
            {
                init.redX = i;
                init.redY = j;
            }
            else if (a[j] == 'B')
            {
                init.blueX = i;
                init.blueY = j;
            }
            map[i][j] = a[j];
        }
    }

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int ans = BFS();
    cout << ans;

    return 0;
}