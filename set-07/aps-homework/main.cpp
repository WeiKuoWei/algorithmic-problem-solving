#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct homework
{
    int time_to_solve;
    int time_to_compile;
    // int time_diff;;
};

bool compare(const homework& lhs, const homework& rhs)
{
    // sort the list with the largest time to compile
    return lhs.time_to_compile > rhs.time_to_compile;
};

int main()
{
    int total_time = 0;
    int num_homeworks;
    deque<homework> homeworks;
    cin >> num_homeworks;
    while(num_homeworks--)
    {
        int time_to_solve, time_to_compile;
        cin >> time_to_solve >> time_to_compile;
        homework temp;
        temp.time_to_solve = time_to_solve;
        temp.time_to_compile = time_to_compile;
        // temp.time_diff = time_to_compile - time_to_solve;
        homeworks.push_back(temp);
    }

    sort(homeworks.begin(), homeworks.end(), compare);
    int max_time = 0;
    for(int i = 0; i < homeworks.size(); i++)
    {
        total_time += homeworks[i].time_to_solve;
        max_time = max(max_time, total_time + homeworks[i].time_to_compile);
    }
    
    cout << max_time << endl;

    return 0;
}
