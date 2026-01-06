#include <bits/stdc++.h>
using namespace std;
class Solution {//method1
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        stack<int>st;
        vector<int> ans(n,-1);
        for(int i=n-1;i>=0;i--) st.push(nums[i]);
        for(int i=n-1;i>=0;i--){
            while(st.size()>0 &&st.top()<=nums[i]) st.pop();
            if(st.size()>0) ans[i]=st.top();
            st.push(nums[i]);
        }
        return ans;
    }
};

class Solution {//method 2
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int> nge(n,-1);
        stack<int>st;
        for(int i=0;i<2*n;i++){
            int idx=i%n;
            while(st.size()>0 && nums[st.top()]<nums[idx]){
                nge[st.top()]=nums[idx];
                st.pop();
            } 
            st.push(idx);
        }
        return nge;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Define a vector of nums for testing
    vector<int> nums = {1, 2, 1};

    // Call the nextGreaterElements function and get the result
    vector<int> result = solution.nextGreaterElements(nums);

    // Output the result
    cout << "Next Greater Elements: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
