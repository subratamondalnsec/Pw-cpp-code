#include <bits/stdc++.h>
using namespace std;

// Comparator function to sort activities by their end times.
bool cmp(vector<int>& v1, vector<int>& v2) {
    return v1[1] < v2[1];
}

class Solution {
public:
    int activitySelection(vector<int> start, vector<int> end, int n) {
        vector<vector<int>> ans(start.size(), vector<int>(2));
        for (int i = 0; i < start.size(); i++) {
            ans[i][0] = start[i];
            ans[i][1] = end[i];
        }
        sort(ans.begin(), ans.end(), cmp);
        int lastendtime = ans[0][1];
        int result = 1;
        for (int i = 1; i < n; i++) {
            if (ans[i][0] > lastendtime) {
                result++;
                lastendtime = ans[i][1];
            }
        }
        return result;
    }
};

int main() {
    // Example input
    vector<int> start = {1, 3, 2, 5};
    vector<int> end = {2, 4, 3, 6};
    int n = start.size();

    // Create an object of the Solution class.
    Solution sol;
    
    // Call the activitySelection function and store the result.
    int maxActivities = sol.activitySelection(start, end, n);
    
    // Print the result.
    cout << "The maximum number of activities that can be selected is: " << maxActivities << endl;

    return 0;
}
