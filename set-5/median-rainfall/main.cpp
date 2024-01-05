#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

int main()
{
    // Create one max heap and one min heap
    priority_queue<long> maxHeap;
    priority_queue<long, vector<long>, greater<long> > minHeap;
    vector<long> result; // Store the medians
    string input;
    
    while (true)
    {
        getline(cin, input);
        if (input.empty())
            break;

        long num = stoi(input);

        if (maxHeap.empty() || num < maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }

        // Ensure the maxHeap is not significantly larger than the minHeap
        if (maxHeap.size() > minHeap.size() + 1)
        {
            long top = maxHeap.top();
            maxHeap.pop();
            minHeap.push(top);
        }
        else if (minHeap.size() > maxHeap.size())
        {
            long top = minHeap.top();
            minHeap.pop();
            maxHeap.push(top);
        }

        // Calculate and store the median
        if (maxHeap.size() == minHeap.size())
        {
            long median = (maxHeap.top() + minHeap.top()) / 2;
            result.push_back(median);
        }
        else
        {
            result.push_back(maxHeap.top());
        }
    }

    // Output the medians
    for (long median : result)
    {
        cout << median << endl;
    }

    return 0;
}
