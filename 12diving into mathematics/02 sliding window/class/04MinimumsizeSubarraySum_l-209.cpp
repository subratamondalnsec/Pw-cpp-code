#include <bits/stdc++.h>
using namespace std;
class solution{
public:
int minSubArrayLen(int target,vector<int>& nums){
    int n=nums.size();
    int i=0;
    int j=0;
    int minlen=INT_MAX,len,sum=0;
    while(j<n){
        sum+=nums[j];
        while(sum>=target){
            len= j-i+1;
            minlen=min(minlen,len);
            sum-=nums[i];
            i++;
        }
        j++;
    }
    if(minlen==INT_MAX) return 0;
    return minlen;
    }
};
int main() {
    solution solution;
    int target = 7;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    
    int result = solution.minSubArrayLen(target, nums);
    cout << "Minimum length of subarray: " << result << endl;

    return 0;
}