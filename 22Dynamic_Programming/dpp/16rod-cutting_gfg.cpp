#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution{
  public:
      vector<int>dp;
      int f(int price[], int n){
          if(n==0) return 0;
          if(dp[n]!=-1) return dp[n];
          int ans=0;
          
          for(int i=0;i<n;i++){
              ans=max(ans,price[i]+cutRod(price,n-i-1));//-1 because start 0 base index
          }
          return dp[n]= ans;
      }
    int cutRod(int price[], int n) {
        dp.resize(n+10,-1);
      return f(price,n);
    }
};

class Solution{
  public:
    int cutRod(int price[], int N) {
        vector<int> dp(N + 1, 0);
        for(int n=1;n<=N;n++){
            int ans=0;
            for(int i=0;i<n;i++){
                ans=max(ans,price[i]+dp[n-i-1]);//-1 because start 0 base index
            }
            dp[n]=ans;
        }
        return dp[N];
    }
};


int main() {
    Solution solution;
    int price[] = {1, 5, 8, 9, 10, 17, 17, 20}; // example prices for lengths 1 to 8
    int N = sizeof(price) / sizeof(price[0]);   // length of the rod
    
    int maxProfit = solution.cutRod(price, N);
    cout << "Maximum profit: " << maxProfit << endl;

    return 0;
}
