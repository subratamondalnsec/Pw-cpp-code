#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int minimumDeleteSum(string a, string b) {
        int n = a.size();
        int m = b.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Initialize dp with ASCII values if one of the strings is empty
        for (int i = 1; i <= n; ++i) dp[i][0] = dp[i-1][0] + (int)a[i-1];
        for (int j = 1; j <= m; ++j) dp[0][j] = dp[0][j-1] + (int)b[j-1];

        // Fill the dp table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) {
                    // Characters match, carry forward the previous cost
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    // Characters do not match, take the minimum cost of deleting either
                    dp[i][j] = min(dp[i-1][j] + (int)a[i-1], dp[i][j-1] + (int)b[j-1]);
                }
            }
        }
        // for (int i = 0; i <= n; i++) {
        //     for (int j = 0; j <= m; j++) {
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        return dp[n][m];
    }
};

int main() {
    // Example input
    string a = "delete";
    string b = "leet";
    
    // Create a Solution object
    Solution solution;
    
    // Call the function
    int result = solution.minimumDeleteSum(a, b);
    
    // Print the result
    //cout << "Minimum ASCII delete sum to make the strings identical: " << result << endl;

    return 0;
}
 