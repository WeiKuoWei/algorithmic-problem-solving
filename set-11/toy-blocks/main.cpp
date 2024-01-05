#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int helper(vector<int>& v, int sum1, int sum2, int n1, int n2, int n, int idx) {
    if (idx > n - 1) {
        return abs(sum1 - sum2);
    }

    int l = INT_MAX;
    int r = INT_MAX;

    if ((n % 2 != 0 && n1 <= n / 2) || (n % 2 == 0 && n1 < n / 2)) {
        l = helper(v, sum1 + v[idx], sum2, n1 + 1, n2, n, idx + 1);
    }

    if ((n % 2 != 0 && n2 <= n / 2) || (n % 2 == 0 && n2 < n / 2)) {
        r = helper(v, sum1, sum2 + v[idx], n1, n2 + 1, n, idx + 1);
    }

    return min(l, r);
}

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int diff = helper(v, 0, 0, 0, 0, n, 0);
    int ans2 = (sum + diff) / 2;
    int ans1 = sum - ans2;

    cout << ans1 << " " << ans2 << endl;

    // cout << "Minimum absolute difference between subset sums: " << minAbsoluteDiff << endl;

    return 0;
}

/*

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }

    int diff = calculateDifference(v, n);
    int ans2 = (sum + diff) / 2;
    int ans1 = sum - ans2;

    cout << ans1 << " " << ans2 << endl;

    return 0;
}


*/


/*

Input
The first line of the input contains one integer N (1 <= N <= 100), the number of toy blocks. Each of the following
N lines contains one integer indicating the height h (1 <= h <= 450) of that block.
Output
Print one line, containing two space separated integers, the heights of two towers. The smaller number goes first.
Example 1
Input:
3
100
90
200
Output:
190 200

Example 2
Input:
5
100
90
200
50
300

Example 3
Input:
8
100
100
100
100
100
100
120
110

*/
