#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef pair<int, int> Location;

vector<vector<int>> map(4, vector<int>(4, 0));
vector<pair<Location, int>> fisihesV(17);
pair<Location, int> shark;
int ans;

// 2차원 map 백터를 선언하고, 이 백터는 상어의 정보를 갖고 있다.
// 상어를 순서대로 이동시켜야 하기 떄문에, 상어의 위치, 방향을 갖고 있을 백터를 선언한다.

// DFS 함수 (2차원 백터, 상어 위치, 합).
// 상어가 물고기를 잡아 먹고, 해당 물고기 값 만큼 값을 더한다
// 물고기를 이동시킨다.

// 3방향 탐색으로 상어가 갈 수 있는 방향에 대한 DFS를 진행한다.

// 만약 상어가 이동할 수 없다면 (해당 위치에서 물고기가 이미 잡아 먹혔거나, 범위를 벗어난다면 ) 이동하지 않는다

// DFS() 시간 복잡도
// 4*3^15 = 1초안에 해결가능
// O()
//

int directionX[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int directionY[8] = {0, -1, -1, -1, 0, 1, 1, 1};

void DFS(vector<vector<int>> Newmap, pair<Location, int> Newshark, int sum, vector<pair<Location, int>> fisihesV);

void init()
{
    ans = 0;
    shark = {{0, 0}, 0};
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a, b;
            cin >> a >> b;
            fisihesV[a] = {{i, j}, b - 1};
            map[i][j] = a;
        }
    }
}
int main(int argc, char **argv)
{
    init();
    DFS(map, shark, 0, fisihesV);
    cout << ans;
    return 0;
}

void DFS(vector<vector<int>> Newmap, pair<Location, int> Newshark, int sum, vector<pair<Location, int>> fisihesV)
{
    vector<vector<int>> Newmap2 = Newmap;
    int sharkX = Newshark.first.first;
    int sharkY = Newshark.first.second;
    int sharkD = Newshark.second;

    if ((sharkX < 0 || sharkX >= 4 || sharkY < 0 || sharkX >= 4) || Newmap2[sharkX][sharkY] == 0)
    {
        return;
    }

    int fishNum = Newmap2[sharkX][sharkY];
    int fishD = fisihesV[fishNum].second;
    sharkD = fishD;
    ans = max(ans, sum + fishNum);

    fisihesV[fishNum].second = -1;
    Newmap2[sharkX][sharkY] = 0;

    // 물고기 이동
    for (int i = 1; i <= 16; i++)
    {
        int movefishX = fisihesV[i].first.first;
        int movefishY = fisihesV[i].first.second;
        int movefishD = fisihesV[i].second;

        // 만약 해당 물고기가 이미 잡아먹힌 경우 건너뜀
        if (movefishD == -1)
            continue;
        for (int j = 0; j < 8; j++)
        {
            int findfishX = movefishX + directionX[movefishD];
            int findfishY = movefishY + directionY[movefishD];
            // 상어가 있거나, 맵 밖으로 벗어나는 경우에는, 방향을 회전함
            if ((findfishX == sharkX && findfishY == sharkY) || (findfishX < 0 || findfishX >= 4 || findfishY < 0 || findfishY >= 4))
            {
                movefishD = (movefishD + 1) % 8;
                continue;
            }
            // 상어가 없거나 맵 안에 유요한 경우에는 위치 바꿈
            else
            {
                int tryfish = Newmap2[movefishX][movefishY];
                int detectedfish = Newmap2[findfishX][findfishY];

                fisihesV[tryfish] = {{findfishX, findfishY}, movefishD};
                fisihesV[detectedfish].first = {movefishX, movefishY};

                Newmap2[movefishX][movefishY] = detectedfish;
                Newmap2[findfishX][findfishY] = tryfish;
                break;
            }
        }
        // 만약 물고기가 이동할 수 없으면, 이동하지 않음.
    }
    // for (int i = 0; i < 4; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //     {
    //         cout << Newmap[i][j] << " ";
    //     }
    //     cout << '\n';
    // }

    // 상어 이동 DFS

    for (int dir = 1; dir <= 3; dir++)
    {
        int dx = sharkX + directionX[sharkD] * dir;
        int dy = sharkY + directionY[sharkD] * dir;
        if ((dx < 0 || dx >= 4 || dy < 0 || dy >= 4) || Newmap2[dx][dy] == 0)
        {
            continue;
        }
        pair<Location, int> nshark = {{dx, dy}, sharkD};
        DFS(Newmap2, nshark, sum + fishNum, fisihesV);
    }
}