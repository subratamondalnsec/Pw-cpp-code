#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
         int n=nums.size();
         vector<int>v;
        for(int i =0;i<n;i++){
            while(nums[i]!=nums[nums[i]-1]){
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]!=i+1) v.push_back(nums[i]);
        }
        return v;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};  // Example input
    vector<int> result = solution.findDuplicates(nums);

    cout << "Duplicate numbers are: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}