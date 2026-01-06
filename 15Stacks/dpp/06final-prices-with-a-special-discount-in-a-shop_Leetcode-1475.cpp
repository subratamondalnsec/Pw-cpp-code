#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();//Next Smallest index
        vector<int> nse(n,0);
        stack<int> st;
        nse[n-1]=prices[n-1];
        st.push(prices[n-1]);
        for(int i=n-2;i>=0;i--) {
            while(st.size()>0 && st.top()>prices[i]) st.pop();
            if(st.size()==0) nse[i] =0;
            else nse[i] = st.top();
            nse[i]=prices[i]-nse[i];
            st.push(prices[i]);
        }
        return nse;
    } 
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Define a vector of prices for testing
    vector<int> prices = {8, 4, 6, 2, 3};

    // Call the finalPrices function and get the result
    vector<int> result = solution.finalPrices(prices);

    // Output the result
    cout << "Final Prices after discount: ";
    for (int price : result) {
        cout << price << " ";
    }
    cout << endl;

    return 0;
}