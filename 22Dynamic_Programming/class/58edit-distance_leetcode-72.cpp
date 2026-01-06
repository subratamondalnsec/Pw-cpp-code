#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> dp;

    int f(string& a, string& b, int i, int j) {
        if (i < 0) return j + 1;
        if (j < 0) return i + 1;
        if (dp[i][j] != -1) return dp[i][j];
        if (a[i] == b[j]) return dp[i][j] = f(a, b, i - 1, j - 1);
        return dp[i][j] = 1 + min({f(a, b, i, j - 1), f(a, b, i - 1, j), f(a, b, i - 1, j - 1)});
    }

    int minDistance(string a, string b) {
        int n = a.size();
        int m = b.size();
        dp.resize(n + 1, vector<int>(m + 1, -1));
        return f(a, b, n - 1, m - 1);
    }
};

int main() {
    Solution solution;
    string a = "intention";
    string b = "execution";
    cout << "Minimum edit distance: " << solution.minDistance(a, b) << endl;
    return 0;
}
