#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

ll Dicecombination(int n,vector<ll>&dp){
    if(n==0) return 1;
    if(n<0) return 0;
    if(dp[n]!=-1) return dp[n];
    ll result=0;
    for(int i=1;i<=6;i++){
        if(n>=i){
            result+=Dicecombination(n-i,dp);
        }
    }
    return dp[n]= result % mod;
}

ll Dicecombination_BU(int N,vector<ll>&dp){
    dp[0]=1;
    for(int n=1;n<=N;n++){
        ll result=0;
        for(int i=1;i<=6;i++){
            if(n>=i){
                result=(result % mod +dp[n-i] % mod)%mod;
            }
        }
        dp[n]= result % mod;
    }
    return dp[N];
}

int main(){
    int n;
    //cout << "Enter a number: ";
    cin >> n;
    vector<ll>dp(n+1,-1);
    // result=Dicecombination(n,dp);

    ll result=Dicecombination_BU(n,dp);
    //cout << "The total number of ways is : " <<result <<" to get the sum "<< n<<" by repeatedly throwing a dice."<< endl;
    cout<< result;
}
