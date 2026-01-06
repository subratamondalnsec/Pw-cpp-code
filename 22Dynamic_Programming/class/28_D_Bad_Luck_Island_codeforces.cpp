/*
Code BY Subrata Mondal
problem link : https://codeforces.com/problemset/problem/540/D
*/
#include <iostream>
#include <vector>
#include <string.h>
#include <iomanip>
using namespace std;
#define ld long double

ld dp[105][105][105];

ld rock(int r,int s,int p){
    if(r==0 || s==0) return 0.0;
    if(p==0) return 1.0;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=r*s+r*p+s*p;
    ld result =0.0;
    result+=rock(r-1,s,p)*((r*p)/total);
    result+=rock(r,s-1,p)*((r*s)/total);
    result+=rock(r,s,p-1)*((s*p)/total);
    return dp[r][s][p]=result;
}
ld scissor(int r,int s,int p){
    if(p==0 || s==0) return 0.0;
    if(r==0) return 1.0;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=r*s+r*p+s*p;
    ld result =0.0;
    result+=scissor(r-1,s,p)*((r*p)/total);
    result+=scissor(r,s-1,p)*((r*s)/total);
    result+=scissor(r,s,p-1)*((s*p)/total);
    return dp[r][s][p]=result;
}
ld paper(int r,int s,int p){
    if(p==0 || r==0) return 0.0;
    if(s==0) return 1.0;
    if(dp[r][s][p]>-0.9) return dp[r][s][p];
    ld total=r*s+r*p+s*p;
    ld result =0.0;
    result+=paper(r-1,s,p)*((r*p)/total);
    result+=paper(r,s-1,p)*((r*s)/total);
    result+=paper(r,s,p-1)*((s*p)/total);
    return dp[r][s][p]=result;
}
int main(){
    int r,s,p;
    cin>>r>>s>>p;
    memset(dp,-1.0,sizeof dp);
    ld ans_r=rock(r,s,p);
    memset(dp,-1.0,sizeof dp);
    ld ans_s=scissor(r,s,p);
    memset(dp,-1.0,sizeof dp);
    ld ans_p=paper(r,s,p);
    cout<<fixed<<setprecision(9)<<ans_r<<" "<<ans_s<<" "<<ans_p<<" ";
    return 0;
}