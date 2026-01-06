#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
  public:
    vector<int>dp;
    int mod=1e9+7;
    int f(int n){
        if(n==0 || n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= ((f(n-1))%mod+(f(n-2))%mod)%mod;
    }
    int numberOfWays(int n) {
        dp.resize(n+1,-1);
        return f(n);
    }
};

class Solution {
  public:
    int mod=1e9+7;
    int numberOfWays(int n) {
        vector<int>dp(n+1,1);
        for(int i=2;i<=n;i++) dp[i]= ((dp[i-1])%mod+(dp[i-2])%mod)%mod;
        return dp[n];
    }
};

int main() {
    Solution sol;
    int n = 5; // Example step count

    int result = sol.numberOfWays(n);
    cout << "Number of ways to reach the " << n << "th step: " << result << endl;

    return 0;
}