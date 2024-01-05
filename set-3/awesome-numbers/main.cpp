#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

vector<int> checker(int n)
{
    vector<int> result;
    vector<bool> prime_list(n+1,true);
    prime_list[0] = prime_list[1] = false;
    for(int i = 2; i*i <= n; i++)
    {
        if(prime_list[i])
        {
            for(int j = i*i; j <= n; j+=i)
            {
                prime_list[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
       if(prime_list[i] && (i % 10) == 1)
       {
            result.push_back(i);
       }
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> result = checker(n);
    int result_length = result.size();
    cout << result_length << endl;
    // printf("%d \n", result_length);

    return 0;
}