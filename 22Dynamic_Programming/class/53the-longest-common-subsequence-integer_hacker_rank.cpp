//https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/problem?isFullScreen=false
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find the longest common subsequence
vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {
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
    
    // Backtrack to find the LCS
    vector<int> lcs;
    int i = n, j = m;
    while (i > 0 && j > 0) {
        if (a[i-1] == b[j-1]) {
            lcs.push_back(a[i-1]);
            i--;
            j--;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            i--;
        } else {
            j--;
        }
    }
    
    // Reverse to get the LCS in the correct order
    reverse(lcs.begin(), lcs.end());
    return lcs;
}

int main() {
    // Example input
    vector<int> a = {1, 3, 4, 1, 2, 3, 4};
    vector<int> b = {3, 4, 1, 2, 1, 3};
    
    // Call the function
    vector<int> lcs = longestCommonSubsequence(a, b);
    
    // Print the LCS result
    cout << "LCS: ";
    for (int num : lcs) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

