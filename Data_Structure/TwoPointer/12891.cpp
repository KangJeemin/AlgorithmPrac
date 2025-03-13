#include <iostream>
using namespace std;
vector<string> inputArray;
vector<int> checkArr;
vector<int> checkArr2;

int main()
{
    int S, P;
    int ans = 0;
    inputArray.resize(1);
    checkArr.resize(4, 0);
    checkArr2.resize(4, 0);

    cin >> S >> P;
    cin >> inputArray[0];
    cin >> checkArr[0] >> checkArr[1] >> checkArr[2] >> checkArr[3];

    for (int i = 0; i < P; i++)
    {
        if (inputArray[0][i] == 'A')
        {
            checkArr2[0]++;
        }
        else if (inputArray[0][i] == 'C')
        {
            checkArr2[1]++;
        }
        else if (inputArray[0][i] == 'G')
        {
            checkArr2[2]++;
        }
        else
        {
            checkArr2[3]++;
        }
    }

    bool isok = true;
    // 초기값 계산
    for (int i = 0; i < 4; i++)
    {
        if (checkArr2[i] < checkArr[i])
        {
            isok = false;
            break;
        }
    }
    if (isok)
    {
        ans++;
    }
    int startindex = 0;
    int endindex = P - 1;

    while (endindex < S - 1)
    {
        if (inputArray[0][startindex] == 'A')
        {
            checkArr2[0]--;
        }
        else if (inputArray[0][startindex] == 'C')
        {
            checkArr2[1]--;
        }
        else if (inputArray[0][startindex] == 'G')
        {
            checkArr2[2]--;
        }
        else
        {
            checkArr2[3]--;
        }
        startindex++;
        endindex++;
        if (inputArray[0][endindex] == 'A')
        {
            checkArr2[0]++;
        }
        else if (inputArray[0][endindex] == 'C')
        {
            checkArr2[1]++;
        }
        else if (inputArray[0][endindex] == 'G')
        {
            checkArr2[2]++;
        }
        else
        {
            checkArr2[3]++;
        }
        isok = true;
        for (int i = 0; i < 4; i++)
        {
            if (checkArr2[i] < checkArr[i])
            {
                isok = false;
                break;
            }
        }
        if (isok)
        {
            ans++;
        }
    }

    cout << ans;
}