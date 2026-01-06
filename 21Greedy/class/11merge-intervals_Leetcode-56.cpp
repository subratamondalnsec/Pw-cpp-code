#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(vector<int>& a, vector<int>& b) {
    return a[0] < b[0];
}

class Solution {//m1
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        vector<vector<int>> result;
        int n = intervals.size();
        result.push_back(intervals[0]);
        for (int i = 1; i < n; i++) {
            vector<int> curr = intervals[i];
            if (curr[0] <= result.back()[1]) {
                result.back()[0] = min(result.back()[0], curr[0]);
                result.back()[1] = max(result.back()[1], curr[1]);
            } else {
                result.push_back(curr);
            }
        }
        return result;
    }
};

bool cmp(vector<int>& a,vector<int>& b){
    return a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> result;
        int n=intervals.size();
        result.push_back(intervals[n-1]);
        for(int i=n-2;i>=0;i--){
            vector<int>curr=intervals[i];
            if(curr[1]>=result[result.size()-1][0]){
                result[result.size()-1][0]=min(result[result.size()-1][0],curr[0]);
                result[result.size()-1][1]=max(result[result.size()-1][1],curr[1]);
            }
            else{
                result.push_back(intervals[i]);
            }
        }
        reverse(result.begin(),result.end());
        return result;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> mergedIntervals = sol.merge(intervals);

    cout << "Merged Intervals: ";
    for (const auto& interval : mergedIntervals) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }
    cout << endl;

    return 0;
}
