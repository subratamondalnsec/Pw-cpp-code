#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<vector<int>>dp(n,vector<int>(3,0));

    int a,b,c;//base case
    cin>>a>>b>>c;//a->0 b->1 c->2
    dp[0][0]=a;
    dp[0][1]=b;
    dp[0][2]=c;
    for(int i=1;i<n;i++){
        cin>>a>>b>>c;
        //i th day ->a
        dp[i][0]=a+max(dp[i-1][1],dp[i-1][2]);
        //i th day ->b
        dp[i][1]=b+max(dp[i-1][0],dp[i-1][2]);
        //i th day ->c
        dp[i][2]=c+max(dp[i-1][0],dp[i-1][1]);
    }
    cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]});
}