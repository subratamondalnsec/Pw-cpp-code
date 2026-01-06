#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sum(vector<int>& v){
        int n=v.size();
        if(n==1) return v[0];
        for(int i =0;i<n-1;i++){
            v[i]=(v[i]+v[i+1])%10; 
        }
        v.pop_back();
        return sum(v);
        
    }
    int triangularSum(vector<int>& nums) {
        return sum(nums);
    }
};
int main() {
    // Example usage:
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    int result = sol.triangularSum(nums);
    cout << "The triangular sum is: " << result << endl;
    
    return 0;
}