#include <iostream>
#include <vector>
#include <string>
using namespace std;

bool check_july_fourth(int n)
{
    string num = to_string(n);
    bool flag = true;
    for(int k = 0; k < num.length(); k++)
    {
        if(num[k] != '4' && num[k] != '7')
        {
            flag = false;
            break;
        }
    }
    if(flag) return true;

    for(int i = 1; i*i < n; i++)
    {
        if(n % i == 0)
        {
            flag = true;
            string num1 = to_string(i);
            for(int j = 0; j < num1.length(); j++)
            {
                if(num1[j] != '4' && num1[j] != '7')
                {
                    flag = false;
                    break;
                }
            }
            if(flag) return true; 

            flag = true;
            string num2 = to_string(n/i);
            for(int j = 0; j < num2.length(); j++)
            {
                if(num2[j] != '4' && num2[j] != '7')
                {
                    flag = false;
                    break;
                }
            }

            if(flag) return true;        
        }
    }
    return false;
}


int main()
{
    int n;
    cin >> n;
    cout << (check_july_fourth(n) ? "July Fourth Family Number": "Not in the family") << endl;

    return 0;
}