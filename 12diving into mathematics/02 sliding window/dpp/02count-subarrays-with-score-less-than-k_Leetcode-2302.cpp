#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        long long n=nums.size(),i=0,j=0,sum=0,score=0,ans=0;
        while(i<n && j<n){
            sum+=nums[j];
            score=sum*(j-i+1);
            while(i<=j && score>=k){
                sum-=nums[i++];
                score=sum*(j-i+1);
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};
int main() {
    Solution solution;
    
    // Test case
    vector<int> nums = {1, 2, 3, 4};
    long long k = 10;
    
    // Call the function and output the result
    long long result = solution.countSubarrays(nums, k);
    cout << "The number of valid subarrays is: " << result << endl;
    return 0;
}