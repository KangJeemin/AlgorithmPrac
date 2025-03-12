#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    int sum = 0;
    int count = 1;
    cin >> n;
    int startindex = 1;
    int endindex = 1;

    while (startindex < n)
    {
        if (sum > n)
        {
            sum -= startindex;
            startindex++;
        }
        else if (sum < n)
        {
            sum += endindex;
            endindex++;
        }
        else
        {
            count++;
            sum += endindex;
            endindex++;
        }
    }
    cout << count;
}