#include <iostream>
#include <vector>
using namespace std;

int maxSpending = -1; // To track the maximum amount spent

// Backtracking function to find the maximum spending
void backtracking(vector<vector<int> >& desserts, int money, int idx, int spent) {
    if (money < 0) return; // If the money is negative, stop exploring this path

    if (idx == desserts.size()) { // Reached the end of desserts list
        maxSpending = max(maxSpending, spent); // Update maximum spending
        return;
    }

    // For each dessert, try each flavor and recurse
    for (int i = 1; i < desserts[idx][0] + 1; ++i) {
        int price = desserts[idx][i];
        backtracking(desserts, money - price, idx + 1, spent + price);
    }
}

int main() {
    int M, N;
    cin >> M >> N;

    vector<vector<int> > desserts(N, vector<int>());

    for (int i = 0; i < N; ++i) {
        int K;
        cin >> K;
        desserts[i].push_back(K); // desserts[i][0] is used to save the number of elements in each dessert
        for (int j = 0; j < K; ++j) {
            int price;
            cin >> price;
            desserts[i].push_back(price);
        }
    }

    backtracking(desserts, M, 0, 0);

    if (maxSpending == -1) {
        cout << "no solution" << endl;
    } else {
        cout << maxSpending << endl;
    }

    return 0;
}

/*

Example 1
Input:
100 4
3 8 6 4
2 5 10
4 1 3 3 7
4 50 14 23 8
Output:
75
by picking 8, 10, 7 and 50.
Example 2
Input:
20 3
3 4 6 8
2 5 10
4 1 3 5 5
Output:
19
Example 3
Input:
5 3
3 6 4 8
2 10 6
4 7 3 1 7
Output:
no solution

*/