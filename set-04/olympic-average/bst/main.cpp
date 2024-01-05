#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>
#include <deque>
#include <unordered_map>


using namespace std;

int main()
{
    multiset<int> bst_list;
    int n;
    cin >> n;

    while(n--)
    {
        int m;
        cin >> m;
        while(m--)
        {
            int num;
            cin >> num;
            bst_list.insert(num);
        }
        multiset<int>:: iterator front = bst_list.begin();
        multiset<int>:: iterator back = prev(bst_list.end());
        // cout << endl;
        cout << *back - *front << endl;
        bst_list.erase(front);
        bst_list.erase(back);
    }
    return 0;
}
