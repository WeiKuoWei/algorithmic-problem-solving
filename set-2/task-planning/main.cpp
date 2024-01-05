#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int> > make_list(vector<pair<int, int> > list_n, vector<vector<int> >& list_m, int m) 
{
    for (int i = 0; i < m; i++) {
        int start_num = list_m[i][0], end_num = list_m[i][1], interval_num = list_m[i][2];
        while (end_num < 1000000) {
            list_n.push_back(make_pair(start_num, end_num));
            start_num += interval_num, end_num += interval_num;
        }
    }
    return list_n;
}

bool compareInterval(pair<int, int> i1, pair<int, int> i2) 
{
    return (i1.first < i2.first) ? true : false;
}

// Function to check if any two intervals overlap
bool isIntersect(vector<pair<int, int> > new_list) 
{
    // Sort intervals in increasing order of start time
    sort(new_list.begin(), new_list.end(), compareInterval);

    for (int i = 1; i < new_list.size(); i++)
        if (new_list[i - 1].second > new_list[i].first)
            return true;

    // If reach here, then no overlap
    return false;
}

int main() 
{
    int n, m;
    cin >> n >> m;
    vector<pair<int, int> > list_n;
    vector<vector<int> > list_m(m, vector<int>(3)); 
    // 2D vector - can furthermore 

    for (int i = 0; i < n; i++) 
    {
        int num1 = 0, num2 = 0;
        cin >> num1 >> num2;
        list_n.push_back(make_pair(num1, num2));
    }

    for (int i = 0; i < m; i++) 
    {
        int num1 = 0, num2 = 0, num3 = 0;
        cin >> num1 >> num2 >> num3;
        list_m[i][0] = num1;
        list_m[i][1] = num2;
        list_m[i][2] = num3;
    }

    // Add the tuple list to the pair list
    vector<pair<int, int> > new_list = make_list(list_n, list_m, m);

    isIntersect(new_list) ? cout << "CONFLICT" << endl: cout << "NO CONFLICT" << endl;

    return 0;
}