// reference
// https://www.geeksforgeeks.org/longest-common-subsequence-dp-4/

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

// Function to compute the Longest Common Subsequence (LCS) of two strings X and Y
// m and n represent the lengths of strings X and Y respectively
// dp is a 2D vector used for memoization of LCS values for subproblems
int lcs(string& X, string& Y, int m, int n, vector<vector<int> >& dp) {
    // Base case: If either of the strings is empty, LCS is 0
	if (m == 0 || n == 0)
		return 0;

    // If the last characters of both strings match
	if (X[m - 1] == Y[n - 1]) {
        // Calculate LCS for the remaining substrings and increment the length by 1
		return dp[m][n] = 1 + lcs(X, Y, m - 1, n - 1, dp);
    }

    // If the result for the current subproblem is already computed (memoized), return it
	if (dp[m][n] != -1) {
		return dp[m][n];
	}

    // If the last characters are different, recursively compute LCS by considering
    // the maximum length of LCS by excluding each character from one of the strings
	return dp[m][n] = max(lcs(X, Y, m, n - 1, dp), lcs(X, Y, m - 1, n, dp));
}


// Driver code
int main()
{
    vector<int> outlist;

    // while there is still input
    string line1, line2;
    while(true){
        getline(cin, line1);
        if(line1.empty() || cin.eof()) break;
        
        getline(cin, line2);

        stringstream ss1(line1);
        stringstream ss2(line2);

        ss1 >> line1;
        ss2 >> line2;

        int m = line1.size();
        int n = line2.size();

        vector<vector<int> > dp(m + 1, vector<int>(n + 1, -1));
        
        outlist.push_back(lcs(line1, line2, m, n, dp));
    }

	for(auto val : outlist){
        cout << val << endl;
    }

	return 0;
}
/*

Input
The input contains pairs of sequences. The first line of a pair is the first sequence and the second line contains the
second sequence. The length of each sequence is at most 1000.
Output
For each pair of input lines, output a line containing one integer: the length of the maximal subsequence that both
sequences have in common.

Example 1
Input:
bcacbcabbaccbab
bccabccbbabacbc
a1b2c3d4e
zz1yy2xx3ww4vv
abcdgh
aedfhr
abcdefghijklmnopqrstuvwxyz
a0b0c0d0e0f0g0h0i0j0k0l0m0n0o0p0q0r0s0t0u0v0w0x0y0z0
abcdefghijklmnzyxwvutsrqpo
opqrstuvwxyzabcdefghijklmn
0
0
0
1

Output:
11
4
3
26
14
1
0

note: missing one test case

*/