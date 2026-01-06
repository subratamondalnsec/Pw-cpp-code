#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int> freq(2001, 0);
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            int idx = arr[i] + 1000;
            freq[idx]++;
        }
        sort(freq.begin(), freq.end());
        for (int i = 0; i < 2000; i++) {
            if (freq[i] == 0) continue;
            if (freq[i] == freq[i + 1]) return false;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> arr1 = {1, 2, 2, 1, 1, 3}; // Example with unique occurrences
    vector<int> arr2 = {1, 2}; // Example with unique occurrences
    vector<int> arr3 = {3, 5, -2, -3, -2, 3, 3}; // Example with non-unique occurrences

    cout << "Test Case 1: " << (sol.uniqueOccurrences(arr1) ? "True" : "False") << endl; // Expected: True
    cout << "Test Case 2: " << (sol.uniqueOccurrences(arr2) ? "True" : "False") << endl; // Expected: True
    cout << "Test Case 3: " << (sol.uniqueOccurrences(arr3) ? "True" : "False") << endl; // Expected: False

    return 0;
}
