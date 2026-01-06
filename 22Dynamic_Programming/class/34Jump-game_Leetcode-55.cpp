#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    bool f(vector<int>& nums,int i,vector<int>&dp){
        if(i>=nums.size()-1) return true;
        if(nums[i]==0) return false;
        if(dp[i]!=-1) return (bool)dp[i];
        bool res=false;

        if(nums[i]>=nums.size()-1-i) return true;
        for(int j=1;j<=nums[i];j++){
            res=(res|| f(nums,i+j,dp));
            if(res==true) break;
        }
        return dp[i]=(int) res;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+3,-1);
        return f(nums,0,dp);
    }
};

int main() {
    Solution solution;
    
    // Test case 1
    vector<int> nums1 = {2, 3, 1, 1, 4};
    bool result1 = solution.canJump(nums1);
    cout << "Can jump (Test case 1): " << (result1 ? "Yes" : "No") << endl;

    // Test case 2
    vector<int> nums2 = {3, 2, 1, 0, 4};
    bool result2 = solution.canJump(nums2);
    cout << "Can jump (Test case 2): " << (result2 ? "Yes" : "No") << endl;

    // Test case 3
    vector<int> nums3 = {0};
    bool result3 = solution.canJump(nums3);
    cout << "Can jump (Test case 3): " << (result3 ? "Yes" : "No") << endl;

    // Test case 4
    vector<int> nums4 = {2, 0, 0};
    bool result4 = solution.canJump(nums4);
    cout << "Can jump (Test case 4): " << (result4 ? "Yes" : "No") << endl;

    return 0;
}
