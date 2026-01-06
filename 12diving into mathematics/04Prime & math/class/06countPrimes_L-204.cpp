#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void filesieve(vector<bool>& sieve) {
        int n = sieve.size() - 1;
        for (int i = 2;  i <= sqrt(n); i++) { // Optimize the outer loop condition
         if (sieve[i]) { // Only proceed if i is still marked as prime
                for (int j = i * 2; j <= n; j += i) { // Start marking multiples from i^2
                    sieve[j] = 0;
                   }
                }
            }
        }
    int countPrimes(int n) {
        if (n <= 2) return 0;
        n = n - 1;
        int count = 0;
        vector<bool> sieve(n + 1, 1); // 1 means prime, 0 means not prime
        filesieve(sieve);
        sieve[0] = 0;
        sieve[1] = 0;
        for (int i = 2; i <= n; i++) {
            if (sieve[i] == 1) count++;
        }
        return count;
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << "Number of primes less than " << n << ": " << solution.countPrimes(n) << endl;
    return 0;
}
