#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

// Function to find the minimum steps required for word transformation
int minTransformationSteps(const string& start, const string& end, unordered_set<string>& dictionary) {
    // If the start and end words are the same, no transformation is needed
    if (start == end) return 0;

    // Queue to perform BFS for word transformation
    queue<pair<string, int> > q;
    q.push(make_pair(start, 1)); // Push the starting word into the queue with step count 1

    // Temporary set to keep track of visited words during BFS
    unordered_set<string> visited;

    // Loop until the queue is empty
    while (!q.empty()) {
        // Get the current word and its step count from the front of the queue
        pair<string, int> current = q.front();
        q.pop();

        // Extract the word and step count from the pair
        string word = current.first;
        int steps = current.second;

        // Iterate through each character of the word
        for (int i = 0; i < word.length(); ++i) {
            char original = word[i]; // Store the original character

            // Try replacing the current character with all lowercase alphabets (a-z)
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == original) continue; // Skip if the character is the same as the original

                word[i] = c; // Replace the character

                // If the word matches the target end word, return the number of steps
                if (word == end) return steps;

                // If the modified word exists in the dictionary and hasn't been visited
                if (dictionary.find(word) != dictionary.end() && visited.find(word) == visited.end()) {
                    q.push(make_pair(word, steps + 1)); // Push the modified word into the queue with increased step count
                    visited.insert(word); // Mark the word as visited to avoid repetition
                }
            }

            word[i] = original; // Revert the character back to its original value
        }
    }

    return -1; // If transformation is not possible
}

// Main function
int main() {
    int n;
    cin >> n;

    // Creating an unordered set to store the dictionary words
    unordered_set<string> dictionary;

    // Reading n words and inserting them into the dictionary
    for (int i = 0; i < n; ++i) {
        string word;
        cin >> word;
        dictionary.insert(word);
    }

    int m;
    cin >> m;

    // For each query, find the minimum transformation steps and print the result
    for (int i = 0; i < m; ++i) {
        string start, end;
        cin >> start >> end;
        int steps = minTransformationSteps(start, end, dictionary);
        cout << steps << endl;
    }

    return 0;
}



/*

Finalized the edit-distance with the help of chatgpt.

Input
The first line contains an integer n, the number of words in the dictionary, 1 <= n <= 200. Each of the following n
lines contains a word in the dictionary. All words will be alphabetic and in lower case. And no word will be longer
than 10 characters.
The following line contains an integer m, the number of queries. Each of the following m lines contain a pair of word
separated by space. They represent the starting word and the ending word. All pairs are guaranteed to have a
transformation using the dictionary given.

Output m lines of numbers: the i-th line represents the minimum number of steps in the transformation for the i-th
pair of words.

Example 1
Input:
11
dip
lip
mad
map
may
pad
pip
pod
pop
sap
sip
4
may mad
map map
pip pod
mad dip
Output:
1
0
2
4


*/