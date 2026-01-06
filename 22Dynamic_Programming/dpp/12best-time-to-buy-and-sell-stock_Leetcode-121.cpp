#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;


/*
class Solution {
public:

    vector<vector<int>>dp;
    int f(vector<int>& prices,int i,bool on ,int k){
        if(i==prices.size()) return 0;
        if(k==0) return 0;
        if(dp[i][on]!=-1) return dp[i][on];
        int ans=0;
        ans=f(prices,i+1,on,k);
        if(on==true) ans=max(ans,f(prices,i+1,false,k-1)+prices[i]);
        else{
            if(k>0) ans=max(ans,f(prices,i+1,true,k)-prices[i]);
        } 
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return f(prices,0,false,1);
    }
};
*/

/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;

        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 2; k++) {
                dp[i][0][k] = max(-prices[i] + dp[i+1][1][k-1], dp[i+1][0][k]);
                dp[i][1][k] = max(prices[i] + dp[i+1][0][k-1], dp[i+1][1][k]);
            }
        }
        return dp[0][0][2];
    }
};
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0) return 0;
        
        int dp1[3] = {0};
        int dp2[3] = {0};

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 2; k++) {
                dp1[k] = max(-prices[i] + dp2[k-1], dp1[k]);
                dp2[k] = max(prices[i] + dp1[k-1], dp2[k]);
            }
        }
        return dp1[2]; 
    }
};


int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int result=sol.maxProfit(prices);
    cout<<"The maximum profit you can achieve : "<<result<<endl;
}