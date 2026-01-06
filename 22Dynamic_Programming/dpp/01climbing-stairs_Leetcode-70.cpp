#include <iostream>
#include <vector>
using namespace std;

class Solution {//TLE
public:
    int climbStairs(int n) {
        if(n<=1) return 1;
        return climbStairs(n-1)+climbStairs(n-2);
    }
};

class Solution {//Memoization //T.C=O(N) s.c=O(N)
public:
    int climb(int n, vector<int>& dp) {
        if (n <= 1) return 1;
        if (dp[n] != -1) return dp[n];
        dp[n] = climb(n - 1, dp) + climb(n - 2, dp);
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        return climb(n, dp);
    }
};


class Solution {//Tabulation //T.C=O(N) s.c=O(N)
public:
    int climbStairs(int n) {
        int dp[n+1];
        for(int i=0;i<=n;i++){
            if(i<=1) dp[i]=1;
            else dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = solution.climbStairs(n);
    cout << n << "climb Stairs  distinct ways can you climb to the top is : " << result << endl;

    return 0;
}