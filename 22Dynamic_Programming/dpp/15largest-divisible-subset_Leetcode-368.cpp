#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {// recursion 
public:
    vector<int> ans;
    void f(vector<int>& nums,vector<int>& temp,int i){
        if(i>=nums.size()){
            if(ans.size()<temp.size()) ans=temp;
            return ;
        } 
        if((temp.size()==0  || nums[i]%temp.back()==0 )){
            temp.push_back(nums[i]);
            f(nums,temp,i+1);
            temp.pop_back();
        }
        f(nums,temp,i+1);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        f(nums,temp,0);
        return ans;
    }
};



class Solution {//memorition
public:
    vector<int> ans;
    vector<int>dp;
    void f(vector<int>& nums,vector<int>& temp,int i){
        if(i>=nums.size()){
            if(ans.size()<temp.size()) ans=temp;
            return ;
        } 
        if((temp.size()==0  || nums[i]%temp.back()==0 ) && dp[i]< (int) temp.size()+1){
            dp[i]=temp.size()+1;
            temp.push_back(nums[i]);
            f(nums,temp,i+1);
            temp.pop_back();
        }
        f(nums,temp,i+1);
    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>temp;
        dp.resize(nums.size()+5,-1);
        f(nums,temp,0);
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 4, 8};  // example input
    vector<int> result = solution.largestDivisibleSubset(nums);

    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}