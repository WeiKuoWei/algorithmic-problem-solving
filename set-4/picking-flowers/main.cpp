#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <unordered_map>

using namespace std;

// global variables
// unordered_map<string, vector<int> > hashtable;

vector<string> input_values(const int& num)
{
    vector<string> list;
    for(int i = 0; i < num; i++)
    {
        string temp;
        cin >> temp;
        list.push_back(temp);
    }
    return list;
}
void insert_hashtable(unordered_map<string, vector<int> >& hashtable, const vector<string>& list, int person)
{
    // insert the values into the hashtable, and check the if the values were already inserted
    // key is the kind of the flower, while value is the ppl x, y, z
    int length = list.size();
    for(int i = 0; i < length; i++)
    {
        string key = list[i];
        if(hashtable[key].empty())
        {
            vector<int> person_list;
            hashtable.insert(make_pair(key, person_list));
            hashtable[key].push_back(person);
        }
            
        else if(hashtable[key].back() != person)
        {
            hashtable[key].push_back(person);
        }
        else
            continue;
    }

}

int main()
{
    // initiated the variables
    int x_num, y_num, z_num;
    unordered_map<string, vector<int> > hashtable;
    // input the values
    cin >> x_num >> y_num >> z_num;
    vector<string> x_list = input_values(x_num);
    vector<string> y_list = input_values(y_num);
    vector<string> z_list = input_values(z_num);
 
    // insert the values into a hashtable
    insert_hashtable(hashtable, x_list, 1);
    insert_hashtable(hashtable, y_list, 2);
    insert_hashtable(hashtable, z_list, 3);

    // check the values in the hashtable
    int x_front = 0, y_front = 0, z_front = 0, x_back = 0, y_back = 0, z_back = 0;
    for (const auto& pair : hashtable) 
    {
        int size = pair.second.size();

        // if there's only one value in vector<int>
        if(size == 1)
        {
            // case 1
            if(pair.second[0] == 1) x_front++;
            // case 2
            else if(pair.second[0] == 2) y_front++;
            // case 3
            else if(pair.second[0] == 3) z_front++;
        }

        // if there's two values in vector<int>
        else if(size == 2)
        {
            int sum  = pair.second[0] + pair.second[1];
            // missing 1
            if(sum == 5) x_back++; 
            // missing 2
            else if(sum == 4) y_back++;
            // missing 3
            else if(sum == 3) z_back++;
        }

        // if there's three values in vector<int>
        else if(size == 3) continue;
    }

    cout << x_front << " " << x_back << endl;
    cout << y_front << " " << y_back << endl;
    cout << z_front << " " << z_back;

    return 0;
}