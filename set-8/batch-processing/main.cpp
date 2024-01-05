#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;

// Function to split tasks into partitions based on a maximum time limit
bool split(const deque<int> &tasks, deque<int> &separators, int num_partitions, long long int max) 
{
    long long int current = 0;
    int partitions = 1;    // Number of partitions
    int remainings = tasks.size();   // Number of remaining tasks

    // Iterate through tasks starting from the end we start from the end because
    // the array is sorted in ascending order, thus considering larger values
    // from the end is more efficient


    for (int i = tasks.size() - 1; i >= 0; --i) 
    {
        if ((current + tasks[i] <= max) && (remainings > num_partitions - partitions)) 
            // Add the task to the current partition
            current += tasks[i];
        else 
        {
            if (partitions == num_partitions) 
                // Not enough tasks left for the remaining partitions
                return false;             
            // Start a new partition with the current task
            current = tasks[i];
            partitions++;
            separators.push_back(i);
        }
        remainings--;
    }
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

    deque<int> best_separators;
    long long int left_limit = max_task_time, right_limit = total_time, best_max = right_limit;

    while (true) 
    {
        if (left_limit > right_limit) 
        {
            // Exit the loop when the limits have crossed
            break;
        }

        long long int middle = left_limit + (right_limit - left_limit) / 2;
        deque<int> separators;


        // if splitting is possible, lower the maximum for the next iteration
        // for possible better results
        if (split(task_times, separators, partitions, middle)) 
        {
            best_max = middle;
            best_separators = separators;
            right_limit = middle - 1;
        }

        // if splitting is not possible, that means the current middle is out of
        // range, thus increase the lower limit the current minimum for the next
        // iteration for possible better results
        else 
        {
            left_limit = middle + 1;
        }
    }
    
    reverse(best_separators.begin(), best_separators.end());

    int count = 0, index = 0, separators_count = best_separators.size();

    // Output task times with separators
    for (auto val: task_times)
    {
        cout << val;
        if (count == total_tasks - 1)
        {
            cout << endl;
        }
        else
        {
            cout << " ";
        }
        if ((index < separators_count) && (count == best_separators[index]))
        {
            cout << "/ ";
            index++;
        }
        count++;
    }

    return 0;
}


/*
9 3
100 200 300 400 500 600 700 800 900


5 4
100 100 100 100 100

*/