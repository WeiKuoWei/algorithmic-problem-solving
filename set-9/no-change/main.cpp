#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>

using namespace std;

int knapsack(int max_capacity, int capacity, vector<int> weights, unordered_map<int, int>& coins_used)
{
    int n = weights.size();
    vector<vector<int> > dp(n+1, vector<int>(max_capacity+1, 0));

    int current_capacity = max_capacity;
    for(int i = 1; i <= n; i++)
    {
        // if the weight is greater than the max_capacity, no need to continue
        if(weights[i - 1] > max_capacity)
        {
            break;
        }

        int num = 0;
        for(int w = 1; w <= max_capacity; w++)
        {
            if(weights[i-1] > w)
            {
                dp[i][w] = dp[i-1][w];
            }
            else
            {
                if(dp[i-1][w-weights[i-1]] + weights[i-1] >= dp[i-1][w])
                {
                    dp[i][w] = dp[i-1][w-weights[i-1]] + weights[i-1];
                    if(dp[i][w] != num)
                    {
                        num = dp[i][w];
                        coins_used[num] = min(coins_used[num - weights[i-1]] + coins_used[weights[i-1]], coins_used[num]);
                    }
                }
                else
                {
                    dp[i][w] = dp[i-1][w];
                }
            }
            if(dp[i][w] >= capacity)
            {
                if(abs(current_capacity - capacity) >= abs(dp[i][w] - capacity))
                {
                    current_capacity = dp[i][w]; 
                }
            }
        }
    }
    return current_capacity;
}

int main() {
    int capacity;
    cin >> capacity;

    int n;
    cin >> n;
    vector<int> weights(n);
    unordered_map<int, int> coins_used;
    coins_used[0] = 0;

    for (int i = 0; i < n; i++) 
    {
        cin >> weights[i];
        coins_used[weights[i]] = 1;
    }

    // sort weights and initialize max_capacity
    sort(weights.begin(), weights.end());
    int max_capacity = 0;
    for(auto val: weights)
    {
        if(max_capacity >= capacity)
        {
            break;
        }
        max_capacity += val;
    }

    // initialize the coins_used map 
    for(int i = 1; i <= max_capacity; i++)
    {
        if(coins_used.find(i) == coins_used.end())
        {
            coins_used[i] = max_capacity;
        }
    }

    int result = knapsack(max_capacity, capacity, weights, coins_used);

    cout << result << " " << coins_used[result] << endl;

    return 0;
}

/*

Input
The first line contains one positive integer M, the price of the garage kit. The price will not exceed 10,000.
The following line contains one positive integer N, the number of coins Chad has, N <= 100.
The next N lines contain positive integers indicating the value of each coin that Chad has. The values are any
positive integers no greater than 10,000.
Chad has brought enough money to buy the kit, so the total value of his coins will always be equal to or greater
than the price of the kit.

Output
Output a single line containing two integers: the total amount paid and the total number of coins used.

Example 1
Input:
14
3
5
10
20
Output:
15 2

Example 2
Input:
5
3
2
3
5
Output:
5 1

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

Example 5
Input:
10
5
1
2
3
4
6

Output:
10 2

Example 6
Input:
20 7
1 3 5 7 9 10 15

Output:
20 2 

Example 7
Input:
1 1
1

Output:
1 1

*/