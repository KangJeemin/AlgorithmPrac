#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>

using namespace std;

string S, E, Q;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    unordered_map<string, bool> HashT;
    int count = 0;

    cin >> S >> E >> Q;
    int Shour = stoi(string(1, S[0]) + string(1, S[1]));
    int SMinute = stoi(string(1, S[3]) + string(1, S[4]));
    int Stime = 60 * Shour + SMinute;
    int Ehour = stoi(string(1, E[0]) + string(1, E[1]));
    int EMinute = stoi(string(1, E[3]) + string(1, E[4]));
    int Etime = 60 * Ehour + EMinute;
    int Qhour = stoi(string(1, Q[0]) + string(1, Q[1]));
    int QMinute = stoi(string(1, Q[3]) + string(1, Q[4]));
    int Qtime = 60 * Qhour + QMinute;
    string chatTime;
    string nickname;
    while (cin >> chatTime >> nickname)
    {

        int Chour = stoi(string(1, chatTime[0]) + string(1, chatTime[1]));
        int CMinute = stoi(string(1, chatTime[3]) + string(1, chatTime[4]));
        int Ctime = 60 * Chour + CMinute;

        // chattim이 Q보다 크면 반복문 종료
        if (Ctime > Qtime)
        {
            break;
        }

        if (Ctime <= Stime)
        {
            HashT[nickname] = true;
        }

        // chatime이 E<=Q인 경우 출석처리
        // 이전에 채팅한 이력이 S<=E 사이에 유효한 채팅한 이력이 있으면 출석처리
        if (Etime <= Ctime && Ctime <= Qtime)
        {
            if (HashT[nickname])
            {
                count++;
                HashT[nickname] = false;
            }

            // cout << "nickname =" << nickname << '\n';
        }
    }
    cout << count;
}