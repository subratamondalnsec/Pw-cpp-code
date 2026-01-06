#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {//Time Complexity: O(n log n) + O(n) ,s.c=O(1)
public:
    int findPlatform(vector<int>& arr, vector<int>& dep) {
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int platform = 0, ans = 0;
        int i = 0, j = 0;
        
        // Traverse through all arrival and departure times
        while (i < arr.size() && j < dep.size()) {
            // If the next train is arriving before or at the time the last train departs, increment platform count
            if (arr[i] <= dep[j]) {
                ans++;
                i++;
                platform = max(platform, ans);
            } else {
                // Otherwise, the platform is free (one train departs), decrement platform count
                ans--;
                j++;
            }
        }
        
        return platform;
    }
};

int main() {
    int n;
    cout << "Enter the number of trains: ";
    cin >> n;

    vector<int> arr(n), dep(n);
    cout << "Enter the arrival times: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Enter the departure times: ";
    for (int i = 0; i < n; ++i) {
        cin >> dep[i];
    }

    Solution solution;
    int result = solution.findPlatform(arr, dep);

    cout << "Minimum number of platforms required is: " << result << endl;

    return 0;
}
