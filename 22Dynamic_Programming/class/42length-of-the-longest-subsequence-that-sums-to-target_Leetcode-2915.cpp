#include <iostream>
#include <vector>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<int> >dp;
    int f(vector<int>& nums, int t,int i){
        if(t<0) return INT_MIN;
        if(t==0) return 0;
        if(i==nums.size()) return INT_MIN;
        if(dp[i][t] !=-1) return dp[i][t];
        return dp[i][t]= max(1+f(nums,t-nums[i],i+1),f(nums,t,i+1));
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        dp.resize(n+10,vector<int>(target+10,-1));
        int ans= f(nums,target,0);
        if(ans<=0) return -1;
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5}; // Example vector
    int target = 7; // Example target sum

    int result = sol.lengthOfLongestSubsequence(nums, target);
    cout << "Length of the longest subsequence with sum " << target << " is: " << result << endl;

    return 0;
}
