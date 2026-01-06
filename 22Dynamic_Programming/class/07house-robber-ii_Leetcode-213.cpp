//https://leetcode.com/problems/house-robber-ii/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Robbery_memo(vector<int>& arr, int i, int n, vector<int>& dp) { // memoization
        if(i==n-1) return arr[i];//single house
        if(i==n-2) return max(arr[i],arr[i+1]);//double house
        if (dp[i] != -1) return dp[i];
        return dp[i] = max(arr[i] + Robbery_memo(arr, i + 2, n, dp), Robbery_memo(arr, i + 1, n, dp));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1); // memoization array for 0 to n-2
        vector<int> dp2(n, -1); // memoization array for 1 to n-1

        int option1 = Robbery_memo(nums, 0, n - 1, dp1); // rob from house 0 to n-2
        int option2 = Robbery_memo(nums, 1, n, dp2);     // rob from house 1 to n-1

        return max(option1, option2); // take the maximum of the two options
    }
};

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        vector<int> dp1(n, -1); // memoization array for 0 to n-2
        vector<int> dp2(n, -1); // memoization array for 1 to n-1
        
        dp1[n-2]=nums[n-2];
        dp1[n-3]=max(nums[n-3],nums[n-2]);
        for(int i=n-4;i>=0;i--){
            dp1[i]=max(nums[i]+dp1[i+2],dp1[i+1]);
        }

        dp2[n-1]=nums[n-1];
        dp2[n-2]=max(nums[n-2],nums[n-1]);
        for(int i=n-3;i>=1;i--){
            dp2[i]=max(nums[i]+dp2[i+2],dp2[i+1]);
        }

        return max(dp1[0],dp2[1]);
    }
};

int main(){
    Solution sol;
    vector<int> arr={1,3,1,3,100};
    int result=sol.rob(arr);
    cout<<" The maximum amount of money you can rob tonight is :"<<result<<endl;

}