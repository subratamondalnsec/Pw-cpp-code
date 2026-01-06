#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> m;
        
        // Store frequency of nums[i] only if nums[i] < k
        for (int i = 0; i < nums.size(); i++) {
            if (k > nums[i]) m[nums[i]]++;
        }
        
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int e = nums[i];
            int rem = k - e;
            
            // If e == rem, count pairs within the same number
            if (m.find(rem) != m.end() && e == rem) {
                count += (m[e] / 2);
                m.erase(e);
            }
            // If e and rem are different, count their pairs and erase them
            else if (m.find(rem) != m.end()) {
                count += min(m[e], m[rem]);
                m.erase(e);
                m.erase(rem);
            }
        }
        return count;
    }
};

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {//t.c=O(n),s.c=O(n)
        unordered_map<int, int> m;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            int rem = k - nums[i];
            // Check if the complement (k - nums[i]) exists in the map
            if (m[rem] > 0) {
                count++;
                m[rem]--;  // Use one occurrence of the complement
            } else {
                // Otherwise, store the current number
                m[nums[i]]++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    
    // Example input
    vector<int> nums = {3, 1, 3, 4, 3};
    int k = 6;
    
    // Call the function
    int result = sol.maxOperations(nums, k);
    
    // Output the result
    cout << "Maximum number of operations: " << result << endl;
    
    return 0;
}
