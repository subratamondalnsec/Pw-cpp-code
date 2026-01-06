#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {//substr(0 base index , length)
        int n = s.size();
        vector< vector<int> >dp(n,vector<int>(n,0));
        int count=n;
        for(int i=0;i<n;i++) dp[i][i]=1;
        string largestPalindrome = s.substr(0, 1); // Start with the first character as the smallest possible palindrome

        // Dynamic programming to find palindromic substrings
        for (int k = 1; k < n; k++) {
            for (int i = 0, j = k; i < n - k && j < n; i++, j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j == i + 1) { // Substring of length 2
                        dp[i][j] = 1;
                        count++;
                    } else if (dp[i + 1][j - 1] == 1) { // Substring of length > 2
                        dp[i][j] = 1;
                        count++;
                    } else {
                        dp[i][j] = 0;
                    }

                    // Check if this palindrome is the largest
                    if (dp[i][j] == 1 && (j - i + 1) > largestPalindrome.size()) {
                        largestPalindrome = s.substr(i, j - i + 1);
                    }
                }
            }
        }
        return largestPalindrome;
    }
};


class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        int count = n;
        string largestPalindrome = s.substr(0, 1); // Start with the first character as the smallest possible palindrome
        //cout<<largestPalindrome<<" \n";
        // Dynamic programming to find palindromic substrings
        for (int k = 1; k < n; k++) {
            for (int i = 0, j = k; i < n - k && j < n; i++, j++) {
                if (s[i] != s[j]) {
                    dp[i][j] = 0;
                } else {
                    if (j == i + 1) { // Substring of length 2
                        dp[i][j] = 1;
                        count++;
                    } else if (dp[i + 1][j - 1] == 1) { // Substring of length > 2
                        dp[i][j] = 1;
                        count++;
                    } else {
                        dp[i][j] = 0;
                    }

                    // Check if this palindrome is the largest
                    if (dp[i][j] == 1 && (j - i + 1) > largestPalindrome.size()) {
                        largestPalindrome = s.substr(i, j - i + 1);
                        //cout<<largestPalindrome<<" \n";
                    }
                }
            }
        }
        return largestPalindrome;
    }
};


int main() {
    Solution sol;
    string s = "babad";
    cout << "Largest Palindromic Substring: " << sol.longestPalindrome(s) << endl;
    return 0;
}