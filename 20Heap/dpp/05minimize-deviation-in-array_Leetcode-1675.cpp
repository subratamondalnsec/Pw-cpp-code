#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumDeviation(vector<int>& arr) {
        priority_queue<int> pq;
        int mn = 1e9, result = 1e9;
        
        // Normalize the array by converting odd numbers to even
        for (auto x : arr) {
            if (x % 2 != 0) x *= 2; // Make odd numbers even by multiplying by 2
            pq.push(x);              // Push into max-heap (priority queue)
            mn = min(mn, x);         // Keep track of the minimum value
        }
        
        // Continue halving the largest value while it's even
        while (true) {
            int val = pq.top(); // Get the maximum value
            pq.pop();
            result = min(result, val - mn); // Calculate deviation
            
            // If the maximum is odd, we can't reduce it further
            if (val % 2 != 0) break;
            
            // Halve the even number and push it back into the heap
            val /= 2;
            pq.push(val);
            mn = min(mn, val); // Update the minimum value
        }
        
        return result; // Return the minimum deviation found
    }
};

int main() {
    Solution sol;

    // Test case 1
    vector<int> arr1 = {1, 2, 3, 4};
    int result1 = sol.minimumDeviation(arr1);
    cout << "Minimum deviation: " << result1 << endl; // Expected output: 1

    // Test case 2
    vector<int> arr2 = {4, 1, 5, 20, 3};
    int result2 = sol.minimumDeviation(arr2);
    cout << "Minimum deviation: " << result2 << endl; // Expected output: 3

    // Test case 3
    vector<int> arr3 = {10, 20, 30, 40};
    int result3 = sol.minimumDeviation(arr3);
    cout << "Minimum deviation: " << result3 << endl; // Expected output: 10

    return 0;
}
