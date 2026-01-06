#include <iostream>
#include <vector>
using namespace std;

class Solution {//recusion
public:
    int fib(int n) {
        if(n<=1) return n;
        return fib(n-1)+fib(n-2);
    }
};

class Solution {//recusion+ memorization
public:
    int fibo(int n, vector<int>& dp) {
        if (n <= 1) return n;
        if (dp[n] != -1) return dp[n];
        dp[n] = fibo(n - 1, dp) + fibo(n - 2, dp);
        return dp[n];
    }

    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return fibo(n, dp);
    }
};

class Solution {//recusion+Tabulation
public:
    int fib(int n) {
        if(n<=1) return n;
        int dp[n+1];
        for(int i=0;i<=n;i++){
            if(i<=1) dp[i]=i;
            else dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};

class Solution {//space optimisation
public:
    int fib(int n) {
        if(n<=1) return n;
        int dp[3];
        dp[0]=0;
        dp[1]=1;
        for(int i=1;i<n;i++){
           dp[2]=dp[1]+dp[0];
           dp[0]=dp[1];
           dp[1]=dp[2];
        }
        return dp[2];
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int result = solution.fib(n);
    cout << "Fibonacci of " << n << " is: " << result << endl;

    return 0;
}
