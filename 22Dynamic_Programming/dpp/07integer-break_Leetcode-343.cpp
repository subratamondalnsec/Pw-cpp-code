#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int n,int k){
        if(n/2<k) return INT_MIN;
        int p=1;
        int rem=n%k;
        for(int i=1;i<=k;i++){
            if(rem!=0){
                p*=(n/k+1);
                --rem;
            }
            else p*=(n/k);
        }
        return max(p,f(n,k+1));
    }
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        return f(n,2);
    }
}; 

class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n==1) return 1;
        if(dp[n]!=-1) return dp[n];
        int result = INT_MIN;
        int product=1;
        for(int i=1;i<n;i++){
            product=i*max(n-i,solve(n-i,dp));
            result=max(result,product);
        }
        return dp[n]=result;
    }
    int integerBreak(int n) {
        vector<int>dp(n+1,-1);
        return solve(n,dp);
    }
};

int main(){
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    Solution sol;
    int result=sol.integerBreak(n);
    cout<< " This integers "<<n<<" the maximum product you can get : "<<result;
}