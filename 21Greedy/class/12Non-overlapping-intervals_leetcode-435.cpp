#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Comparison function for sorting intervals based on the start time
bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int lastEndtime = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEndtime) {
                ans++;
                lastEndtime = min(lastEndtime, intervals[i][1]);
            } else {
                lastEndtime = intervals[i][1];
            }
        }
        return ans;
    }
};

bool cmp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size();
        int lastEndtime = intervals[0][1];
        int ans = 0;
        for (int i = 1; i < n; i++) {
            if (intervals[i][0] < lastEndtime) {
                ans++;
            } else {
                lastEndtime = intervals[i][1];
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example input
    vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
    
    // Calling the function
    int result = solution.eraseOverlapIntervals(intervals);

    // Output the result
    cout << "Minimum number of intervals to remove: " << result << endl;

    return 0;
}
