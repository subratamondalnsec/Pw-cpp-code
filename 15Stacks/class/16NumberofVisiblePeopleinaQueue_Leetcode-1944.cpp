#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<int> st;
        st.push(arr[n-1]);
        ans [n-1] = 0;
        for(int i=n-2;i>=0;i--) {
            int count = 0;
            while(st.size()>0 && arr[i]>st.top()) {
                st.pop();
                count++;
            }
            if(st.size()!=0) count++; // VIMP
            ans [i] = count;
            st.push(arr[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> heights = {10, 6, 8, 5, 11, 9};
    vector<int> result = sol.canSeePersonsCount(heights);
    
    cout << "The number of persons each person can see is: ";
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;
    
    return 0;
}