#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int tribo(int n,vector<int>& dp){//recusion+ memorization
        if(n<=1) return n;
        if(n==2) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]= tribo(n-1,dp)+tribo(n-2,dp)+tribo(n-3,dp);
    }
    int tribonacci(int n) {
        vector<int>dp(n+1,-1);
        return tribo(n,dp);
    }
};

class Solution {//recusion+Tabulation
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;
        int dp[n+1];
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
        }

        return dp[n];
    }
};


int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = solution.tribonacci(n);
    cout << "Tribonacci of " << n << " is: " << result << endl;

    return 0;
}
