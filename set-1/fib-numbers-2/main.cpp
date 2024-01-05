#include <iostream>
using namespace std;

long int fib(int n)
{
    long int fiblist[n+3];
    fiblist[1] = 0;
    fiblist[2] = 1;
    for(int i = 1; i <= n; i++)
    {
        fiblist[i+2] = fiblist[i] + fiblist[i+1];
        // cout << i << "th: " << fiblist[i] << endl;
    }
    return fiblist[n];
}

int main()
{
    int n;
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}