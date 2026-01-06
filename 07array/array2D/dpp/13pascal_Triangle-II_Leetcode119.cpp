#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int n) {
        long long i=(long long)n;
        long long curr=1;
        vector<int> ans;
        for(long long j=0;j<=i;j++){
            ans.push_back((int)curr);
            curr=curr*(i-j)/(j+1);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    int n = 5;
    vector<int> row = sol.getRow(n);
    cout << "Row " << n << " of Pascal's Triangle: ";
    for (int num : row) {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}