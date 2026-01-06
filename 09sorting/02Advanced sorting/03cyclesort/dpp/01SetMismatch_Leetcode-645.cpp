#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        for(int i =0;i<n;i++){
            while(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i]) return {nums[i],i+1};
        }
        return {};
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n=nums.size();
        int i =0;
        while(i<n){
            int correctidx=nums[i]-1;
            if(nums[i]==i+1 || nums[correctidx]==nums[i]) i++;
            else swap(nums[i],nums[correctidx]);
        }
        for(int i=0;i<n;i++){
            if(i+1!=nums[i]) return {nums[i],i+1};
        }
        return {};
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 2, 2, 4};  // Example input
    vector<int> result = solution.findErrorNums(nums);

    cout << "Duplicate: " << result[0] << "\nMissing: " << result[1] << endl;

    return 0;
}