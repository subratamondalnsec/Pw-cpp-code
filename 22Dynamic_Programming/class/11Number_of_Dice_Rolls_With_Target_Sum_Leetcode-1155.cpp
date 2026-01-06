#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
class Solution{
public:
    int f(int n,int k,int t, vector<vector<int> >&dp){
        if(n==0 && t==0) return 1;
        if(n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        int result=0;
        for(int v=1;v<=k;v++){
            if(t-v>=0){
                result=(result%mod+f(n-1,k,t-v,dp)%mod)%mod;
            }
        }
        return dp[n][t]=result %mod;
    }
    int numRollsToTarget(int n,int k,int t){
        vector<vector<int> >dp(n+2,vector<int>(t+2,-1));
        return f(n,k,t,dp);
    }
};

class Solution{
public:
    int numRollsToTarget(int N,int k,int target){
        vector<vector<int> >dp(N+1,vector<int>(target+1,0));
        dp[0][0]=1;
        for(int n=1;n<=N;n++){//Number of dice
            for(int t=1;t<=target;t++){//target
                int res=0;
                for(int i=1;i<=k;i++){//number of face
                    if(t-i>=0) res=((res % mod) + (dp[n-1][t-i] % mod)) % mod ;
                }
                dp[n][t]=res;
            }
            
        }
        return dp[N][target];
    }
};

int main(){
    Solution sol;
    int n;
    cout<<"Enter the Number of Dice : ";
    cin>>n;
    int k;
    cout<<"Enter the Number of face : ";
    cin>>k;
    int target;
    cout<<"Enter the target : ";
    cin>>target;
    int ans=sol.numRollsToTarget(n,k,target);
    cout<<"This are "<<ans<<" ways to get target. ";
}