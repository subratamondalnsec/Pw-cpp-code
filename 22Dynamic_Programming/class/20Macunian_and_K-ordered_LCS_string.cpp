/*
Code BY Subrata Mondal
problem link : 
*/
/* memorization */
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll dp[2005][2005][8];
ll longestCommonSubstring(string& a, string& b, int idxA, int idxB,int k) {
    if (idxA == a.size() || idxB == b.size()) {
        return 0;
    }
    if(dp[idxA][idxB][k]!=-1) return dp[idxA][idxB][k];
    ll res=0;
    if (a[idxA] == b[idxB]) {
        res=1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k);
    }
    else{
        if(k>0){
            res=1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k-1);
        }
        res=max(res,longestCommonSubstring(a, b, idxA + 1, idxB,k));
        res=max(res,longestCommonSubstring(a, b, idxA, idxB + 1,k));
    }
    // else{ both else case are same 
    //     if(k>0){
    //         res=max({1 + longestCommonSubstring(a, b, idxA + 1, idxB + 1,k-1),longestCommonSubstring(a, b, idxA + 1, idxB,k),longestCommonSubstring(a, b, idxA , idxB+1,k)});
    //     }
    //     else{
    //         res=max(longestCommonSubstring(a, b, idxA + 1, idxB,k),longestCommonSubstring(a, b, idxA, idxB + 1,k));

    //     }
    // }
    dp[idxA][idxB][k]=res;
    return res;
}
int main() {//it is string case it next 21 is number
    string a, b;
    cin >> a >> b;
    int k;
    cin>>k;
    
    memset(dp,-1,sizeof dp);
    ll ans = longestCommonSubstring(a, b, 0, 0,k);
    cout << ans << endl;
    return 0;
}

/* Tabulation */

#include <bits/stdc++.h>
using namespace std;

#define ll long long int
const int MAXN = 2005;  // Constraints limit for array size
ll dp[MAXN][MAXN][8];

int main() {
    string a, b;
    cin >> a >> b;
    int k;
    cin >> k;

    int n = a.size();
    int m = b.size();

    // Initialize DP array
    memset(dp, 0, sizeof(dp));

    // Fill the DP table iteratively
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int kk = 0; kk <= k; kk++) {
                // Case 1: Characters match
                if (a[i-1] == b[j-1]) {
                    dp[i][j][kk] = dp[i-1][j-1][kk] + 1;
                }
                // Case 2: Characters don't match, but substitution is allowed
                else if (kk > 0) {
                    dp[i][j][kk] = dp[i-1][j-1][kk-1] + 1;
                }
                // Case 3: Maximize by skipping an element from either sequence
                dp[i][j][kk] = max(dp[i][j][kk], dp[i-1][j][kk]);
                dp[i][j][kk] = max(dp[i][j][kk], dp[i][j-1][kk]);
            }
        }
    }

    // Find the maximum length with up to k mismatches
    ll ans = 0;
    for (int kk = 0; kk <= k; kk++) {
        ans = max(ans, dp[n][m][kk]);
    }

    cout << ans << endl;
    return 0;
}
