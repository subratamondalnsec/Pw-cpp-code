/*
Code BY Subrata Mondal
problem link : https://atcoder.jp/contests/dp/tasks/dp_i
*/
#include <iostream>
#include <vector>
#include <iomanip>//setprecision =>koto decimal place por jonto chai
#include <string.h>
using namespace std;

//double dp[35][20];  vs code 
double dp[3005][2000];
double f(vector<double> &p,int i,int x){
    if(x==0) return 1;
    if(i==-1) return 0;
    if(dp[i][x]>-0.9) return dp[i][x];
    return dp[i][x]=f(p,i-1,x-1)*p[i] +f(p,i-1,x)*(1-p[i]);
}
int main(){
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i=0;i<n;i++) cin>>p[i];
    memset(dp,-1,sizeof dp);
    cout<<fixed<<setprecision(9)<<f(p,n-1,(n+1)/2);
}
