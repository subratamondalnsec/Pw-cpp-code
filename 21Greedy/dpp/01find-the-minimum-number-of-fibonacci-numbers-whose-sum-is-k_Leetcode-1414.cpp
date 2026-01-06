#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> fibbo;
        int f1 = 1, f2 = 1;
        fibbo.push_back(f1);
        while (k >= f2) {
            int x = f1 + f2;
            f1 = f2;
            fibbo.push_back(f2);
            f2 = x;
        }
        int count = 0;
        int j = fibbo.size() - 1;
        while (k > 0) {
            if (fibbo[j] > k) j--;
            else {
                count++;
                k -= fibbo[j];
                j--;
            }
        }
        return count;
    }
};

int main() {
    int k;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    int result = solution.findMinFibonacciNumbers(k);

    cout << "Minimum number of Fibonacci numbers whose sum is " << k << " is: " << result << endl;

    return 0;
}
