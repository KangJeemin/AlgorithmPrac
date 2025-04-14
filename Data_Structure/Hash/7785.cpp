// 해시테이블과, set을 사용하면 풀 수 있을 것 같음
#include <iostream>
#include <unordered_map>
#include <set>
#include <string>

using namespace std;

unordered_map<string, bool> HashT;

// 사전의 역순으로 저장하기
set<string, greater<string>> member;
int N;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        string a, b;
        cin >> a >> b;

        member.insert(a);
        if (b == "enter")
        {
            HashT[a] = true;
        }
        else
        {
            HashT[a] = false;
        }
    }

    for (auto iter = member.begin(); iter != member.end(); iter++)
    {
        if (HashT[*iter])
        {
            cout << *iter << '\n';
        }
    }
}
