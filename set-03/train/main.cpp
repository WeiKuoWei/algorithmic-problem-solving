#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;

bool check(deque<int> car_list, int max_num)
{
    deque<int> stay_list;
    deque<int> start_list;
    while(!car_list.empty())
    {
        // cout << "car_list: ";
        // for(int i = 0; i < car_list.size() ; i++)
        // {
        //     cout << car_list[i] << " ";
        // }
        // cout << endl;
        // cout << "stay_list: ";
        // for(int i = 0; i < stay_list.size() ; i++)
        // {
        //     cout << stay_list[i] << " ";
        // }
        // cout << endl;
        // cout << "start_list: ";
        // for(int i = 0; i < start_list.size() ; i++)
        // {
        //     cout << start_list[i] << " ";
        // }
        // cout << endl;

        if((!stay_list.empty()) && (stay_list.back() == max_num))
        {
            // the top of the stay list is the maximum
            // cout << "a" << endl;
            start_list.push_front(stay_list.back());
            stay_list.pop_back();
            max_num--;
        }
        else if((!car_list.empty()) && (car_list.back() == max_num))
        {
            // the top of the car list is the 
            // cout << "b" << endl;
            start_list.push_front(car_list.back());
            car_list.pop_back();
            max_num--;
        }
        else
        {
            // cout << "c" << endl;
            stay_list.push_back(car_list.back());
            car_list.pop_back();
            
        }
    }

    if(stay_list.empty())
        return true;
    for(int i = 0; i < stay_list.size()-1; i++)
    {
        if(stay_list[i]+1 != stay_list[i+1])
            return false;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;

    deque<int> car_list;
    vector<string> answer_list;
    int flag = 1;
    while(flag == 1)
    {
        for(int i = 0; i < n; i++)
        {
            int k;
            cin >> k;
            if(k == 0)
            {
                flag = 0;
                break;
            }
            car_list.push_back(k);
        }
        if(flag == 0) 
            break;

        else if(check(car_list, n)) 
            answer_list.push_back("Yes");
        else 
            answer_list.push_back("No");
        car_list.clear();
    }

    for(int i = 0; i < answer_list.size(); i++)
    {
        cout << answer_list[i] << endl;
    }
    
    return 0;
}