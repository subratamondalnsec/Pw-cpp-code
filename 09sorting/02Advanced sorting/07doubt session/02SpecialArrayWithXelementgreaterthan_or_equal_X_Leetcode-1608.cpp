#include <iostream>
#include <vector>
#include <algorithm>  // For the sort function
using namespace std;
class Solution {
public:
    int specialArray(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        // If the smallest element is greater than or equal to n, return n
        if (arr[0] >= n) return n;
        // Check for the special number in the sorted array
        for (int i = 1; i < n; i++) {
            int len = n - i;  // Number of elements greater than or equal to arr[i]
            // If the current element is different from the previous and satisfies the condition
            if (arr[i] != arr[i-1] && arr[i] >= len && len > arr[i-1]) {
                return len;
            }
        } 
        return -1;  // No special number found
    }
};

int main() {
    Solution solution;
    
    // Example test cases
    vector<int> arr1 = {3, 5};
    vector<int> arr2 = {0, 0};
    vector<int> arr3 = {0, 4, 3, 0, 4};
    vector<int> arr4 = {3, 6, 7, 7, 0};
    
    cout << "Test Case 1: " << solution.specialArray(arr1) << endl;  // Expected output: 2
    cout << "Test Case 2: " << solution.specialArray(arr2) << endl;  // Expected output: -1
    cout << "Test Case 3: " << solution.specialArray(arr3) << endl;  // Expected output: 3
    cout << "Test Case 4: " << solution.specialArray(arr4) << endl;  // Expected output: -1
    
    return 0;
}
