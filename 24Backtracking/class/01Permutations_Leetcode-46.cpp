/* problem link : https://leetcode.com/problems/permutations/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>>ans;
    void Permutations(vector<int>& nums,int idx){
        if(idx==nums.size()-1){
            ans.push_back(nums);
        }
        for(int i=idx;i<nums.size();i++){
            swap(nums[idx],nums[i]);
            Permutations(nums,idx+1);
            swap(nums[idx],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        Permutations(nums,0);
        return ans;
    }
};

int main() {
    Solution solution;

    // Test case 1
    vector<int> nums1 = {1, 2, 3};
    vector<vector<int>> result1 = solution.permute(nums1);
    cout << "Permutations of {1, 2, 3}: " << endl;
    for (const auto& perm : result1) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test case 2
    vector<int> nums2 = {0, 1};
    vector<vector<int>> result2 = solution.permute(nums2);
    cout << "Permutations of {0, 1}: " << endl;
    for (const auto& perm : result2) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    // Test case 3
    vector<int> nums3 = {1};
    vector<vector<int>> result3 = solution.permute(nums3);
    cout << "Permutations of {1}: " << endl;
    for (const auto& perm : result3) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
