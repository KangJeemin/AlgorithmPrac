#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int timeToMinutes(const string &t)
{
    return stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3, 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S, E, Q;
    cin >> S >> E >> Q;

    int Stime = timeToMinutes(S);
    int Etime = timeToMinutes(E);
    int Qtime = timeToMinutes(Q);

    unordered_map<string, bool> entered;
    int count = 0;
    string chattime, nickname;

    while (cin >> chattime >> nickname)
    {
        if (chattime.length() != 5 || chattime[2] != ':')
            continue;

        int Ctime = timeToMinutes(chattime);

        if (Ctime <= Stime)
        {
            entered[nickname] = true;
        }
        else if (Etime <= Ctime && Ctime <= Qtime)
        {
            if (entered[nickname])
            {
                count++;
                entered[nickname] = false;
            }
        }
    }

    cout << count << '\n';
    return 0;
}
