/*
Code BY Subrata Mondal
problem link : https://atcoder.jp/contests/dp/tasks/dp_l
*/
#include <bits/stdc++.h>
using namespace std;
#define ll long long int 
ll f(int i,int j,vector<vector<ll> >&dp,vector<ll>&arr){
    if(i==j) return arr[i];
    if(dp[i][j]!=-1) return dp[i][j];
    return dp[i][j]=max(arr[i]-f(i+1,j,dp,arr),arr[j]-f(i,j-1,dp,arr));
}

ll fbu(int n,vector<vector<ll> >&dp,vector<ll>&arr){
    //base case
    for(int i=0;i<n;i++){
        dp[i][i]=arr[i];
    }

    for(int len=2;len<=n;len++){
        for(int i=0;i<=n-len;i++){
            int j=i+len-1;
            dp[i][j]=max(arr[i]-dp[i+1][j],arr[j]-dp[i][j-1]);
        }
    }
    return dp[0][n-1];
}

int main(){
    int n;
    cin>>n;
    vector<ll>arr(n+3);
    for(int i=0;i<n;i++){
        cin>> arr[i];
    }
    // vector<vector<ll> >dp(n+3,vector<ll>(n+3,-1));
    // cout<<f(0,n-1,dp,arr);

    vector<vector<ll> >dp(n+3,vector<ll>(n+3,0));
    cout<<fbu(n,dp,arr);
}