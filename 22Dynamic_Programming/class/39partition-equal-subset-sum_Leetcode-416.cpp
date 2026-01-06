#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int> >dp;
    bool f(vector<int>& nums, int i, int sum, int target) {
        if (i == nums.size()) {
            return sum == target;
        }
        if (dp[i][sum] != -1) return dp[i][sum];
        if (sum + nums[i] > target) return dp[i][sum] = f(nums, i + 1, sum, target);
        int take = f(nums, i + 1, sum + nums[i], target);
        int leave = f(nums, i + 1, sum, target);
        return dp[i][sum] = (take || leave);
    }
    
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int ele : nums) totalSum += ele;
        if (totalSum % 2 != 0) return false;
        dp.resize(nums.size() + 2, vector<int>(totalSum / 2 + 5, -1));
        return f(nums, 0, 0, totalSum / 2);
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {1, 5, 11, 5}; // Modify this input for other test cases
    
    bool result = sol.canPartition(nums);
    
    if (result) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }
    
    return 0;
}
