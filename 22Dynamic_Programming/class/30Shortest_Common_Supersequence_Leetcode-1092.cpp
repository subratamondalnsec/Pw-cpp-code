/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/shortest-common-supersequence/description/
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // Print LCS
        string lcs = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (a[i-1] == b[j-1]) {
                lcs = a[i-1] + lcs; // Include this character in LCS
                i--;
                j--;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                i--;
            } else {
                j--;
            }
        }
        string ans="";
        i=j=0;
        for(int k=0;k<lcs.length();k++){
            while(a[i]!=lcs[k]) ans.push_back(a[i++]);
            i++;
            while(b[j]!=lcs[k]) ans.push_back(b[j++]);
            j++;
            ans.push_back(lcs[k]);
        }
        while(i<n) ans.push_back(a[i++]);
        while(j<m) ans.push_back(b[j++]);
        return ans;
    }
};
int main() {
    Solution solution;

    // Example input
    string a = "abac";
    string b = "cab";

    // Call the function
    string result = solution.shortestCommonSupersequence(a, b);

    // Print the result
    cout << "Shortest Common Supersequence: " << result << endl;

    return 0;
}