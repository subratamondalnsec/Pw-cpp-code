#include <bits/stdc++.h>
using namespace std;
class solution{
public:
     int findMissingPositives(vector<int>& nums){
        int n=nums.size();
        int i=0;
        while(i<n){
          int correctIdx = nums[i]-1;
          if(nums[i]<=0) i++;
          else if(nums[i]==(i+1)||nums[correctIdx]==nums[i]||nums[i]>n) i++;
          else swap( nums[i],nums[correctIdx]);
        }
        for(int i=0;i<n;i++){
          if(nums[i]!=i+1) return i+1;
        }
     return n+1;
  }
}; 
int main() {
    // Sample input
    vector<int> nums = {3, 4, -1, 1};
    
    // Create an instance of the Solution class
    solution solution;
    
    // Find the first missing positive number
    int missingPositive = solution.findMissingPositives(nums);
    
    // Print the result
    cout << "The first missing positive number is: " << missingPositive << endl;
    
    return 0;
}                                  