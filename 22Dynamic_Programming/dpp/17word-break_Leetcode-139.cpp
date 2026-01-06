#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    unordered_set<string> st;
    int n;
    vector<int> dp;
    
    bool f(string s, int i) {
        if (i >= n) return true;
        if (dp[i] != -1) return dp[i];
        for (int l = 1; l <= n - i; l++) {
            if (st.find(s.substr(i, l)) != st.end() && f(s, i + l))
                return dp[i] = true;
        }
        return dp[i] = false;
    }
    
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.size();
        dp.resize(n + 1, -1);
        for (auto word : wordDict) st.insert(word);
        return f(s, 0);
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    
    if (solution.wordBreak(s, wordDict)) {
        cout << "The string can be segmented into words from the dictionary." << endl;
    } else {
        cout << "The string cannot be segmented into words from the dictionary." << endl;
    }
    
    return 0;
}
