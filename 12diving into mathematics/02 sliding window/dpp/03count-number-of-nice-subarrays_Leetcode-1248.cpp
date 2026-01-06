#include <bits/stdc++.h>
using namespace std;
class Solution {//this method change the array
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%2==0) nums[i]=0;
            else nums[i]=1;
        }
        int i=0,j=0,sum=0,ans=0,count=0;
        while(i<n && j<n){
            if(nums[j]==1) count =0;
            sum+=nums[j];
           while(sum==k){
                count++;
                sum-=nums[i];
                i++;
            }
            ans+=count;
            j++;
        }
        return ans;
    }
};

class Solution {//this method no change the array
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0,sum=0,ans=0,count=0;
        while(j<n){
            if(nums[j]%2!=0){
                count =0;
                sum++;
            }
           while(i<=j && sum==k){
                count++;
                if(nums[i++]%2!=0) sum--;
            }
            ans+=count;
            j++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test case
    vector<int> nums = {1, 1, 2, 1, 1};
    int k = 3;
    
    // Call the function and output the result
    int result = solution.numberOfSubarrays(nums, k);
    cout << "The number of subarrays with exactly " << k << " odd numbers is: " << result << endl;

    return 0;
}