#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w, n;
    cin >> w >> n;

    vector<int> weights(n);
    for (int i = 0; i < n; i++)
    {
        cin >> weights[i];
    }

    // sort the weights
    sort(weights.begin(), weights.end());

    for(int i = 0; i < n; i++)
    {
        if(weights[i] > w)
        {
            cout << i;
            return 0;
        }
        w -= weights[i];
    }
    cout << n;

    return 0;
}

/*

Input
First two lines contains 0<=W<=10ˆ8 and 0<=N<=10ˆ5 as described above. The net line contains N weights of the
dancing hippos, 0<=w_i<=10ˆ8.
Output
Maximum number of hippos that can be safely placed on the platform.
Example 1
Input
50
4
76 56 64 69
Output
0
Example 2
Input
150
7
45 32 78 56 22 63 37
Output
4
Example 3
Input
10000
10
87 21 15 43 60 61 71 57 79 20
Output
10



*/