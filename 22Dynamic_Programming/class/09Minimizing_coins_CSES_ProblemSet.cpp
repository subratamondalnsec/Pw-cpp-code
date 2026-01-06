#include <bits/stdc++.h>
using namespace std;

int minimum_coin_TD(vector<int>& coins,int x,vector<int>&dp){
    if(x==0) return 0;
    int result=INT_MAX;
    for(int i=0;i<coins.size();i++){
        if(x-coins[i]>=0){
            result=min(result,minimum_coin_TD(coins,x-coins[i],dp));
        }
    }
    if(result==INT_MAX) return dp[x]=INT_MAX;
    return dp[x]=1+result;
}

int minimum_coin_BU(vector<int>& coins,int X,vector<int>&dp){
    dp[0]=0;
    for(int x=1;x<=X;x++){
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(x-coins[i]>=0){
                result=min(result,dp[x-coins[i]]);
            }
        }
        if(result==INT_MAX) dp[x]=INT_MAX;
        else dp[x]=1+result;
    }
    return dp[X];
}

int main(){
    int n;//Number of coins
    int x;//sum of coins
    cin>>n>>x;
    vector<int>coins;
    for(int i=0;i<n;i++){
        int num;
        cin>>num;
        coins.push_back(num);
    }
    vector<int>dp(x+3,-1);
    // int ans=minimum_coin_TD(coins,x,dp);
    // if(ans==INT_MAX) cout<<"-1\n";
    // else cout<<ans<<endl;
    int ans=minimum_coin_BU(coins,x,dp);
    if(ans==INT_MAX) cout<<"-1\n";
    else cout<<ans<<endl;
}