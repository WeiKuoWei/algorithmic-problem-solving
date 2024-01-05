#include <iostream>
#include <vector>
#include <unordered_set>
#include <stack>
using namespace std;

// The functions associated with stack are: 
// empty() – Returns whether the stack is empty – Time Complexity : O(1) 
// size() – Returns the size of the stack – Time Complexity : O(1) 
// top() – Returns a reference to the top most element of the stack – Time Complexity : O(1) 
// push(g) – Adds the element ‘g’ at the top of the stack – Time Complexity : O(1) 
// pop() – Deletes the most recent entered element of the stack – Time Complexity : O(1) 

int check(string input, int input_length)
{
    stack<char> brackets;
    // unordered_set<char> o_brackets = {'(', '[', '{'};
    // unordered_set<char> c_brackets = {')', ']', '}'};
    for(int i = 0; i < input_length; i++)
    {
        char k = input[i];
        if((k == '(') || (k == '[') || (k == '{'))
        {
            brackets.push(k);
        }
        else if ((k == ')') || (k == ']') || (k == '}'))
        {
            if(brackets.empty())
                return i;
            else if(k ==  ')' && '(' == brackets.top())
                brackets.pop();
            else if(k ==  ']' && '[' == brackets.top())
                brackets.pop();
            else if(k ==  '}' && '{' == brackets.top())
                brackets.pop();
            else return i;
        }
        else continue;
    }
    if(!brackets.empty()) return input_length;
    return 0;
}

int main() {
    string input;
    getline(cin, input);
    int input_length = input.length();  
    int num = check(input, input_length);
    
    if(num == 0)
        cout << "YES" << endl;
    else 
        cout << "NO " << num+1 << endl;

    return 0;
}