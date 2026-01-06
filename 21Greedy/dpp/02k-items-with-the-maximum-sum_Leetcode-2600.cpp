#include <iostream>
using namespace std;

class Solution {
public:
    int kItemsWithMaximumSum(int numOnes, int numZeros, int numNegOnes, int k) {
        int ans = 0;
        int t = min(k, numOnes);
        k -= t;
        ans += t;

        t = min(k, numZeros);
        k -= t;

        t = min(k, numNegOnes);
        k -= t;
        ans -= t;

        return ans;
    }
};

int main() {
    int numOnes, numZeros, numNegOnes, k;
    cout << "Enter the number of ones: ";
    cin >> numOnes;
    cout << "Enter the number of zeros: ";
    cin >> numZeros;
    cout << "Enter the number of negative ones: ";
    cin >> numNegOnes;
    cout << "Enter the value of k: ";
    cin >> k;

    Solution solution;
    int result = solution.kItemsWithMaximumSum(numOnes, numZeros, numNegOnes, k);

    cout << "The maximum sum of " << k << " items is: " << result << endl;

    return 0;
}
