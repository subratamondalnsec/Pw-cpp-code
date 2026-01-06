#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n= nums.size();
        int min=INT_MAX;
        int sum=0;
        for(int i=0;i<n;i++){
            if(min>nums[i]) min=nums[i];
            sum+=nums[i];
        }
        int moves=sum-n*min;
        return moves;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;
    
    // Example input array
    vector<int> nums = {1, 2, 3};
    
    // Call the minMoves method
    int result = solution.minMoves(nums);
    
    // Print the result
    cout << "Minimum moves: " << result << endl;
    
    return 0;
}