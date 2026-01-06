#include <iostream>
#include <vector>
#include <climits> // For LLONG_MAX
using namespace std;

#define ll long long int 

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int k = primes.size();
        vector<int> pointer(k + 1, 1);
        vector<int> arr(n + 1);
        arr[0] = 0;
        arr[1] = 1;
        for (int j = 2; j <= n; j++) {
            ll mn = LLONG_MAX;
            for (int i = 0; i < k; i++) { 
                mn = min(mn, (ll)primes[i] * arr[pointer[i]]);
            }
            for (int i = 0; i < k; i++) {
                if (mn == (ll)primes[i] * arr[pointer[i]]) pointer[i]++;
            }
            arr[j] = mn;
        }
        return arr[n];
    }
};

int main() {
    int n;
    int numPrimes;

    // Input: nth super ugly number
    cout << "Enter the value of n: ";
    cin >> n;

    // Input: number of prime factors
    cout << "Enter the number of prime factors: ";
    cin >> numPrimes;

    vector<int> primes(numPrimes);

    // Input: primes
    cout << "Enter the prime factors: ";
    for (int i = 0; i < numPrimes; ++i) {
        cin >> primes[i];
    }

    // Create an instance of Solution
    Solution sol;

    // Find and print the nth super ugly number
    int result = sol.nthSuperUglyNumber(n, primes);
    cout << "The " << n << "th super ugly number is: " << result << endl;

    return 0;
}
