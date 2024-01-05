#include <iostream>
#include <unordered_map>
#include <vector>
#include <deque>
#include <string>
#include <cctype>
using namespace std;

// Function to convert infix expression to postfix expression
string infixToPostfix(string& infix) 
{
    // Map to store operator precedence
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    // Deque to store operators and postfix expression
    deque<char> operators, postfix;
    
    // Iterate through the infix expression
    for (char ch : infix) 
    {
        // If the character is an alphanumeric character (operand), add it to the postfix expression
        if (isalnum(ch)) 
        {
            postfix.push_back(ch);
        } 
        // If the character is an opening parenthesis, push it to the operators deque
        else if (ch == '(') 
        {
            operators.push_back(ch);
        } 
        // If the character is a closing parenthesis
        else if (ch == ')') 
        {
            // Pop operators and append to postfix until an opening parenthesis is encountered
            while (!operators.empty() && operators.back() != '(') 
            {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            // Pop the opening parenthesis
            if (!operators.empty() && operators.back() == '(') 
            {
                operators.pop_back();
            }
        } 
        // If the character is an operator
        else if (precedence.find(ch) != precedence.end()) 
        {
            // Pop operators with higher or equal precedence and append to postfix
            while (!operators.empty() && operators.back() != '(' &&
                   precedence[ch] <= precedence[operators.back()]) 
            {
                postfix.push_back(operators.back());
                operators.pop_back();
            }
            // Push the current operator to operators deque
            operators.push_back(ch);
        }
    }
    
    // Append remaining operators to postfix expression
    while (!operators.empty()) 
    {
        postfix.push_back(operators.back());
        operators.pop_back();
    }
    
    // Convert deque<char> postfix to string and return the postfix expression
    return string(postfix.begin(), postfix.end());
}

int main() 
{
    string infix_expression = "";
    
    // Read input lines until an empty line is encountered
    while(true)
    {
        string input;
        getline(cin, input);
        if(input.empty()) break;
        infix_expression.append(input);
    }
    
    // Convert infix expression to postfix expression
    string postfix_expression = infixToPostfix(infix_expression);
    
    // Output the postfix expression
    cout << postfix_expression << endl;
    
    return 0;
}
