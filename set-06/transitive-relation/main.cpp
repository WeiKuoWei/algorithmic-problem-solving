#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Function to find the representative element of a set
int findSet(int elem, vector<int>& parent) 
{
    if (elem == parent[elem])
        return elem;
    return parent[elem] = findSet(parent[elem], parent);
}

int main() 
{
    int num_cap, num_inputs;
    cin >> num_cap >> num_inputs;

    vector<int> parent(num_cap);  // Each element's parent in the set
    vector<int> setSize(num_cap, 1);  // Size of each set (initialized to 1)

    // Initialize the DSU: Each element is initially its own parent
    for (int i = 0; i < num_cap; i++) 
    {
        parent[i] = i;
    }

    while (num_inputs--) 
    {
        int a, b;
        cin >> a >> b;

        int parentA = findSet(a, parent);
        int parentB = findSet(b, parent);

        // If they are not in the same set, merge the sets
        if (parentA != parentB) {
            // Merge smaller set into larger set to optimize the tree
            if (setSize[parentA] < setSize[parentB]) 
            {
                swap(parentA, parentB);
            }

            parent[parentB] = parentA;  // Set parentB's parent to parentA
            setSize[parentA] += setSize[parentB];  // Update the size of the merged set
        }
    }

    int max_size = 0;
    unordered_map<int, int> size_map;

    // Calculate the maximum set size
    for (int i = 0; i < num_cap; i++) 
    {
        int representative = findSet(i, parent);
        size_map[representative]++;

        max_size = max(max_size, size_map[representative]);
    }

    cout << max_size << endl;
    return 0;
}
