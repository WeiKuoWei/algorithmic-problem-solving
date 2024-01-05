#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_days, num_unions;
    cin >> num_days >> num_unions;

    vector<int> union_list;
    while(num_unions--)
    {
        int temp;
        cin >> temp;
        union_list.push_back(temp);
    }

    // strike list
    vector<int> strike_list(num_days, 0);
    for(int val: union_list)
    {
        for(int i = 0; i < num_days; i++)
        {
            if((i + 1) % val == 0)
            {
                strike_list[i] = 1;
            }
        }
    }

    // print the strike list but exclude fridays and saturdays
    int count = 0;
    for(int i = 0; i < num_days; i++)
    {
        if((i + 1) % 7 != 0 && (i + 1) % 7 != 6)
        {
            if(strike_list[i] == 1)
            {
                count++;
            }
        }
    }

    cout << count << endl;
    
    return 0;
}