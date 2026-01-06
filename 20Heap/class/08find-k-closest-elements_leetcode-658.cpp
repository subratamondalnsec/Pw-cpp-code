#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& nums, int k, int x) {
        priority_queue<pair<int, int>> pq;
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = abs(nums[i] - x);
            pq.push({abs(nums[i] - x), nums[i]});
            if (pq.size() > k) pq.pop();
        } 
        vector<int> ans;
        while (pq.size() > 0) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example input
    vector<int> nums = {1, 2, 3, 4, 5};  // Array of numbers
    int k = 4;  // Number of closest elements to find
    int x = 3;  // Reference element to compare distance from
    
    // Call the function
    vector<int> closest = solution.findClosestElements(nums, k, x);
    
    // Output the result
    cout << "The " << k << " closest elements to " << x << " are: ";
    for (int num : closest) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}
