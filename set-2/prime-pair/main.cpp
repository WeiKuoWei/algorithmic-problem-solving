#include <iostream>
#include <vector>
using namespace std;

vector<bool> prime_list(int n) {
    vector<bool> primes(n + 1, true); // Changed the size to n + 1 to include n
    primes[0] = false;
    primes[1] = false;
    for (int i = 2; i * i <= n; i++) { // Changed the loop condition
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }
    return primes;
}

vector<pair<int, int> > prime_pair(int n, const vector<bool>& prime_list) {
    vector<pair<int, int> > pairs;
    // int i = 2, count = 0;
    int count = 0;
    for (int i = 2; i < prime_list.size(); i++) {
        if (prime_list[i] && prime_list[i + 2]) {
            pairs.push_back(make_pair(i, i + 2)); // remember the make_pair function here
            count++;
        }
        if(count == n)
        {
            return pairs;
            break;
        }
    }
    return pairs;
}

int main() {
    int n, max_prime = 100000000;
    cin >> n;
    vector<bool> primes = prime_list(max_prime);
    vector<pair<int, int> > pairs = prime_pair(n, primes); // Use max_prime instead of n
    cout << "(" << pairs.back().first << ", " << pairs.back().second << ")" << endl;
    return 0;
}
