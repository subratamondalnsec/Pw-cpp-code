#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>>dp;
    int f(int amount, vector<int>& coins,int idx){
        if(amount==0) return 1;
        if(amount<0) return 0;
        if(dp[amount][idx]!=-1) return dp[amount][idx];
        int totalway=0;
        for(int i=idx;i<coins.size();i++){
            if(amount>=coins[i]) totalway+=f(amount-coins[i],coins,i);
        }
        return dp[amount][idx]=totalway;
    }
    int change(int amount, vector<int>& coins) {
        dp.resize(amount+10,vector<int>(coins.size()+3,-1));
        return f(amount,coins,0);
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    // Call the function
    int result = solution.change( amount,coins);
    
    // Output the result
    cout << "The number of combinations that make up that amount: " << result << endl;

    return 0;
}
