#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    vector<int> searchRange(vector<int>& nums,int target){
        vector<int>v(2,-1);
        int n=nums.size();
        int lo = 0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                if(mid==0 ||nums[mid-1]!=target){
                    v[0]=mid;
                    break;
                }
                else hi=mid-1;
            }
            else if(nums[mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        lo = 0;
        hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                if(mid==n-1 || nums[mid+1]!=target){
                    v[1]=mid;
                    break;
                }
                else lo=mid+1;
            }
            else if(nums[mid]>target)hi=mid-1;
            else lo=mid+1;
        }
        return v;
    }
};
int main() {
    Solution sol;
    vector<int> arr = {1,2,3,3,4,4,4,5,5};
    int k = 4;
    vector<int> result = sol.searchRange(arr, k);
    
    cout << "first occurance : "<<result[0];
    cout << endl;
    cout<<"last occurance : "<< result[1]; 
    return 0;
}
