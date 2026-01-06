/* problem link : https://leetcode.com/problems/range-sum-query-immutable/
By subrata mondal */
#include<bits/stdc++.h>
using namespace std;

class NumArray {//prefix sum
public:
    vector<int>arr;
    NumArray(vector<int>& nums) {
        int n=nums.size();
        arr=vector<int>(n);
        arr[0]=nums[0];
        for(int i=1;i<n;i++){
            arr[i]=arr[i-1]+nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        if(left==0) return arr[right];
        return arr[right]-arr[left-1];
    }
};

class NumArray {//segment tree
public:
    vector<int>seg;
    int n;
    void build_segment_Tree(vector<int>& nums,int i,int lo,int hi){
        if(lo==hi){
            seg[i]=nums[hi];
            return;
        }
        int mid=lo+(hi-lo)/2;
        build_segment_Tree(nums,2*i+1,lo,mid);
        build_segment_Tree(nums,2*i+2,mid+1,hi);
        seg[i]=seg[2*i+1]+seg[2*i+2];
    }
    NumArray(vector<int>& nums) {
        n=nums.size();
        seg.resize(4*n);
        build_segment_Tree(nums,0,0,n-1);
    }
    int getsum(int i,int lo,int hi,int& l,int& r){
        if(l>hi || r<lo) return 0;
        if(lo>=l && hi<=r) return seg[i];
        int mid=lo+(hi-lo)/2;
        int leftsum=getsum(2*i+1,lo,mid,l,r);
        int rightsum=getsum(2*i+2,mid+1,hi,l,r);
        return leftsum+rightsum;
    }
    
    int sumRange(int left, int right) {
        return getsum(0,0,n-1,left,right);
    }
};


int main() {
    vector<int> nums = {1, 2, 3, 4}; // Input array
    NumArray obj(nums);             // Initialize NumArray object

    // Range queries
    int query1 = obj.sumRange(0, 3); // Query for range sum [0, 3]
    int query2 = obj.sumRange(1, 2); // Query for range sum [1, 2]

    // Print results
    cout << query1 << " " << query2 << endl;

    return 0;
}
