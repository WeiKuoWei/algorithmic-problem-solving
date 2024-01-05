#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

// Function to split tasks into partitions based on a maximum time limit
bool split(const deque<int> &tasks, int num_partitions, long long int max) 
{
    long long int current = 0;
    int partitions = 1;    // Number of partitions
    int remainings = tasks.size();   // Number of remaining tasks

    // Iterate through tasks starting from the end
    for (int i = tasks.size() - 1; i >= 0; --i) 
    {
        if ((current + tasks[i] <= max) && (remainings > num_partitions - partitions)) 
        {
            // Add the task to the current partition
            current += tasks[i];
        }
        else 
        {
            if (partitions == num_partitions) 
            {
                // if partitions is already equal to num_partitions but there
                // are still remaining tasks left, return false
                return false;
            }
            
            // Start a new partition with the current task
            current = tasks[i];
            partitions++;
        }
        remainings--;
    }
    // after running the whole for loop, return true if the tasks are splitted
    // into the intended number of partitions
    return partitions == num_partitions;
}

int main() 
{
    int total_tasks, partitions;
    cin >> total_tasks >> partitions;

    deque<int> task_times;
    int max_task_time = 0;
    long long int total_time = 0;

    // Read task times and calculate total time and maximum task time
    for (int i = 0; i < total_tasks; i++) 
    {
        int task;
        cin >> task;
        task_times.push_back(task);
        total_time += task;
        max_task_time = max(max_task_time, task);
    }

    long long int left_limit = max_task_time, right_limit = total_time, best_max = right_limit;

    while (true) 
    {
        if (left_limit > right_limit) 
        {
            // Exit the loop when the limits have crossed
            break;
        }

        long long int middle = left_limit + (right_limit - left_limit) / 2;

        if (split(task_times, partitions, middle)) 
        {
            best_max = middle;
            right_limit = middle - 1;
        }
        else 
        {
            left_limit = middle + 1;
        }
    }

    cout << best_max << endl;

    return 0;
}

/*

Input
The first line contains 2 integer N, M as described above. 1 <= M <= N <= 10ˆ5.
In the next line, there are N natural numbers indicating the elements of the array. 0 <= A[i] <= 10ˆ9 for 1 <= i
<= N
Output
Output one integer followed by a newline, indicating the minimal maximum sum of any subarray in the optimal split.
Example 1
Input:
4 3
4 3 2 1
Output:
4
Example 2
Input:
4 1
4 3 2 1
Output:
10
Example 3
Input:
3 2
1 100 2
Output:
101

5 4
1 1 1 1 1
2 

5 3
1 1 1 1 1

5 4
2 2 2 2 2

5 1 
1 1 1 1 1

// got three wrong answers

*/