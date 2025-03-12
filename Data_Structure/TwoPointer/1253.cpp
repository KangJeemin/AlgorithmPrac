#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<long> inputArray;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N;
    cin >> N;
    inputArray.resize(N, 0);
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> inputArray[i];
    }

    sort(inputArray.begin(), inputArray.end());

    for (int i = 0; i < N; i++)
    {
        int startindex = 0;
        int endindex = N - 1;

        while (startindex < endindex)
        {
            if ((inputArray[startindex] + inputArray[endindex]) > inputArray[i])
            {
                endindex--;
            }
            else if ((inputArray[startindex] + inputArray[endindex]) < inputArray[i])
            {
                startindex++;
            }
            else
            {
                if (startindex == i || endindex == i)
                {
                    if (startindex == i)
                    {
                        startindex++;
                        continue;
                    }
                    else if (endindex == i)
                    {
                        endindex--;
                        continue;
                    }
                }
                // 좋은 수
                count++;
                break;
            }
        }
    }
    cout << count;
}