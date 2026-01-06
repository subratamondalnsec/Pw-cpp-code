#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        int mx=0;
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1])  dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] =0;
                mx=max(mx, dp[i][j]);
            }
        }
        return mx;
    }
};

int main(){
    Solution sol;
    string a,b;
    cout<<"Enter a string : ";
    cin>>a;
    cout<<"Enter a string : ";
    cin>>b;
    int ans=sol.longestCommonSubstr(a,b);
    cout<<"A common substring of two strings is : "<<ans;
}