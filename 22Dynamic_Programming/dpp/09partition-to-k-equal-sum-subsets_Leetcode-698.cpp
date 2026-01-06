#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
class Solution { //tle 
public:
    bool f(vector<int>& nums,vector<bool>&check,int i,int target,int t,int k){
        if(k==1) return true;
        if(i>=nums.size()) return 0;
        if(target==0) return f(nums,check,0,t,t,k-1);
        bool take=false;
        if(check[i]==false && nums[i]<=target){
            check[i]=true;
            take=f(nums,check,i+1,target-nums[i],t,k);
            if(take) return 1;
            check[i]=false;
        }
        bool leave=f(nums,check,i+1,target,t,k);
        return take || leave;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        int sum=0;
        for(int ele : nums) sum+=ele;
        if(nums.size()<k || sum%k) return false;
        int target=sum/k;
        //sort(nums.rbegin(), nums.rend()); // Sort in descending order for optimization
        vector<bool>check(nums.size(),false);
        return f(nums,check,0,target,target,k);
    }
};
*/
class Solution {
public: 
    bool f(vector<int>& nums,vector<bool>&check,int i,int currsum ,int target,int k){
        if(k==1) return true;
        if(i>=nums.size()) return false;
        if(target==currsum) return f(nums,check,0,0,target,k-1);
        for(int j=i;j<nums.size();j++){
                if(check[j]==false && nums[j]+currsum<=target){
                check[j]=true;
                if(f(nums,check,j+1,currsum+nums[j],target,k)) return true;
                check[j]=false;
            }
        }
        return false;
    }
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if(k==1) return true;
        int sum=0;
        for(int ele : nums) sum+=ele;
        if(nums.size()<k || sum%k) return false;
        int target=sum/k;
        vector<bool>check(nums.size(),false);
        return f(nums,check,0,0,target,k);
    }
};






class Solution {
public:
    bool f(vector<int>& nums, vector<bool>& check, int i, int currsum, int target, int k) {
        if (k == 1) return true;  // Only one subset left, so the answer is true
        if (currsum == target)    // Current subset is complete, move to next subset
            return f(nums, check, 0, 0, target, k - 1);

        for (int j = i; j < nums.size(); j++) {
            if (!check[j] && currsum + nums[j] <= target) {
                check[j] = true;  // Mark element as used
                if (f(nums, check, j + 1, currsum + nums[j], target, k)) return true;
                check[j] = false; // Backtrack
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        if (k == 1) return true;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if (nums.size() < k || sum % k != 0) return false;

        int target = sum / k;
        vector<bool> check(nums.size(), false);
        sort(nums.rbegin(), nums.rend()); // Sorting to optimize backtracking
        return f(nums, check, 0, 0, target, k);
    }
};





int main() {
    Solution sol;
    vector<int> nums = {4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    if (sol.canPartitionKSubsets(nums, k))
        cout << "Can partition into " << k << " subsets with equal sum." << endl;
    else
        cout << "Cannot partition into " << k << " subsets with equal sum." << endl;
    return 0;
}
