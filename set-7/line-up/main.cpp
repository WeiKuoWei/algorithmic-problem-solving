#include <iostream>
#include <deque>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main()
{
    int n, counter = 0;
    // recording the groups in the queue
    unordered_map<int, deque<int> > groups;
    // recording the ppl in which group
    unordered_map<int, int> ppl;
    deque<int> order;
    vector<int> output_list;
    cin >> n;
    
    while(n--)
    {
        // create a hash map that record which ppl are in which group
        int m;
        cin >> m;
        while(m--)
        {
            int temp;
            cin >> temp;
            ppl[temp] = counter;
        }
        // create a hash table that stores the ppl in queues
        deque<int> temp;
        groups[counter] = temp;
        counter++;
    }

    while(true)
    {
        string command;
        getline(cin, command);

        if(command == "Shutdown")
        {
            break;
        }
        else if(command == "Pop")
        {
            // pop the first element of the group in the queue
            int current_grp = order.front();
            output_list.push_back(groups[current_grp].front());
            groups[current_grp].pop_front();
            // if the queue is empty, pop the group
            if(groups[current_grp].empty())
            {
                order.pop_front();
            }
        }

        istringstream iss(command);
        string temp;
        int num;
        iss >> temp >> num;
        
        if(temp == "Push")
        {
            // cout << "num: " << num << endl;
            // locate the ppl in the group
            int current_grp = ppl[num];
            // push the ppl into the queue
            groups[current_grp].push_back(num);
            // if the group is not in the queue, push the group into the queue
            bool flag = true;
            for(auto val: order)
            {
                if(val == current_grp)
                {
                    flag = false;
                    break;
                }
            }
            if(flag)
            {
                order.push_back(current_grp);
            }
        }
    }

    for(auto val: output_list)
    {
        cout << val << endl;
    }
    return 0;
}