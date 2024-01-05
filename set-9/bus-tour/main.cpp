#include <iostream>
#include <vector>
#include <climits>
#include <string>
#include <sstream>

using namespace std;

int main() 
{
    string input_line;
    getline(cin, input_line);
    int num_stops = stoi(input_line);

    vector<int> stops;
    
    int counter = num_stops - 1;
    
    while(counter > 0)
    {
        getline(cin, input_line);
        stops.push_back(stoi(input_line));
        counter--;
    }
    
    long long current_sum = LONG_MIN;
    long long global_sum = LONG_MIN;
    int start_index = 0;
    int end_index = 0;
    
    int global_start_index = 0;
    int global_end_index = 0;
    
    for(int i = 0 ; i < num_stops - 1 ; i++)
    {
        if(0 > current_sum)
        {
            current_sum = stops[i];
            start_index = i;
            end_index = i;
        }
        else
        {
            current_sum += stops[i];
            end_index = i;
        }
           
        if(current_sum > global_sum)
        {
            global_start_index = start_index;
            global_end_index = end_index;
            global_sum = current_sum;
        }
        else if(global_sum == current_sum)
        {
            if(global_end_index - global_start_index < end_index - start_index)
            {
                global_start_index = start_index;
                global_end_index = end_index;
            }
            else if(global_end_index - global_start_index == end_index - start_index)
            {
                if(start_index < global_start_index)
                {
                    global_start_index = start_index;
                    global_end_index = end_index;
                }
            }
        }
    }
    
    if(global_sum < 0)
    {
        cout << "Yet another overrated tourist destination" << endl;
    }
    else
    {
        cout << "The nicest part of Y1 is between stops " << global_start_index + 1 << " and " << global_end_index + 2 << endl;
    }

    return 0;
}

// i discussed the problem with sasah malik, and uses his input function
// please use the previous code I submitted if this is not appropriate

/*

Input
The first line of input contains an integer, N, the number of stops along the Y1 bus route, 2 <= N<= 20,000
Each of the next N-1 lines contains a single integer. The i-th integer indicating niceness between stop i and stop i+1.
The absolute value of niceness will not exceed 10ˆ9.

Output If the maximum possible sum between two stops is not positive, your program should print a line:
“Yet another overrated tourist destination”
Otherwise, your program should identify the beginning bus stop i and the ending bus stop j that identify the segment
of the route which yields the maximal sum of niceness.
If more than one segment is equally maximally nice, choose the one with the longest bus ride (largest number of
stops, j - i). To break ties further in longest maximal segments, choose the segment that begins with the earliest
stop (lowest i).
Print a line in the form:
“The nicest part of Y1 is between stops i and j”

Example 1
Input
3
-2
5

Output
The nicest part of Y1 is between stops 2 and 3

Example 2
Input
4
-1
-1
-1

Output
Yet another overrated tourist destination

100000*20000
*/