#include <bits/stdc++.h>
using namespace std;
    // int search(vector<int>& nums, int target) {//raghav sir
    //     int n=nums.size();
    //     int lo=0;
    //     int hi=n-1;
    //     if(n==2){
    //         if(target==nums[0]) return 0;
    //         else if(target==nums[1]) return 1;
    //         else return -1;
    //     }
    //     int pivot=-1;
    //     while(lo<=hi){
    //          int mid=lo+(hi-lo)/2;
    //          if(mid==0) lo=mid+1;
    //          else if(mid==n-1) hi=mid-1;
    //          else if(nums[mid]<nums[mid+1]&&nums[mid]<nums[mid-1]){
    //             pivot=mid;
    //             break;
    //          }
    //          else if(nums[mid]>nums[mid+1]&& nums[mid]>nums[mid-1]){
    //             pivot=mid+1;
    //             break;
    //          }
    //          else if(nums[mid]>nums[hi])lo=mid+1;
    //          else hi=mid-1;
    //     }
    //     if(pivot==-1){
    //       lo=0;
    //       hi=n-1;
    //     while(lo<=hi){
    //        int mid=lo+(hi-lo)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(nums[mid]>target)hi=mid -1;
    //         else lo =mid+1;
    //     }
    //     return-1;
    //     }
    //     if(target>=nums[0]&& target<=nums[pivot-1]){
    //      lo=0;
    //      hi=pivot-1;
    //     while(lo<=hi){
    //        int mid=lo+(hi-lo)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(nums[mid]>target)hi=mid -1;
    //         else lo =mid+1;
    //     }
    //     }
    //     else{
    //       lo=pivot;
    //       hi=n-1;
    //     while(lo<=hi){
    //        int mid=lo+(hi-lo)/2;
    //         if(nums[mid]==target) return mid;
    //         else if(nums[mid]>target)hi=mid -1;
    //         else lo =mid+1;
    //     }
    //     }
    //     return -1;
    // }
    
    int search(vector<int>& nums, int target) {
        int lo=0, hi=nums.size()-1;
        while(lo<=hi){
            int mid =lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            else if(nums[lo]<=nums[mid]){
                if(nums[lo]<=target && target<=nums[mid]) hi=mid-1;
                else lo=mid+1;
            }
            else{
                if(nums[mid]<=target && target<=nums[hi]) lo=mid+1;
                else hi = mid-1;
            }
        }
        return -1;
    }
    
    int main() {
    vector<int> testArray = {4, 5, 6, 7, 0, 1, 2}; // Example of a rotated sorted array
    int target = 0; // Example target value
    int result =search(testArray, target);
    cout << "The index of target " << target << " is " << result << std::endl;
    return 0;
}