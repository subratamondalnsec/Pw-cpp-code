#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
    typedef pair<int, int> pi;
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        for(int i = 0; i < nums.size(); i++) m[nums[i]]++;
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        for(auto x : m){
            pq.push({x.second, x.first});
            if(pq.size() > k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()) {
            ans.push_back((pq.top()).second);
            pq.pop();
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 1, 2, 2, 3};  // Example input
    int k = 2;  // Find the 2 most frequent elements
    
    vector<int> result = solution.topKFrequent(nums, k);
    
    // Output the result
    cout << "Top " << k << " frequent elements are: ";
    for(int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
