#include <bits/stdc++.h>
using namespace std;
vector<int> all_digit(int n){
    vector<int>result;
    while(n>0){
        if(n%10!=0) result.push_back(n%10);
        n=n/10;
    }
    return result;
}
int min_Step_memo(int n,vector<int>&dp){//top down
    if(n==0) return 0;
    if(n<=9) return 1;
    if(dp[n]!=-1) return dp[n];
    vector<int> digit=all_digit(n);
    int result=INT_MAX;
    for(int i=0;i<digit.size();i++){
        result=min(result,min_Step_memo(n-digit[i],dp));
    }
    return dp[n]= 1+result;
}

int min_Step_BU(int num,vector<int>&dp){//Bottom up
    dp[0]=0;
    for(int i=1;i<=9;i++) dp[i]=1;
    for(int n=10;n<=num;n++){
        vector<int> digit=all_digit(n);
        int result=INT_MAX;
        for(int i=0;i<digit.size();i++){
            result=min(result,dp[n-digit[i]]);
        }
        dp[n]=1+result;
    }
    return dp[num];
}


int main(){
    int n;
    cin>>n;
    vector<int>dp(n+4,-1);
    //cout<<min_Step_memo(n,dp)<<"\n";
    cout<<min_Step_BU(n,dp)<<"\n";
    return 0;
}