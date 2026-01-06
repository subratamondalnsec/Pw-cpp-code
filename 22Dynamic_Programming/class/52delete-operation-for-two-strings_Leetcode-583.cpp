#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    // int f(string& a, string& b, int idxA, int idxB){
    //     if (idxA == a.size() || idxB == b.size()) return 0;
    //     if(dp[idxA][idxB]!=-1) return dp[idxA][idxB];
    //     if (a[idxA] == b[idxB]) return dp[idxA][idxB]= 1 + f(a, b, idxA + 1, idxB + 1);
    //     else return dp[idxA][idxB]= max(f(a, b, idxA + 1, idxB),f(a, b, idxA, idxB + 1));
    // }
    int f(string& a, string& b, int idxA, int idxB){
        if (idxA < 0 || idxB < 0) return 0;
        if(dp[idxA][idxB]!=-1) return dp[idxA][idxB];
        if (a[idxA] == b[idxB]) return dp[idxA][idxB]=1 + f(a, b, idxA - 1, idxB - 1);
        else return dp[idxA][idxB]= max(f(a, b, idxA - 1, idxB),f(a, b, idxA, idxB - 1));
    }
    int minDistance(string a, string b) {
        int n=a.size();
        int m=b.size();
        dp.resize(n+4,vector<int>(m+4,-1));
        //return f(a, b, 0, 0);
        return (n+m)-2* f(a, b, n-1,  m-1);
    }
};



class Solution {
public:
    vector<vector<int>> dp;
    
    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        dp.resize(n+1, vector<int>(m+1, 0));
        
        // Fill the dp table with LCS calculation
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i-1] == b[j-1]) 
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // Minimum deletions to make both strings identical
        return (n + m) - 2 * dp[n][m];
    }
};

int main() {
    // Example input
    string a = "sea";
    string b = "eat";
    
    // Create a Solution object
    Solution solution;
    
    // Call the function
    int result = solution.minDistance(a, b);
    
    // Print the result
    cout << "Minimum number of deletions to make the strings identical: " << result << endl;

    return 0;
}
