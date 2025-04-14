#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

int K, L;

int main()
{
    cin >> K >> L;
    queue<pair<string, int>> Q;
    unordered_map<string, int> HashT;
    int ans = 0;

    for (int i = 0; i < L; i++)
    {
        string a;
        cin >> a;
        HashT[a] = i;
        Q.push(make_pair(a, i));
    }

    while (ans < 3 && !Q.empty())
    {
        pair<string, int> data;
        data = Q.front();
        Q.pop();
        if (HashT[data.first] == data.second)
        {
            ans++;
            cout << data.first << '\n';
        }
    }
}