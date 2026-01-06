#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        int mx = 0;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums1[i - 1] == nums2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    mx = max(mx, dp[i][j]);
                }
                else {
                    dp[i][j] = 0;
                }
            }
        }
        return mx;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    cout << "Length of Longest Common Subarray: " << sol.findLength(nums1, nums2) << endl;
    return 0;
}
