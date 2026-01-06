#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> countDistinct(int a[], int n, int k) {
        vector<int> ans;
        unordered_map<int, int> m;
        int i = 0;
        for (i = 0; i < k; i++) m[a[i]]++;
        ans.push_back(m.size());
        while (i < n) {
            m[a[i - k]]--;
            if (m[a[i - k]] == 0) m.erase(a[i - k]);
            m[a[i]]++;
            ans.push_back(m.size());
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;

    // Input array and parameters
    int a[] = {1, 2, 1, 3, 4, 2, 3};  // Example array
    int n = sizeof(a) / sizeof(a[0]); // Size of the array
    int k = 4; // Size of the sliding window

    // Call the function and get the result
    vector<int> result = sol.countDistinct(a, n, k);

    // Print the result
    cout << "Count of distinct elements in each window:" << endl;
    for (int count : result) {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
