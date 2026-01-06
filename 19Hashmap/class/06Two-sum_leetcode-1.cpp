#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            int rem = target - nums[i];
            if (map.find(rem) != map.end()) {
                ans.push_back(map[rem]);
                ans.push_back(i);
                return ans;  // Return as soon as the solution is found
            }
            map[nums[i]] = i;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {2, 7, 11, 15};  // Input array
    int target = 9;  // Target sum
    vector<int> result = solution.twoSum(nums, target);
    
    // Output the result
    if (!result.empty()) {
        cout << "Indices: " << result[0] << ", " << result[1] << endl;
    } else {
        cout << "No solution found." << endl;
    }

    return 0;
}
