#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        int n=nums.size();
        vector<long long> ans(n,0);
        ans[0]=nums[0]*2;
        int max_ele=nums[0];
        for(int i =1;i<n;i++){
            max_ele=max(nums[i],max_ele);
            ans[i]=max_ele+ans[i-1]+nums[i];
        }
        return ans;
    }
};

int main() {
    // Example input
    vector<int> nums = {1, 2, 3, 4, 5};

    // Create an instance of Solution
    Solution sol;

    // Call the findPrefixScore function
    vector<long long> result = sol.findPrefixScore(nums);

    // Print the result
    cout << "The prefix scores are: ";
    for (long long score : result) {
        cout << score << " ";
    }
    cout << endl;

    return 0;
}