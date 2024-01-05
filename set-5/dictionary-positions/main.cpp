#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>


using namespace std;

int main() {
     // create a dictionary that match char to numbers
    unordered_map<char, int> char_table;
    for(int i = 1; i < 27; i++) {
        char_table['a' + i - 1] = i;
    }


    // create a hashtable that holds all the numbers 
    unordered_map<string, int> number_table;
    int count = 1;
    for(int n1 = 0; n1 < 26; n1++)
    {
        string s = "";
        s.append(1, 'a' + n1);
        number_table[s] = count;
        count++;
    }

    for(int n1 = 0; n1 < 26; n1++) 
    {
        for(int n2 = n1 + 1; n2 < 26; n2++)
        {
            string s = "";
            s.append(1, 'a' + n1);
            s.append(1, 'a' + n2);
            number_table[s] = count;
            count++;
        }
    }

    for(int n1 = 0; n1 < 26; n1++) 
    {
        for(int n2 = n1 + 1; n2 < 26; n2++)
        {
            for(int n3 = n2 + 1; n3 < 26; n3++)
            {
                string s = "";
                s.append(1, 'a' + n1);
                s.append(1, 'a' + n2);
                s.append(1, 'a' + n3);
                number_table[s] = count;
                count++;
            }
        }
    }

    for(int n1 = 0; n1 < 26; n1++) 
    {
        for(int n2 = n1 + 1; n2 < 26; n2++)
        {
            for(int n3 = n2 + 1; n3 < 26; n3++)
            {
                for(int n4 = n3 + 1; n4 < 26; n4++)
                {
                    string s = "";
                    s.append(1, 'a' + n1);
                    s.append(1, 'a' + n2);
                    s.append(1, 'a' + n3);
                    s.append(1, 'a' + n4);
                    number_table[s] = count;
                    count++;
                }
            }
        }
    }

    for(int n1 = 0; n1 < 26; n1++) 
    {
        for(int n2 = n1 + 1; n2 < 26; n2++)
        {
            for(int n3 = n2 + 1; n3 < 26; n3++)
            {
                for(int n4 = n3 + 1; n4 < 26; n4++)
                {
                    for(int n5 = n4 + 1 ; n5 < 26; n5++)
                    {
                        string s = "";
                        s.append(1, 'a' + n1);
                        s.append(1, 'a' + n2);
                        s.append(1, 'a' + n3);
                        s.append(1, 'a' + n4);
                        s.append(1, 'a' + n5);
                        number_table[s] = count;
                        count++;
                    }
                }
            }
        }
    }

    // input the string
    string input;
    cin >> input;

    // check if the string is valid
    bool flag = true;
    for(int i = 0; i < input.length()-1; i++) 
    {
        if(char_table[input[i]] > char_table[input[i+1]]) 
        {
            flag = false;
            break;
        }
    }

    if(flag) 
    {
        cout << number_table[input];
    } 
    else 
    {
        cout << "0";
    }
    return 0;
}