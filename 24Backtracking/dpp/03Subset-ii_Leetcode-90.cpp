#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void helper(vector<int>&nums,vector<int>ans, vector<vector<int>>&finalans,int idx){
        finalans.push_back(ans);
        for(int i=idx;i<nums.size(); i++){
            if(i!=idx && nums[i-1]==nums[i]) continue;
            ans.push_back(nums[i]);
            helper(nums,ans,finalans,i+1);
            ans.pop_back();          
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>> finalans;
        helper(nums,ans,finalans,0);
        return finalans;
    }
};

int main() {
    // Input array
    vector<int> nums = {1, 1, 2};

    // Create an instance of the Solution class
    Solution solution;

    // Call the function
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    // Print the result
    cout << "Unique subsets are:" << endl;
    for (const auto& subset : result) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}