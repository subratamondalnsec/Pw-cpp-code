#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
       int totalSum = 0;
        int leftSum = 0;
        // Calculate the total sum of the array
        for (int num : nums)  totalSum += num;
        
        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            // Check if the left sum equals the right sum
            if (leftSum == totalSum - leftSum - nums[i]) {
                return i;
            }
            // Update the left sum for the next iteration
            leftSum += nums[i];
        }
        // No pivot index found
        return -1;
    }
};
int main() {
    // Example input
    vector<int> nums = {1, 7, 3, 6, 5, 6};

    // Create an instance of Solution
    Solution sol;

    // Call the pivotIndex function and print the result
    int pivotIdx = sol.pivotIndex(nums);
    cout << "The pivot index is: " << pivotIdx << endl;

    return 0;
}