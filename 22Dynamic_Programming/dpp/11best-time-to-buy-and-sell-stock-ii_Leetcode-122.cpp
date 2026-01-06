#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;

/*
class Solution {
public:
    vector<vector<int>>dp;
    int f(vector<int>& prices,int i,bool on ){
        if(i==prices.size()) return 0;
        if(dp[i][on]!=-1) return dp[i][on];
        int ans=INT_MIN;
        ans=f(prices,i+1,on);
        if(on==true) ans=max(ans,f(prices,i+1,false)+prices[i]);
        else ans=max(ans,f(prices,i+1,true)-prices[i]);
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<int>(2,-1));
        return f(prices,0,false);
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int i = n-1 ; i>=0 ; i--){
            dp[i][0] = max(dp[i+1][0],-prices[i]+dp[i+1][1]);
            dp[i][1] = max(dp[i+1][1],prices[i]+dp[i+1][0]);
        } 
        return dp[0][0];
    }
};


// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int n = prices.size();
//         int p0 = 0 ; 
//         int p1 = 0 ; 
//         for(int i = n-1 ; i>=0 ; i--){
//             p0 = max(p0,-prices[i]+p1);
//             p1 = max(p1,prices[i]+p0);
//         } 
//         return p0;
//     }
// };

int main(){
    Solution sol;
    vector<int> prices={7,1,5,3,6,4};
    int result=sol.maxProfit(prices);
    cout<<"The maximum profit you can achieve : "<<result<<endl;
}