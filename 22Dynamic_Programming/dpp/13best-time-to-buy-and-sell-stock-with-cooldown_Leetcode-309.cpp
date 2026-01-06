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
        if(i>=prices.size()) return 0;
        if(dp[i][on]!=-1) return dp[i][on];
        int ans=0;
        ans=f(prices,i+1,on);
        if(on==true) ans=max(ans,f(prices,i+2,false)+prices[i]);
        else ans=max(ans,f(prices,i+1,true)-prices[i]);
        return dp[i][on] = ans;
    }
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        dp.resize(prices.size(),vector<int>(2,-1));
        return f(prices,0,false);
    }
};
*/
/*
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==1) return 0;
        int n = prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        for(int i = n-1 ; i>=0 ; i--){
            for(int j=0;j<=1;j++){
                if(j==0) dp[i][0] = max(dp[i+1][0],-prices[i]+dp[i+1][1]);
               else dp[i][1] = max(dp[i+1][1],prices[i]+dp[i+2][0]);  //i+1 hobe na karon tarporer din cool down
            }
        } 
        return dp[0][0];
    }
};
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(2,0),next(2,0),nextNext(2,0);
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    curr[j]=max(-prices[i]+next[1],next[0]);
                }
                else{
                    curr[j]=max(prices[i]+nextNext[0],next[1]);
                }
            }
            nextNext=next;
            next=curr;
        }
        return curr[0];
    }
};


int main(){
    Solution sol;
    vector<int> prices={1,2,3,0,2};
    int result=sol.maxProfit(prices);
    cout<<"The maximum profit you can achieve : "<<result<<endl;
}