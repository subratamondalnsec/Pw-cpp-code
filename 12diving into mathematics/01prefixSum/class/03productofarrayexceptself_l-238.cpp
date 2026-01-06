#include <bits/stdc++.h>
using namespace std;
// class solution{//dividar method
// public:
//    vector<int>productExceptself(vector<int>& nums){
//         int n=nums.size();
//         int product=1,p2=1,noz=0;
//         for( int i=0;i<n;i++){
//             if(nums[i]==0) noz++;
//             product*=nums[i];
//             if(nums[i]!=0) p2*=nums[i];
//         }
//         if(noz>1) p2=0;
//         for(int i=0;i<n;i++){
//             if(nums[i]==0) nums[i]=p2;
//             else nums[i]=product/nums[i];
//         }
//         return nums;
//    }
// };
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size(); 
                vector<int>pre(n);
                //prefix produt
                int p=nums[0];
                pre[0]=1;
                for(int i=1;i<n;i++){
                    pre[i]=p;
                    p *= nums[i];
                }
                p=nums[n-1];
                for(int i=n-2;i>=0;i--){
                    pre[i]*=p;
                    p*=nums[i];
                }
            return pre;
    }
};
int main() {
    vector<int> nums = {1, 2, 3, 4};

    Solution sol;
    vector<int> result = sol.productExceptSelf(nums);

    // Output the result
    cout << "Result array: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}