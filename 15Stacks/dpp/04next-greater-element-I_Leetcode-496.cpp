#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums2.size();
        int nge[n];
        stack<int>st;//stack 
        nge[n-1]=-1;
        st.push(nums2[n-1]);
        for(int i=n-2;i>=0;i--){
            //pop all the elements similar than arr[i]
            while(st.size()>0 && st.top()<=nums2[i]) st.pop();
            //mark the ans in the nge array
            if(st.size()==0) nge[i]=-1;
            else nge[i]=st.top();
            //push the arr[i]
            st.push(nums2[i]);
        }
        int m=nums1.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j]){
                    ans.push_back(nge[j]);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    
    vector<int> result = solution.nextGreaterElement(nums1, nums2);
    
    // Print the result
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}