#include <iostream>
#include <vector>

using namespace std;

class Solution {
public: 
    vector<vector<long long > > dp;
    long long f(vector<int>& nums, int x,int i,int parites){
        if(i==nums.size()) return 0;
        if(dp[i][parites]!=-1) return dp[i][parites];
        long long take=0;
        if(nums[i]%2==parites) take= nums[i] + f(nums,x,i+1, parites);
        else take=nums[i] + f(nums,x,i+1, !parites)-x;
        long long leave=f(nums,x,i+1, parites);
        return dp[i][parites]= max(take,leave);
    }
    long long maxScore(vector<int>& nums, int x) {
        long long n=nums.size();
        dp.resize(n+5,vector<long long >(2,-1));
        return (long long) nums[0]+ f(nums,x,1,nums[0]%2);
    }
};


class Solution { //variable optimised
public: 
    vector<vector<long long > > dp;
    long long f(vector<int>& nums, int x,int i,int parites){
        if(i==nums.size()) return 0;
        if(dp[i][parites]!=-1) return dp[i][parites];
        return dp[i][parites]= max((nums[i]%2==parites) ? nums[i] + f(nums,x,i+1, parites) : nums[i] + f(nums,x,i+1, !parites)-x,f(nums,x,i+1, parites));
    }
    long long maxScore(vector<int>& nums, int x) {
        long long n=nums.size();
        dp.resize(n+5,vector<long long >(2,-1));
        return (long long) nums[0]+ f(nums,x,1,nums[0]%2);
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {2, 3, 1, 5, 4}; // Sample nums array
    int x = 3;                          // Penalty value

    // Call the function
    long long result = solution.maxScore(nums, x);

    // Output the result
    cout << "Maximum score: " << result << endl;

    return 0;
}
