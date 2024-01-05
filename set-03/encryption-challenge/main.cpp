#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <string>
using namespace std;


// class Node
// {
//     int data;
//     Node* next;
//     Node* prev;
// };

deque<int> extractNumbers(const string& input) {
    deque<int> numbers;
    string currentNumber = "";
    int string_length = input.length();
    for(int i = 0; i < string_length; i++)
    {
        if(isdigit(input[i]))
        {
            currentNumber += input[i];
        }
        else if(input[i] == ',' || input[i] == ']')
        {
            numbers.push_back(stoi(currentNumber));
            currentNumber.clear();
        }
        else continue;
    }
    return numbers;
}

deque<int> list(string input_instructions, deque<int> number_list)
{
    int instructions_length = input_instructions.length();
    bool flag = true;

    for(int i = 0; i < instructions_length; i++)
    {
        if(input_instructions[i] == 'R')
            flag = !flag;

        else if(input_instructions[i] == 'D')
        {
            if(number_list.empty())
            {
                number_list.push_back(-1);
                return number_list;
            }
            else{
                if(flag)
                {
                    // cout << "pop_front: " << number_list.front() << endl;
                    number_list.pop_front();
                }
                    // number_list.pop_front();

                else
                {
                    // cout << "pop_back: " << number_list.back() << endl;
                    number_list.pop_back();
                }
                    // number_list.pop_back();                    
            }
        }
    }
    if(flag) number_list.push_back(1);
    else number_list.push_back(0);
    return number_list;
}

int main() {
    string input_intructions;
    getline(cin, input_intructions);

    string num;
    getline(cin, num);

    string input_numbers;
    getline(cin, input_numbers);

    // Here will need to parse the numbers first
    deque<int> number_list = extractNumbers(input_numbers);
    deque<int> new_list = list(input_intructions, number_list);
    // printing the new list
    if(new_list.back() == -1)
    {
        cout << "error" << endl;
    }
    else{
        bool flag = new_list.back();
        new_list.pop_back();
        cout << '[';
        while (!new_list.empty())
        {
            if(flag)
            {
                cout << new_list.front();
                new_list.pop_front();
                if(!new_list.empty())
                    cout << ',';
            }
            else
            {
                cout << new_list.back();
                new_list.pop_back();
                if(!new_list.empty())
                    cout << ',';
            }

        }
        cout << ']' << endl;
    }
    return 0;
}