#include <bits/stdc++.h>
using namespace std;
class solution{
public:
    int numSubarrayProductLessThanK(vector<int>& nums,int k){
        if(k<=1) return 0;
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        int product=1;
        while(j<n){
           product *=nums[j];
           while(product>=k){
            count+=(j-i);
            product/=nums[i];
            i++;
           }
           j++;
        }
        while(i<n){
            count+=(j-i);
            product/=nums[i];
            i++;
        }
        return count;
    }
};
int main() {
    solution solution;
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    
    int result = solution.numSubarrayProductLessThanK(nums, k);
    cout << "Number of subarrays with product less than " << k << ": " << result << endl;

    return 0;
}
