#include<bits/stdc++.h>
#define ll long long int
using namespace std;

vector<ll>dp((1<<16),INT_MAX);
vector<ll>sum((1<<16),0);

ll calc(vector<vector<ll > >& compact,ll mask){
    ll ans=0;
    for(int i=0;i<=16;i++){
        for(int j=i+1;j<=16;j++){
            if(((mask & (1<<i))!=0) and ((mask & (1<<j))!=0)){
                ans+=compact[i][j];
            }
        }
    }
    return ans;
}

ll f(vector<vector<ll > >& compact,int mask){
    if(mask==0) return 0;
    if(dp[mask]!=INT_MAX) return dp[mask];
    ll ans=0;
    for(int g=mask;g!=0;g=((g-1) & mask)){
        ans=max(ans,sum[g]+f(compact,mask^g));
    }
    return dp[mask]=ans;
}

void precompute(vector<vector<ll > >& compact,int n){
    for(int mask=1;mask<=((1 << n)-1);mask++){
        sum[mask]=calc(compact,mask);
    }
}

int main(){
    ll n;
    cin>>n;
    vector<vector<ll > >compact(n,vector<ll >(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>compact[i][j];
        }
    }
    precompute(compact,n);
    cout<<f(compact,(1<<n)-1);
    return 0;

}


/*
Sample Input 1

3
0 10 20
10 0 -100
20 -100 0

Sample Output 1
20
The rabbits should be divided as 
{1,3},{2}.

Sample Input 2

2
0 -10
-10 0

Sample Output 2
0
The rabbits should be divided as 
{1},{2}.

Sample Input 3

4
0 1000000000 1000000000 1000000000
1000000000 0 1000000000 1000000000
1000000000 1000000000 0 -1
1000000000 1000000000 -1 0

Sample Output 3
4999999999

Sample Input 4

16
0 5 -4 -5 -8 -4 7 2 -4 0 7 0 2 -3 7 7
5 0 8 -9 3 5 2 -7 2 -7 0 -1 -4 1 -1 9
-4 8 0 -9 8 9 3 1 4 9 6 6 -6 1 8 9
-5 -9 -9 0 -7 6 4 -1 9 -3 -5 0 1 2 -4 1
-8 3 8 -7 0 -5 -9 9 1 -9 -6 -3 -8 3 4 3
-4 5 9 6 -5 0 -6 1 -2 2 0 -5 -2 3 1 2
7 2 3 4 -9 -6 0 -2 -2 -9 -3 9 -2 9 2 -5
2 -7 1 -1 9 1 -2 0 -6 0 -6 6 4 -1 -7 8
-4 2 4 9 1 -2 -2 -6 0 8 -6 -2 -4 8 7 7
0 -7 9 -3 -9 2 -9 0 8 0 0 1 -3 3 -6 -6
7 0 6 -5 -6 0 -3 -6 -6 0 0 5 7 -1 -5 3
0 -1 6 0 -3 -5 9 6 -2 1 5 0 -2 7 -8 0
2 -4 -6 1 -8 -2 -2 4 -4 -3 7 -2 0 -9 7 1
-3 1 1 2 3 3 9 -1 8 3 -1 7 -9 0 -6 -8
7 -1 8 -4 4 1 2 -7 7 -6 -5 -8 7 -6 0 -9
7 9 9 1 3 2 -5 8 7 -6 3 0 1 -8 -9 0

Sample Output 4
132

*/