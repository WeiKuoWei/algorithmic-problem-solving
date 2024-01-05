#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
using namespace std;

// create a structure for nodes
// create the tree itself

int main()
{   
    vector<string> output_list, input_list;


    string input_line;
    while(true)
    {
        string temp;
        getline(cin, temp);
        if(cin.eof() || temp.empty()) break;
        else
        {
            input_line.append(temp);
            input_line.append(" ");
        } 
    }

    // iterating through the entire line
    string temp_input;
    int length = input_line.size();
    for(int i = 0; i < length; i++)
    {
        char ch = input_line[i];
        // cout << "ch: " << ch << endl;
        // encounter space then push temp_input into input_list
        if((ch == ' ' || i == (length-1)) && !temp_input.empty())
        {
            input_list.push_back(temp_input);
            temp_input.clear();
        }
        // encounter upper: 65-90: change ch to lower case then append to temp
        else if(65 <= ch && ch <= 90)
        {
            string asciiString(1, ch+32);
            temp_input.append(asciiString);
        }
        // encounter lower: 97-122: append ch to temp
        else if(97 <= ch && ch <= 122)
        {
            string asciiString(1, ch);
            temp_input.append(asciiString);
        }
        // encounter other: continue
        else continue;
    }

    // implement a binary search tree to store values
    set<string> string_list; 
    int input_size = input_list.size();
    for(int i = 0; i < input_size; i++)
    {
        string_list.insert(input_list[i]);
    }

    // print out the set
    for(string output: string_list)
    {
        cout << output << endl;
    }
    // set<string>:: iterator it;
    // for(it = string_list.begin(); it != string_list.end(); it++)
    // {
    //     cout << *it << endl;
    // }

    return 0;
}