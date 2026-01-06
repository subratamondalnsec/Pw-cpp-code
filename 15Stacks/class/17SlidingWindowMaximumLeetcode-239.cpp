#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        if (k==1) return arr;
        int n = arr.size();
        int ngi[n];
        stack<int> st;
        ngi [n-1] = n;
        st.push(n-1);
        for(int i=n-2;i>=0;i--) {
            while(st.size()>0 && arr[st.top()]<=arr[i]){
                st.pop();
            }
            if(st.size()==0) ngi[i] = n;
            else ngi[i] = st.top();
            st.push(i);
        }
        vector<int> ans;
        int j = 0;
        for(int i=0;i<n-k+1;i++) {
            if(j<i) j = i;
            int mx = arr[j]; // starting of window se
            while(j < i+k) { // means if nge is inside 
                mx = arr[j];
                if(ngi[j] >= i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> arr = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> result = sol.maxSlidingWindow(arr, k);
    
    cout << "The maximum values in each sliding window are: ";
    for (int value : result) {
        cout << value << " ";
    }
    cout << endl;
    
    return 0;
}
