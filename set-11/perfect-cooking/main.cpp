// reference
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

// int lcs(string& X, string& Y, int m, int n, vector<vector<int> >& dp)
// {
// 	if (m == 0 || n == 0)
// 		return 0;
// 	if (X[m - 1] == Y[n - 1])
// 		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);

// 	if (dp[m][n] != -1) {
// 		return dp[m][n];
// 	}
// 	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
// }


int editDistance(const string& x, const string& y, int m, int n) {
    // Create a 2D vector for memoization
    vector<vector<int> > dp(m + 1, vector<int>(n + 1));

    // Initialize base cases and dynamic programming table
    for (int i = 0; i <= m; ++i) { // Loop through string x
        for (int j = 0; j <= n; ++j) { // Loop through string y
            if (i == 0) {
                dp[i][j] = j; // If x is empty, the distance is the length of y (edit(-1,j) = j)
            } else if (j == 0) {
                dp[i][j] = i; // If y is empty, the distance is the length of x (edit(i,-1) = i)
            } else if (x[i - 1] == y[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // No cost if characters match, take diagonal value
            } else {
                // Calculate the cost for different operations and choose the minimum
                dp[i][j] = 1 + min(dp[i][j - 1], min(dp[i - 1][j], dp[i - 1][j - 1]));
                // 1 is added because there's a mismatch, and we choose the minimum among insertion, deletion, or replacement
            }
        }
    }

    return dp[m][n]; // Return the edit distance for x and y
}


// Driver code
int main()
{
    string line1, line2;
    string x, y;
    int m, n;
    getline(cin, line1);
    getline(cin, line2);

    stringstream ss1(line1);
    stringstream ss2(line2);

    ss1 >> m >> x;
    ss2 >> n >> y;

    int distance = editDistance(x, y, m, n);
    cout << distance << endl;

	// vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
    
    // int temp = min(m, n);
    // cout << temp - lcs(line1, line2, m, n, dp) + abs(m - n) << endl;

	return 0;
}

/*

// consider the case of changing a step

Example 1
Input:
5 ABCDE
4 ABDE
Output:
1

Example 2
Input:
3 TGZ
8 ACGTTGGC
Output:
7

Example 3
Input:
3 TGZ
3 TGZ

Output:
0

Example 4
Input:
90 TGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZABC
93 TGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZTGZ

Output:
6

Example 5
Input:
5 ABCDE
6 ABXYEF

Output:
3 

*/
