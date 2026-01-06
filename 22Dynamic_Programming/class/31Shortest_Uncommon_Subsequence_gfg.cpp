/*
Code BY Subrata Mondal
problem link : https://www.geeksforgeeks.org/problems/shortest-uncommon-subsequence5746/1
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution{
public:
    vector<vector<int>>dp;
    int f(string &s,string &t,int n,int m){
        if(n==0) return 1e9;
        if(m==0) return 1;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans=1e9;
        int k;
        int c=s[n-1];
        for(k=m-1;k>=0;k--){
            if(c==t[k]) break;
        }
        if(k==-1) ans= 1;
        else {
            ans= min(f(s,t,n-1,m),1+f(s,t,n-1,k));
        }

        return dp[n][m]=ans;
    }
    int shortestUnSub(string S,string T){
        dp.resize(S.size()+10,vector<int>(T.size()+10,-1));
        int ans=f(S,T,S.size(),T.size());
        return (ans>=1e9) ? -1 : ans;
    }
};
int main(){
    Solution sol;
    string S;
    cin>>S;
    string T;
    cin>>T;
    cout<< endl <<sol.shortestUnSub(S,T);
}

/*
Input:
S = "babab"
T = "babba"
Output:3
*/