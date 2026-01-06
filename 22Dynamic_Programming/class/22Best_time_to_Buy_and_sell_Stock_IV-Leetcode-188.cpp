/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    int dp[1005][105][2];
    int f(vector<int>&prices,int i, int k,bool on){
        if(i==prices.size()) return 0;
        if(dp[i][k][on]!=-1) return dp[i][k][on];
        int ans=INT_MIN;
        ans=f(prices,i+1,k,on);//avoid
        if(on==true) ans=max(ans,prices[i]+f(prices,i+1,k-1,false));//stick sell
        else{
            if(k>0) ans=max(ans,f(prices,i+1,k,true)-prices[i]);//stick buy
        }
        return dp[i][k][on]=ans;
    }
    int maxProfit(int k,vector<int>&prices){
        memset(dp,-1,sizeof dp);
        return f(prices,0,k,false);
    }
};
int main(){
    vector<int>arr={2,4,1};
    int k=2;
    Solution sol;
    int result=sol.maxProfit(k,arr);
    cout<<"Max profit of stock : "<<result;
}
