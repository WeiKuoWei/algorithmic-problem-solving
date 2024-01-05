#include <iostream>
#include <vector>
using namespace std;

int knapsack(int capacity, vector<int>& weights) 
{
    int n = weights.size();
    vector<vector<int> > dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) 
    {
        for (int w = 1; w <= capacity; w++) 
        {
            if (weights[i - 1] > w) 
            {
                // If the current item's weight is greater than the capacity, we cannot include it
                // So, we just take the previous item's value
                dp[i][w] = dp[i - 1][w];
            } 
            else 
            {
                // If the current item's weight is less than or equal to the
                // capacity, we can either include it or not We take the maximum
                // value between the previous item's value and the current
                // item's value + the value of the remaining capacity
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - weights[i - 1]] + weights[i - 1]);
            }
        }
        // for(int p = 0; p <= n; p++)
        // {
        //     for(int q = 0; q <= capacity; q++)
        //         cout << dp[p][q] << " ";
        //     cout << endl;
        // }
        // cout << endl;
    }

    return dp[n][capacity];
}

int main() {
    int capacity;
    cin >> capacity;

    int n;
    cin >> n;
    vector<int> weights(n);

    for (int i = 0; i < n; i++) 
    {
        cin >> weights[i];
    }

    int maxWeight = knapsack(capacity, weights);
    cout << maxWeight << endl;

    return 0;
}

/*

Example 1
Input:
5 3
1 3 4
Output:
5

Example 2
Input:
10 4
9 8 4 2
Output:
10

Example 3
Input:
20 4
10 5 7 4
Output:
19

Example 4
Input:
10
4
3
3
9
11

Output:
11 1

*/