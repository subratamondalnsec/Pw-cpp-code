#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(k==1) return nums;
        int n=nums.size();
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<n;i++){
            while(dq.size()>0 && nums[i]>nums[dq.back()])  dq.pop_back();
            dq.push_back(i);
            int j=i-k+1;//start of the window
            while(dq.front()<j) dq.pop_front();
            if(i>=k-1) ans.push_back(nums[dq.front()]);
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