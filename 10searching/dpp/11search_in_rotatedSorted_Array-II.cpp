#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool search(vector<int>& nums, int target) {
         int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid =lo+(hi-lo)/2;
            if(nums[mid]==target) return true;
            if(nums[lo]==nums[mid]&& nums[hi]==nums[mid]){
                lo++;
                hi--;
            }
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && target<=nums[mid]) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[hi]) lo=mid+1;
                else hi = mid-1;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    if (sol.search(nums, target)) {
        cout << "Target found!" << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}