
#include <iostream>
#include <vector>
using namespace std;
class Solution {//memorition
public:
    vector<vector<int>>dp;
    int f(vector<int>& coins, int amount,int i){
        if(amount==0) return 0;
        if(amount<0) return 1e5;
        if(i==coins.size()) return 1e5;
        if(dp[i][amount]!=-1) return dp[i][amount];
        return dp[i][amount]= min(1+f(coins,amount-coins[i],i),f(coins,amount,i+1));
    }
    int coinChange(vector<int>& coins, int amount) {
        dp.resize(coins.size()+4,vector<int>(amount+10,-1));
        int ans= f(coins,amount,0);
        return (ans==1e5) ? -1 :ans;
    }
};

class Solution {//tabulation
public:
    vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(n+1,vector<int>(amount+1,1e5));
        for(int i=0;i<=n;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]<0) dp[i][j]=dp[i-1][j];
                else dp[i][j]=min(1+dp[i][j-coins[i-1]],dp[i-1][j]);
            }
        }
        return (dp[n][amount]==1e5) ? -1 :dp[n][amount];
    }
};

class Solution {//space optimization
public:
    vector<vector<int>>dp;
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.resize(2,vector<int>(amount+1,1e5));
        for(int i=0;i<=1;i++) dp[i][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=amount;j++){
                if(j-coins[i-1]<0) dp[1][j]=dp[0][j];
                else dp[1][j]=min(1+dp[1][j-coins[i-1]],dp[0][j]);
            }
            for(int j=1;j<=amount;j++) dp[0][j]=dp[1][j];//1st row fill 0th row
        }
        return (dp[1][amount]==1e5) ? -1 :dp[1][amount];
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> coins = {1, 2, 5};
    int amount = 11;

    // Call the function
    int result = solution.coinChange(coins, amount);
    
    // Output the result
    cout << "Minimum coins needed: " << result << endl;

    return 0;
}
