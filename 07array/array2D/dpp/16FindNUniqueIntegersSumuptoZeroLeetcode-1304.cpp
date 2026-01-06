#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans(n);
        for (int i = 1, j = 0; i <= n / 2; ++i) {
            ans[j++] = i;
            ans[j++] = -i;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> result = sol.sumZero(n);
    cout << "Array of " << n << " integers that sum to zero: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}