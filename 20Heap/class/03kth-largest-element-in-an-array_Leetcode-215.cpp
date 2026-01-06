#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> >pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k) pq.pop();
        }
        return pq.top();
    }
};
int main() {
    Solution solution;
    vector<int> nums = {3, 2, 1, 5, 6, 4};  // Example array
    int k = 2;  // Find the 2nd largest element
    int result = solution.findKthLargest(nums, k);
    
    cout << "The " << k << "th largest element is: " << result << endl;
    
    return 0;
}