#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparison function for sorting intervals based on the end time
bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int lastEndtime = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] <= lastEndtime) {
                ans++;
            } else {
                lastEndtime = intervals[i][1];
            }
        }
        return n - ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<vector<int>> intervals = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    
    // Calling the function
    int result = solution.findMinArrowShots(intervals);

    // Output the result
    cout << "Minimum number of arrows required: " << result << endl;

    return 0;
}
