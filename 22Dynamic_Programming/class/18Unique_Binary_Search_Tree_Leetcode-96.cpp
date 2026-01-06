/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/unique-binary-search-trees/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{//recursion
public:
    int f(int n){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=f(i-1)*f(n-i);
        }
        return sum;
    }
    int numTrees(int n){
        return f(n);
    }
};

class Solution{//dp meorization
public:
    int f(int n,vector<int>&dp){
        if(n==0 || n==1) return 1;
        if(n==2) return 2;
        if(dp[n]!=-1) return dp[n];
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=f(i-1,dp)*f(n-i,dp);
        }
        return dp[n]= sum;
    }
    int numTrees(int n){
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};

class Solution{//dp tabulation
public:
    int numTrees(int n){
        vector<int>dp(n+3,0);
        dp[0]=dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int k=1;k<=i;k++){
                dp[i]+=dp[k-1]*dp[i-k];
            }
        }
        return dp[n];
    }
};

int main(){
    Solution sol;
    int n;
    cout<<"Enter a Number : ";
    cin>>n;
    int result=sol.numTrees(n);
    cout<<"Total Number of genarate BST : "<<result;
}