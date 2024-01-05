#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>


using namespace std;

int main()
{
    priority_queue<int> big_list;
    // priority_queue<int, vector<int>, greater<int> > small_list;
    priority_queue<int> small_list;
    
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
            big_list.push(num);
            small_list.push(-num);
        }
        
        cout << big_list.top() + small_list.top() << endl;
        big_list.pop();
        small_list.pop();
    }
    return 0;
}

// Note: The above syntax may be difficult to remember, so in case of numeric
// values, we can multiply the values with -1 and use max heap to get the effect
// of min heap. Not only that we can use custom sorting method by replacing
// greater with custom comparator function.
