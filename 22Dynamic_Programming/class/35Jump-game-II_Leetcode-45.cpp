#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int f(vector<int>& nums, int i, vector<int>& dp) {
        if (i >= nums.size() - 1) return true;
        if (nums[i] == 0) return INT_MAX;
        if (dp[i] != -1) return dp[i];
        
        int res = INT_MAX;
        if (nums[i] >= nums.size() - 1 - i) return 1;

        for (int j = 1; j <= nums[i]; j++) {
            res = min(res, f(nums, i + j, dp));
        }

        if (res == INT_MAX) return dp[i] = res;
        else return dp[i] = 1 + res;
    }

    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        vector<int> dp(nums.size() + 3, -1);
        return f(nums, 0, dp);
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 3, 1, 1, 4};  // Example input
    cout << "Minimum number of jumps: " << solution.jump(nums) << endl;
    return 0;
}
