#include <bits/stdc++.h>
using namespace std;
// class solution{//method 1
// public:
//     int longestSubarray(vector<int>& nums){
//         int n=nums.size();
//         int k=1;
//         int flips=0,i=0,j=0;
//         int maxlen=INT_MIN,len=INT_MIN;
//         while(j<n){
//             if(nums[j]==1) j++;
//             else{
//                 if(flips<k){
//                     flips++;
//                     j++;
//                 }
//                 else{//flips==k
//                     //calculate len
//                     len= j-i;
//                     maxlen=max(maxlen,len);
//                     //i ko just uske aage wale 0 se ek idx aage le jaao
//                     while(nums[i]==1) i++;
//                     i++;
//                     j++;
//                 }
//             }

//         }
//         len= j-i;
//         maxlen=max(maxlen,len);
//         return maxlen-1;
//     }
// };
//method 2
    int longestSubarray(vector<int>& nums){
        int n=nums.size();
        int i=0,j=0;
        int zeropos=-1,maxlen=0,count=0;
        while(j<n){
            int prev=zeropos;
            if(nums[j]==0){
                count++;
                zeropos=j;
            }
            if(count<=1) j++;
            else{
                maxlen=max(maxlen,j-i);
                i=prev+1;
                count--;
                j++;
            }
        }
        maxlen=max(maxlen,j-i);
        return maxlen-1;
    }
int main() {
    vector<int> nums = {1, 1, 0, 1, 1, 1, 0, 1, 1};
    int result =longestSubarray(nums);
    cout << "Longest subarray length after deleting one element: " << result << endl;

    return 0;
}