#include <bits/stdc++.h>
using namespace std;
int main(){
    int l,k,m;//m=> number of coins
    cin>>l>>k>>m;
    vector<int>dp(1000005,0);
    dp[1]=1;
    dp[k]=1;
    dp[l]=1;
    for(int i=2;i<=1000000;i++){
        if(i==k or i==l) continue;
        dp[i]=!(dp[i-1] and ((i-k>=1)? dp[i-k] : 1) and ((i-l>=1)? dp[i-l] : 1 ));
    }
    for(int i=0;i<m;i++){
        int n;
        cin>>n;
        if(dp[n]==1) cout<<"A";
        else cout<<"B";
    }
}

 // recursion + memo
vector<int>dp;
int f(int n,int k,int l){
    if(n==1 || n==k || n==l) return 1;
    if(n<0) return 1;
        if(dp[n]!=-1) return dp[n];
    return dp[n]= !(f(n-1,k,l) && f(n-k,k,l) && f(n-l,k,l));
}
 
int main(){
    int l,k,m;//m=> number of coins
    cin>>l>>k>>m;
    int mx=INT_MIN;
    vector<int>coins(m);
    for(int i=0;i<m;i++){
        cin>>coins[i];
        mx=max(mx,coins[i]);
    }
    dp.resize(mx+5,-1);
    dp[1]=dp[l]=dp[k]=1;
    f(mx,k,l);
    for(int i=0;i<coins.size();i++){
        if(dp[coins[i]]==1) cout<<"A";
        else cout<<"B";
    }
}