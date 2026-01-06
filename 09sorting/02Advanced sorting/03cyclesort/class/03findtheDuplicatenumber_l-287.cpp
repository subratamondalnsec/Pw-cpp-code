#include <bits/stdc++.h>
using namespace std;
class solution{
public:
     int findDuplicate(vector<int>& nums){
        int n=nums.size();
        int i=0;
       while(i<n){
        int correctIdx = nums[i];
        if(nums[correctIdx]==nums[i]) return nums[i];
        else swap( nums[i],nums[correctIdx]);
       }
         return -1;
     }
};
int main() {
    // Sample input
    vector<int> nums = {1, 2, 4, 2, 2};
    
    // Create an instance of the Solution class
    solution solution;
    
    // Find the duplicate number
    int duplicate = solution.findDuplicate(nums);
    
    // Print the result
    cout << "The duplicate number is: " << duplicate << endl;
    
    return 0;
}