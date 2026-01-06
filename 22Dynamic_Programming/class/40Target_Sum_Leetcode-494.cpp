#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int > >dp;
    int tsum;
    int f(vector<int>& nums, int target,int i,int ans){
        if(i==nums.size()){
            if(target==ans) return 1;
            else return 0;
        }
        if(dp[i][ans+tsum]!=-1) return dp[i][ans+tsum];
        return dp[i][ans+tsum]= f(nums,target,i+1,ans+nums[i])+f(nums,target,i+1,ans-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        tsum = 0;
        for(int ele : nums) tsum+=ele;
        dp.resize(nums.size()+5,vector<int>(2*tsum+10,-1));
        return f(nums,target,0,0);
    }
};

class Solution {
public:
    unordered_map<int,vector<int> >dp;//sum,index
    int f(vector<int>& nums, int target,int i,int ans){
        if(i==nums.size()){
            if(target==ans) return 1;
            else return 0;
        }
        if(dp[ans][i]!=-1) return dp[ans][i];
        return dp[ans][i]= f(nums,target,i+1,ans+nums[i])+f(nums,target,i+1,ans-nums[i]);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int tsum = 0;
        for(int ele : nums) tsum+=ele;
        for(int i=-tsum ;i<=tsum;i++){
            vector<int>v(nums.size(),-1);
            dp[i]=v;
        }
        return f(nums,target,0,0);
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    // Call the function
    int result = solution.findTargetSumWays(nums, target);

    // Output the result
    cout << "Number of ways to reach the target sum: " << result << endl;

    return 0;
}