#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// Declare a set to store unique vectors representing subsets with the desired sum
set<vector<int> > output_list;

// Recursive function to find all subsets with the target sum
void subset_sum(vector<int>& numbers, int target, vector<int> partial = vector<int>()) {
    int s = 0;  // Variable to store the sum of elements in the current partial subset
    int n;  // Variable to store the current number
    vector<int> remaining;  // Vector to store the remaining numbers for recursive calls

    // If partial subset is empty, initialize it
    if (partial.empty()) {
        partial = vector<int>();
    }

    // Calculate the sum of elements in the current partial subset
    for (int num : partial) {
        s += num;
    }

    // Check if the current partial subset equals the target sum
    if (s == target) {
        // Sort the subset in descending order before inserting into the set
        vector<int> temp;
        for (int i = 0; i < partial.size(); i++) {
            temp.push_back(partial[i]);
        }
        sort(temp.begin(), temp.end(), greater<int>());
        output_list.insert(temp);
    }

    // If the current sum is greater than or equal to the target, stop recursion
    if (s >= target) {
        return;
    }

    // Iterate through remaining numbers and make recursive calls
    for (int i = 0; i < numbers.size(); i++) {
        n = numbers[i];
        // Extract remaining numbers after choosing the current one
        remaining = vector<int>(numbers.begin() + i + 1, numbers.end());
        // Create a new partial subset with the current number
        vector<int> new_partial(partial);
        new_partial.push_back(n);
        // Recursive call with the remaining numbers
        subset_sum(remaining, target, new_partial);
    }
}

int main() {
    // Initialize vector to store input numbers, target sum, and a counter
    vector<int> numbers;
    int target, n;
    // Read input: target sum and the number of elements
    cin >> target >> n;
    // Read the input numbers
    while (n--) {
        int temp;
        cin >> temp;
        numbers.push_back(temp);
    }

    // Call the subset_sum function to find all subsets with the target sum
    subset_sum(numbers, target);

    // Output the subsets with the target sum
    cout << "Sums of " << target << ":" << endl;

    // Check if there are no valid subsets
    if (output_list.empty()) {
        cout << "NONE" << endl;
        return 0;
    }

    // Iterate through the set in reverse order to output subsets in descending order
    for (int i = output_list.size() - 1; i >= 0; i--) {
        const vector<int>& v = *next(output_list.begin(), i);  // Get the i-th vector
        // Output the elements of the current subset
        cout << v[0];
        for (int j = 1; j < v.size(); j++) {
            cout << "+" << v[j];
        }
        cout << endl;
    }

    return 0;
}


/*

400 10
150 100 60 60 50 50 50 30 20 20

*/