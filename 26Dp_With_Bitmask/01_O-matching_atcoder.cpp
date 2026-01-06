#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
int dp[22][(1<<22)];

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}


int f(vector<vector<int> > compat, int i, int mask, int n) {
    if(i == n+1) {
        if(mask == 0) return 1; // one possible way found
        return 0; // no possible way found for this branch
    }
    if(dp[i][mask] != -1) return dp[i][mask];
    int ans = 0;
    for(int w = 1; w <= n; w++) {
        bool avail = (((1 << (w-1)) & (mask)) == 0) ? 0 : 1;
        if(avail and compat[i][w] == 1) {
            ans = ((ans%mod) + (f(compat, i+1, (mask^(1<<(w-1))) , n))%mod)%mod;
        }
    }

    return dp[i][mask] = ans;
}


int main(){
    file_i_o();
    int n;
    cin>>n;
    vector<vector<int> > compat(n+1, vector<int> (n+1));
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin>>compat[i][j];
        }
    }
    cout<<f(compat, 1, (1<<n)-1, n);
    return 0;
}