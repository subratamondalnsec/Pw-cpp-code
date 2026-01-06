#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
        // Calculate prefix sum
        for (int i = 1; i < arr.size(); i++) {
            arr[i] += arr[i - 1];
        }
        
        unordered_map<int, int> mp;
        int count = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            // If current prefix sum equals k
            if (arr[i] == k) count++;
            
            // Check if there's a prefix sum that satisfies the equation arr[i] - k
            int rem = arr[i] - k;
            if (mp.find(rem) != mp.end()) count += mp[rem];
            
            // Store prefix sum frequencies
            mp[arr[i]]++;
        }
        
        return count;
    }
};

int main() {
    Solution solution;
    
    vector<int> arr = {1, 1, 1};
    int k = 2;
    
    int result = solution.subarraySum(arr, k);
    cout << "Number of subarrays with sum " << k << " is: " << result << endl;
    
    return 0;
}
