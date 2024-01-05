#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>

using namespace std;

int main()
{   
    vector<string> output_list, input_list;
    unordered_map<string, int> hashtable(800000);
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

    for(const string& key: input_list)
    {
        hashtable.insert(make_pair(key, 1));
    }

    for(const auto& pair: hashtable)
    {
        output_list.push_back(pair.first);
    }

    sort(output_list.begin(), output_list.end());

    for(string output: output_list){
        cout << output << endl;
    }
    return 0;
}