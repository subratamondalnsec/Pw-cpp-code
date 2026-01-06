#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& arr) {
        unordered_map<int, int> m;
        int lsub = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (i == 0 && arr[i] == 0) arr[i] = -1;
            else if (arr[i] == 0) arr[i] = arr[i - 1] - 1;
            else if (i == 0 && arr[i] == 1) arr[i] = 1;
            else if (arr[i] == 1) arr[i] = 1 + arr[i - 1];

            if (arr[i] != 0 && m.find(arr[i]) == m.end())  m[arr[i]] = i;
            else if (arr[i] == 0)  lsub = max(lsub, (i + 1));
            else if (m.find(arr[i]) != m.end()) lsub = max(lsub, (i - m[arr[i]]));
        }
        return lsub;
    }
};

int main() {
    Solution sol;

    // Input binary array
    vector<int> arr = {0, 1, 0, 0, 1, 1, 0};

    // Call the function and print the result
    int maxLength = sol.findMaxLength(arr);

    cout << "Maximum length of a subarray with equal 0s and 1s: " << maxLength << endl;

    return 0;
}
