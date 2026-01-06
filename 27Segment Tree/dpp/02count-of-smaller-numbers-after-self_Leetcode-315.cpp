/* problem link : https://leetcode.com/problems/count-of-smaller-numbers-after-self/
By subrata mondal */
#include<bits/stdc++.h>
using namespace std;


class STree{
public:
    vector<int>seg;
    STree(int n){
        seg.resize(4*n+1);
    }

    void build(vector<int>&freq,int ind,int low,int high){
        if(low==high){
            seg[ind]=freq[low];
            return;
        }
        int mid=low+(high-low)/2;
        build(freq,2*ind+1,low,mid);
        build(freq,2*ind+2,mid+1,high);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    void update(int ind,int low,int high,int i,int val){
        if(low==high){
            seg[ind]+=val;
            return;
        }
        int mid=low+(high-low)/2;
        if(i<=mid)  update(2*ind+1,low,mid,i,val);
        else    update(2*ind+2,mid+1,high,i,val);
        seg[ind]=seg[2*ind+1]+seg[2*ind+2];
    }

    int query(int ind,int low,int high,int l,int r){

        if(high<l or low>r) return 0;

        if(low>=l and high<=r)
            return seg[ind];
        
        int mid=low+(high-low)/2;
        int left=query(2*ind+1,low,mid,l,r);
        int right=query(2*ind+2,mid+1,high,l,r);
        return left+right;
    }

};
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n=20001;
        vector<int>freq(n,0);
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+10000]++;
        }
        STree st(n);
        st.build(freq,0,0,n-1);
        cout<<st.seg[0];
        vector<int>cnt;
        for(int i=0;i<nums.size();i++){
            freq[nums[i]+10000]--;
            st.update(0,0,n-1,nums[i]+10000,-1);
            cnt.push_back(st.query(0,0,n-1,0,nums[i]+10000-1));
        }
        return cnt;
    }
};


int main() {
    // Test input
    vector<int> nums = {5, 2, 6, 1};
    
    // Solution instance
    Solution sol;
    
    // Call the method
    vector<int> result = sol.countSmaller(nums);
    
    // Output the results
    cout << "Count of smaller numbers after self: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}