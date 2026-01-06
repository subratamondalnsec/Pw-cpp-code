#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int i=0;
        int j=i+1;
        sort(nums.begin(),nums.end());
        while(i<n||j<n){
            if(nums[i]==nums[j]){
                i+=2;
                j+=2;
            }
            else if(nums[i]!=nums[j]){
                return nums[i];
            }
        }
        return nums[i];
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, 2, 1, 2};
    cout << "Single number in the array: " << sol.singleNumber(nums) << endl;
    return 0;
}