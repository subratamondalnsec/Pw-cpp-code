#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
    int nge[n];
    nge[n-1]=-1;
    int mx=prices[n-1];
    for(int i=n-2;i>=0;i--){
        if(mx<prices[i]){
            nge[i]=-1;
            mx=prices[i];
        }
        else{
            nge[i]=mx;
        } 
    }
    int profit=0;
    for(int i=0;i<n;i++){
        profit=max(profit,(nge[i]-prices[i]));
    }
    return profit;

    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Max Profit: " << sol.maxProfit(prices) << endl;
    return 0;
}
    