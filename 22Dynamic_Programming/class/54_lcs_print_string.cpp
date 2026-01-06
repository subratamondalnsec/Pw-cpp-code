#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    
    int longestCommonSubsequence(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
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
        
        cout << "LCS: " << lcs << endl;
        return dp[n][m];
    }
};

int main() {
    // Example input
    string a = "ABCBDAB";
    string b = "BDCABC";
    
    // Create a Solution object
    Solution solution;
    
    // Call the function
    int length = solution.longestCommonSubsequence(a, b);
    
    // Print the length of the LCS
    cout << "Length of LCS: " << length << endl;

    return 0;
}
