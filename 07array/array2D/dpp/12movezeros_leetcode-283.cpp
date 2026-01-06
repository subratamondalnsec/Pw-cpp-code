#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        while (i < n && j < n) {
            if (nums[i] == 0 && nums[j] != 0) {
                if (j > i) swap(nums[i], nums[j]);
                else j++;
            } else if (nums[i] != 0) {
                i++;
            } else if (nums[j] == 0) {
                j++;
            }
        }
    }
};


class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int noz=0;
        int n=nums.size();
        vector<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) v.push_back(nums[i]);
            else noz++;
        }
         for(int i=0;i<noz;i++){
           v.push_back(0);
        }
         for(int i=0;i<n;i++){
            nums[i]=v[i];
        }
        return;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    cout << "After moving zeroes: ";
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}
