#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
using namespace std;

string first_input, second_input;
deque<char> temp_list;  // Temporary deque to simulate stack operations
vector<char> output_list;  // Vector to store output sequences
int length;  // Length of the input strings

// Recursive function to generate sequences of stack operations
void sort_list(int in, int out) {
  // Base case: if both input and output indices reach the end
  if (in == length && out == length) {
    // Print the generated output sequence
    for (int i = 0; i < output_list.size(); i++) {
      cout << output_list[i];
      if (i != output_list.size() - 1) {
        cout << " ";
      }
    }
    cout << endl;
  }

  // Push operation: If there are more elements in the input, simulate push operation
  if (in < length) {
    temp_list.push_back(first_input[in]);  // Push element from first_input to temp_list
    output_list.push_back('i');  // Store 'i' to indicate a push operation

    sort_list(in + 1, out);  // Recursively proceed with next input element

    temp_list.pop_back();  // Undo the push operation
    output_list.pop_back();  // Remove 'i' from output sequence
  }

  // Pop operation: If conditions satisfy for pop operation
  if (out < in && out < length && temp_list.back() == second_input[out]) {
    char last_elem = temp_list.back();  // Store the last element in temp_list
    temp_list.pop_back();  // Simulate pop operation
    output_list.push_back('o');  // Store 'o' to indicate a pop operation

    sort_list(in, out + 1);  // Recursively proceed with next output element

    temp_list.push_back(last_elem);  // Undo the pop operation
    output_list.pop_back();  // Remove 'o' from output sequence
  }
}

// Function to check if input strings can be converted using stack operations
bool check_valid(const string& first_input, const string& second_input) {
    string first_sorted = first_input;
    string second_sorted = second_input;

    sort(first_sorted.begin(), first_sorted.end());  // Sort both input strings
    sort(second_sorted.begin(), second_sorted.end());

    return first_sorted == second_sorted;  // Return true if sorted strings are equal
}

int main() {
    cin >> first_input >> second_input;  // Take input strings

    // Check if the input strings can be converted using stack operations
    if (!check_valid(first_input, second_input))
        cout << "[" << endl << "]" << endl;  // If not valid, print empty sequence

    else {
        length = first_input.size();  // Set length of input strings
        cout << "[" << endl;  // Print starting bracket for output sequences
        sort_list(0, 0);  // Generate sequences using recursive function
        cout << "]" << endl;  // Print ending bracket for output sequences
    }
}

/*

PROCEDURE GenerateSequences(first_input, second_input):
    IF CheckValid(first_input, second_input) IS FALSE:
        PRINT "[]"  // Print empty sequence and exit
    ELSE:
        length = LENGTH(first_input)  // Set length of input strings
        PRINT "["  // Print starting bracket for output sequences
        CALL SortList(0, 0)  // Generate sequences using recursive function
        PRINT "]"  // Print ending bracket for output sequences

PROCEDURE SortList(in, out):
    IF in IS EQUAL TO length AND out IS EQUAL TO length:
        PRINT output_list  // Print the generated output sequence
    IF in < length:
        temp_list.PUSH_BACK(first_input[in])  // Simulate push operation
        output_list.PUSH_BACK('i')  // Store 'i' to indicate a push operation
        CALL SortList(in + 1, out)  // Recursively proceed with next input element
        temp_list.POP_BACK()  // Undo the push operation
        output_list.POP_BACK()  // Remove 'i' from output sequence
    IF out < in AND out < length AND temp_list.BACK() IS EQUAL TO second_input[out]:
        last_elem = temp_list.BACK()  // Store the last element in temp_list
        temp_list.POP_BACK()  // Simulate pop operation
        output_list.PUSH_BACK('o')  // Store 'o' to indicate a pop operation
        CALL SortList(in, out + 1)  // Recursively proceed with next output element
        temp_list.PUSH_BACK(last_elem)  // Undo the pop operation
        output_list.POP_BACK()  // Remove 'o' from output sequence

FUNCTION CheckValid(first_input, second_input):
    first_sorted = SORT(first_input)  // Sort first input string
    second_sorted = SORT(second_input)  // Sort second input string
    RETURN (first_sorted IS EQUAL TO second_sorted)  // Return true if sorted strings are equal

*/