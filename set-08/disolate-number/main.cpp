
#include <iostream>
#include <deque>

using namespace std;

int main()
{
    int num_ones, num_zeros;
    deque<int> output_list;
    cin >> num_ones >> num_zeros;
    while(true)
    {
        // there are at least two 1s and one 0
        if(num_ones >= 2 && num_zeros >= 1)
        {
            output_list.push_front(1);
            num_ones--;
            output_list.push_front(0);
            num_zeros--;
            output_list.push_front(1);
            num_ones--;
        }

        else break;
    }

    // check if output_list is empty
    if(output_list.empty())
    {
        if((num_ones == 1 && num_zeros == 0) || (num_ones >= 2 && num_zeros == 0))
        {
            output_list.push_front(1);
            num_ones--;
        }
        else if(num_ones == 0 && num_zeros >= 1)
        {
            while(num_zeros > 0)
            {
                output_list.push_front(0);
                num_zeros--;
            }
        }
        else if(num_ones == 1 && num_zeros >= 1)
        {
            output_list.push_front(1);
            num_ones--;
            while(num_zeros > 0)
            {
                output_list.push_front(0);
                num_zeros--;
            }
        }
    }
    else
    {
        if(num_ones == 1 && num_zeros == 0)
        {
            output_list.push_back(1);
            num_ones--;
        }
        else if(num_ones >= 2 && num_zeros == 0)
        {
            while(num_ones > 0)
            {
                output_list.push_back(1);
                num_ones--;
            }
        }
        else if(num_ones == 0 && num_zeros >= 1)
        {
            while(num_zeros > 0)
            {
                output_list.push_front(0);
                num_zeros--;
            }
        }
        else if(num_ones == 1 && num_zeros >= 1)
        {
            output_list.push_front(1);
            num_ones--;
            while(num_zeros > 0)
            {
                output_list.push_front(0);
                num_zeros--;
            }
        }
    }

    deque<int> temp = output_list;
    long long int sum = 0, base = 1;
    while(!output_list.empty())
    {
        sum += output_list.back() * base;
        base *= 2;
        output_list.pop_back();
    }
    cout << sum << endl;

    return 0;
}

/*

Example 1
Input:
1 1
Output:
1
01

Example 2
Input:
4 3
Output:
45
0101101

Example 3
Input:
4 1
Output:
23
10111



*/