#include <bits/stdc++.h>
using namespace std;
#define inf INT_MAX;
int Min_step(int n){//t.c=O(2^n) s.c=O(n)
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    return 1+min({Min_step(n-1),(n%2==0)? Min_step(n/2): INT_MAX , (n%3==0)?Min_step(n/3):INT_MAX });
}
int Min_step_memo(int n,vector<int>&dp){//t.c=O(n) s.c=O(n)
    if(n==1) return 0;
    if(n==2 || n==3) return 1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]= 1+min({Min_step_memo(n-1,dp),(n%2==0)? Min_step_memo(n/2,dp): INT_MAX , (n%3==0)?Min_step_memo(n/3,dp):INT_MAX });
}
int Min_step_Top_down(int n,vector<int>&dp){ //t.c=O(n) s.c=O(n)
    dp[1]=0;
    dp[2]=1;
    dp[3]=1;  
    for(int i=4;i<=n;i++){
        dp[i]=1+min({dp[i-1],(i%2==0)? dp[i/2]: INT_MAX , (i%3==0)?dp[i/3]:INT_MAX });
    }
    return dp[n];
}
int main(){
    int n;
    cout<<"Enter the Number : ";
    cin>>n;
    vector<int>dp(n+1,-1);
    cout<<"minimum number of step reduces "<<n<<" to 1 is : ";
    cout<<Min_step(n)<<endl;
    cout<<Min_step_memo(n,dp)<<endl;
    cout<<Min_step_Top_down(n,dp)<<endl;
}