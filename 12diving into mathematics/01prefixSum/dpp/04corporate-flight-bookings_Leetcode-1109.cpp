#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n,0);
    for(int i=0;i<bookings.size();i++){
        ans[bookings[i][0]-1]+=bookings[i][2];
        if(bookings[i][1]< n) ans[bookings[i][1]]-=bookings[i][2];
    }
    for(int i=1;i<n;i++){
        ans[i]+=ans[i-1];
    }
    return ans;
    }
};

int main() {
    Solution sol;
    
    // Example test case
    vector<vector<int>> bookings = {{1, 2, 10}, {2, 3, 20}, {2, 5, 25}};
    int n = 5;
    
    vector<int> result = sol.corpFlightBookings(bookings, n);
    
    // Print the result
    for (int seats : result) {
        cout << seats << " ";
    }
    cout << endl;

    return 0;
}
