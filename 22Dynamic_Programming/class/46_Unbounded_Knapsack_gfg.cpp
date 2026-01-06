#include <iostream>
#include <vector>
using namespace std;

class Solution{
public:
    vector<vector<int>> dp;
    int n;

    int f(int c, int wt [], int val[], int w, int i) {
        if (i == n) return 0;
        if (dp[i][w] != -1) return dp[i][w];
        if (c < w + wt[i]) return dp[i][w] = f(c, wt, val, w, i + 1);
        int take = val[i] + f(c, wt, val, w + wt[i], i );
        int leave = f(c, wt, val, w, i + 1);
        return dp[i][w] = max(take, leave);
    }
    int knapSack(int N, int c, int val[], int wt[]){
        // code here
        dp.resize(N, vector<int>(c + 1, -1));
        n=N;
        return f(c, wt, val, 0, 0);
        
    }
};

int main() {
    int n; // Number of items
    int W; // Maximum capacity of knapsack
    cout << "Enter the number of items: ";
    cin >> n;

    int  wt[n], val[n];

    cout << "Enter the maximum capacity of knapsack: ";
    cin >> W;

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> wt[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < n; ++i) {
        cin >> val[i];
    }

    Solution sol;
    int maxVal = sol.knapSack(n,W, wt, val);

    cout << "The maximum value that can be obtained is: " << maxVal << endl;

    return 0;
}
