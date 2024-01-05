#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <deque>
#include <sstream>
#include <unordered_map>

using namespace std;

// Define a custom comparison struct
struct CustomCompare {
    bool operator()(const pair<int, int>& a, const pair<int, int>& b) const 
    {
        // Compare based on the first number
        if (a.second > b.second) 
        {
            return true;
        }
        if (a.second < b.second) 
        {
            return false;
        }

        // If the first numbers are equal, compare based on the second number
        return a.first > b.first;
    }
};

int main() {

    // create a vector to hold the input
    vector<pair<int, int> > input_list;
    int min, id, interval;
    string input, temp;

    // input the first line to get min
    getline(cin, input);
    istringstream iss(input);
    iss >> temp >> id >> min;
    input_list.push_back(make_pair(id, min));

    while(getline(cin, input))
    {
        if(input == "#") break;
        else
        {
            istringstream iss(input);
            iss >> temp >> id >> interval;

            input_list.push_back(make_pair(id, interval));
            // find the minimum interval
            if(min > interval) min = interval;
        }
    }

    // find out the maximum time that can be made
    int num_of_outputs;
    cin >> num_of_outputs;
    min = min * num_of_outputs;
    
    // create a priority queue that holds two values
    priority_queue<pair<int, int>, vector<pair<int, int> >, CustomCompare> time_list;
    for(auto val: input_list)
    {
        time_list.push(make_pair(val.first, val.second));
    }

    // push the numbers into the hashtable
    unordered_map<int, deque<int> > time_table;
    for(auto val: input_list)
    {
        int current_time = val.second, id = val.first;
        while(current_time <= min)
        {
            current_time += val.second;
            time_table[id].push_back(current_time);
        }
    }

    // create a vector to hold the output
    vector<int> output_list;
    while(num_of_outputs--)
    {
        pair<int, int> top = time_list.top();
        int id = top.first;
        output_list.push_back(id);
        time_list.pop();
        int time = time_table[id].front();
        time_table[id].pop_front();
        time_list.push(make_pair(id, time));
    }

    // print the output_list
    for(auto val: output_list)
    {
        cout << val << endl;
    }

    return 0;
}