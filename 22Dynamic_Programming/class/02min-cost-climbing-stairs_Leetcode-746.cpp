#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int helper(vector<int>& cost, int i, vector<int>& dp) {
        if (i == 0 || i == 1) return cost[i];
        if (dp[i] != -1) return dp[i];
        return dp[i] = cost[i] + min(helper(cost, i - 1, dp), helper(cost, i - 2, dp));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, -1);
        return min(helper(cost, n - 1, dp), helper(cost, n - 2, dp)); 
    }
};

class Solution {//tabulation
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        for(int i=2;i<n;i++){
            cost[i]+=min(cost[i-1],cost[i-2]);
        }
        return min(cost[n-1],cost[n-2]);
    }
};

int main() {
    vector<int> cost = {10, 15, 20};  // Example input
    Solution sol;
    int result = sol.minCostClimbingStairs(cost);
    cout << "The minimum cost to reach the top is: " << result << endl;
    return 0;
}
