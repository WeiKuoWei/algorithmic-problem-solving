#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    vector<int> intput_list;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        int temp; 
        cin >> temp;
        intput_list.push_back(temp);
    }

    cout << intput_list[(n-1)/2] << endl;
    return 0;
}