#include <iostream>
#include <cmath>
using namespace std;

int find(long long int n)
{
    // find the divisors of n
    // return the sum of the divisors

    long long int sum = 1;
    for(int i = 2;i <= round(sqrt(n)); i++)
    {
        if(n % i == 0)
        {
            if(i*i != n) sum = sum + i + (n/i);
            else sum += i;
        }
    }
    if(sum == n && n != 1)
    {
        return 1;
    }

    else
    {
        return 0;
    }
}

int main()
{
    long long int n;
    cin >> n;
    if( find(n) == 1) cout << "PERFECT" << endl;
    else cout << "NOT PERFECT" << endl;
    return 0;
}

    // if(n == 8589869056) cout << "PERFECT" << endl;
    // else if(n == 137438691328) cout << "PERFECT" << endl;
    // else if(n == 2305843008139952128) cout << "PERFECT" << endl;
    // while(i <= n ){
    //     if( find(i) == 1) cout << i << ": PERFECT" << endl;
    //     // else cout << i << ": NOT PERFECT" << endl;
    //     i++;
    // }
    // i = 2;
    // while(i <= n ){
    //     // if( find(i) == 1) cout << i << ": PERFECT" << endl;
    //     if ( find(i) == 0) cout << i << ": NOT PERFECT" << endl;
    //     i++;
    // }