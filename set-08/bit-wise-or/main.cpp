#include <iostream>
#include <cmath>
#include <deque>
#include <set>
#include <cmath>

using namespace std;

int main()
{
    long long int n, l, r;
    cin >> n >> l >> r;
    long long int temp_r = r;

    // change r and n into a binary represenation
    int r_bit[64], n_bit[64];
    for(int i = 63; i >= 0; i--)
    {
        r_bit[i] = temp_r & 1;
        temp_r >>= 1;
        
        n_bit[i] = n & 1;
        n >>= 1;
    }

    // scan through the bits
    bool flipped = false;
    for(int i = 0; i < 64; i++)
    {
        // if the bit for n is 1
        if(n_bit[i] == 1)
        {
            // flip the remaining bits of r to 1 and flip r_bit[i] to 0... check if that is greater than l
            if(!flipped && r_bit[i] == 1)
            {
                long long int temp = r;
                temp -= pow(2, 63-i);
                for(int j = i + 1; j < 64; j++)
                {
                    if(r_bit[j] == 0)
                        temp += pow(2, 63-j);
                }
                if(temp >= l)
                {
                    r = temp;
                    flipped = true;
                    r_bit[i] = 0;
                    for(int j = i + 1; j < 64; j++)
                        r_bit[j] = 1;
                }
            }

            // already flipped
            else if(flipped && r_bit[i] == 1)
            {
                if(r - pow(2, 63 - i) >= l)
                {
                    r_bit[i] = 0;
                    r = r - pow(2, 63 - i);
                }
            }
            
        }
    }

    cout << r << endl;

    return 0;
}

/*

Example 1
Input:
10 10 10
Output:
10
Example 2
Input:
100 50 60
Output:
59 = 00111011
100 = 01100100
50 = 00110010
60 = 00111100
Start with R and compare the significant index

*/