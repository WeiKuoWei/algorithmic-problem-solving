#include <iostream>
#include <deque>
#include <algorithm>
#include <queue>    

using namespace std;

int main()
{   
    int n;
    cin >> n;

    priority_queue<long long int, vector<long long int>, greater<long long int> > input_list;
    while(n--)
    {
        int temp;
        cin >> temp;
        input_list.push(temp);
    }

    long long int cost = 0;
    while(input_list.size() > 1)
    {
        long long int temp = input_list.top();
        input_list.pop();
        temp += input_list.top();
        input_list.pop();
        cost += temp;
        input_list.push(temp);
    }

    cout << cost << endl;
    return 0;
}

/*

Example 1
Input:
3
1 2 3
Output:
9
Example 2
Input:
4
1 2 3 4
Output:
19

Example 3
Input:
5
1 2 3 4 5
Output:
33
*/