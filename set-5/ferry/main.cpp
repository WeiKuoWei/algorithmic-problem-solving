#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

using namespace std;

bool compareFirstInt(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main()
{
    // Input values: ferry capacity, time interval, and number of cars
    int capacity, interval, num_of_cars;
    cin >> capacity >> interval >> num_of_cars;

    // Split the input into two deques: left-bound cars and right-bound cars
    // deque<int> left, right;
    deque<pair<int, int> > left, right;
    int count = 0;
    while (num_of_cars--)
    {
        int arrival_time;
        string direction;
        cin >> arrival_time >> direction;
        if (direction == "left")
        {
            left.push_back(make_pair(arrival_time, count));
        }
        else
        {
            right.push_back(make_pair(arrival_time, count));
        }
        count++;
    }

    // Create a flag that indicates which side the ferry is currently on
    // and record the current time
    vector<pair<int, int> > output_list;
    bool ferry_at_left = true;
    int current_time = 0;

    // While there are cars on either side
    while (!left.empty() || !right.empty())
    {
        int capacity_temp = capacity; // Temporary capacity for loading/unloading

        // If the ferry is at the left side
        if (ferry_at_left)
        {
            if (!left.empty() && !right.empty())
            {
                // Determine which side has a car arriving first
                if (left.front().first <= right.front().first && current_time <= left.front().first)
                {
                    current_time = left.front().first;
                }
                else if (left.front().first > right.front().first && current_time <= right.front().first)
                {
                    current_time = right.front().first;
                    current_time += interval;
                    ferry_at_left = !ferry_at_left;
                }
            }

            else if (!left.empty() && current_time <= left.front().first)
            {
                current_time = left.front().first;
            }
            else if (!right.empty() && current_time <= right.front().first)
            {
                current_time = right.front().first;
                current_time += interval;
                ferry_at_left = !ferry_at_left;
            }
        }
        // If the ferry is at the right side
        else if (!ferry_at_left)
        {
            if (!left.empty() && !right.empty())
            {
                if (left.front().first < right.front().first && current_time <= left.front().first)
                {
                    current_time = left.front().first;
                    current_time += interval;
                    ferry_at_left = !ferry_at_left;
                }
                else if (left.front().first >= right.front().first && current_time <= right.front().first)
                {
                    current_time = right.front().first;
                }
            }

            else if (!left.empty() && current_time <= left.front().first)
            {
                current_time = left.front().first;
                current_time += interval;
                ferry_at_left = !ferry_at_left;

            }
            else if (!right.empty() && current_time <= right.front().first)
            {
                current_time = right.front().first;
            }
        }

        // If the ferry is at the left side, load left-bound cars
        if (ferry_at_left)
        {
            while (capacity_temp-- && !left.empty())
            {
                if (left.front().first <= current_time)
                {
                    // Record the arrival time of the loaded car
                    output_list.push_back(make_pair(left.front().second, current_time + interval));
                    left.pop_front();
                }
                else
                {
                    break;
                }
            }
        }
        // If the ferry is at the right side, load right-bound cars
        else
        {
            while (capacity_temp-- && !right.empty())
            {
                if (right.front().first <= current_time)
                {
                    // Record the arrival time of the loaded car
                    output_list.push_back(make_pair(right.front().second, current_time + interval));
                    right.pop_front();
                }
                else
                {
                    break;
                }
            }
        }
        current_time += interval;
        ferry_at_left = !ferry_at_left;
    }

    sort(output_list.begin(), output_list.end(), compareFirstInt);
    // Print the arrival times of the loaded cars
    // sort(output_list.begin(), output_list.end());
    for (auto val : output_list)
    {
        cout << val.second << endl;
    }

    return 0;
}