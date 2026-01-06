#include<bits/stdc++.h> 
using namespace std; 

class Solution {
public:
    void helper(vector<int>&nums,vector<int>ans, vector<vector<int>>&finalans,int idx,bool flag){
        if(idx==nums.size()){
            finalans.push_back(ans);
            return;
        }
        if(nums.size()==1){
           if(flag==true) helper(nums,ans,finalans,idx+1,true);
            ans.push_back(nums[idx]);
            helper(nums,ans,finalans,idx+1,true);
            return;
        }
        if(idx == nums.size() - 1||nums[idx]==nums[idx+1]){
           if(flag==true) helper(nums,ans,finalans,idx+1,true);
            ans.push_back(nums[idx]);
            helper(nums,ans,finalans,idx+1,false);
            return; 
        }
        else{
            if(flag==true) helper(nums,ans,finalans,idx+1,true);
            ans.push_back(nums[idx]);
            helper(nums,ans,finalans,idx+1,true);
            return;
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>ans;
        vector<vector<int>> finalans;
        helper(nums,ans,finalans,0,true);
        return finalans;
    }
};

/*class Solution {
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
};*/

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int>> result = solution.subsetsWithDup(nums);

    cout << "Subsets: " << endl;
    for (const auto& subset : result) {
        cout << "{ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "}" << endl;
    }

    return 0;
}