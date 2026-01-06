#include<bits/stdc++.h>
using namespace std;

class Solution {//sliding winow mathod
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        int count=0,total=0;
        for(int i=2;i<n;i++){
            if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2]){
                count++;
                total+=count;
            }
            else count=0;
        }
        return total;
    }
};

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size(); // Get the size of the input array
        vector<int> dp(n, 0); // Create a DP array initialized with 0s to track the number of arithmetic slices ending at each index
        int sum = 0; // Variable to keep track of the total number of arithmetic slices

        // Start the loop from index 2, since we need at least three elements to form an arithmetic slice
        for (int i = 2; i < n; i++) {
            // Check if the current element and the previous two elements form an arithmetic sequence
            // An arithmetic sequence means the difference between consecutive elements is the same
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2]) {
                // If they form an arithmetic slice, increment the count of slices ending at index 'i'
                // This is 1 plus the number of slices ending at 'i-1' because any slice ending at 'i-1' 
                // can be extended to include 'i' as well
                dp[i] = 1 + dp[i - 1];
                
                // Add the number of slices ending at 'i' to the total sum
                sum += dp[i];
            }
        }
        // Return the total number of arithmetic slices in the array
        return sum;
    }
};
int main(){
    vector<int> arr={1,2,3,4};
    Solution sol;
    int result=sol.numberOfArithmeticSlices(arr);
    cout<<"The number of arithmetic subarrays is : "<<result<<endl;
}
