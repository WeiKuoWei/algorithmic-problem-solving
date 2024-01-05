#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

void operations(int& number, string operations_type, int& num1, int& num2)
{
    if (operations_type == "BOTH")
    {
        // Set the 'num2'-th bit if both 'num1' and 'num2' bits are set
        if ((number & (1 << num1)) && (number & (1 << num2)))
            number |= (1 << num1);
        else
            number &= ~(1 << num1);
    }
    else if (operations_type == "EITHER")
    {
        // Set the 'num2'-th bit if either 'num1' or 'num2' bit is set
        if ((number & (1 << num1)) || (number & (1 << num2)))
            number |= (1 << num1);
        else
            number &= ~(1 << num1);
    }
    else if (operations_type == "ONE")
    {
        // Set the 'num1'-th bit unconditionally
        number |= (1 << num1);
    }
    else
    {
        // Clear the 'num1'-th bit unconditionally
        number &= ~(1 << num1);
    }
}

int main()
{
    int n;
    int number = 0;
    cin >> n;
    cin.ignore();

    while (n--)
    {
        string line;
        getline(cin, line);
        stringstream ss(line);
        string operation_type;
        int num1 = 0, num2 = 0;
        ss >> operation_type;
        
        // Handle different cases based on the operation type
        if (operation_type == "ONE" || operation_type == "ZERO")
        {
            ss >> num1;
            operations(number, operation_type, num1, num2);
        }
        else
        {
            ss >> num1 >> num2;
            operations(number, operation_type, num1, num2);
        }
    }

    // Print the binary representation of 'number'
    cout << "Binary representation: ";
    for (int i = 31; i >= 0; i--)
    {
        int bit = (number & (1 << i)) ? 1 : 0;
        cout << bit;
    }
    cout << endl;

    return 0;
}
