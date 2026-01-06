/* problem link : https://leetcode.com/problems/n-queens/description/
By subrata mondal */
#include<bits/stdc++.h>
using namespace std;


class NumArray {
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
    void update_val(int i,int lo,int hi,int& index, int& val){
        if(lo==hi) {
            seg[i]=val;
            return;
        }
        int mid=lo+(hi-lo)/2;
        if(index<=mid) update_val(2*i+1,lo,mid,index,val);
        else update_val(2*i+2,mid+1,hi,index,val);
        seg[i]=seg[2*i+1]+seg[2*i+2];

    }
    void update(int index, int val) {
        update_val(0,0,n-1,index,val);
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
    // Example array
    vector<int> nums = {1, 3, 5};
    
    // Create the NumArray object
    NumArray obj(nums);
    
    // Query the sum of range [0, 2]
    cout << "Sum of range [0, 2]: " << obj.sumRange(0, 2) << endl;  // Output: 9
    
    // Update index 1 to value 2
    obj.update(1, 2);
    
    // Query the sum of range [0, 2] again
    cout << "Sum of range [0, 2] after update: " << obj.sumRange(0, 2) << endl;  // Output: 8
    
    return 0;
}