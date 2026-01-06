#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<vector<int> > &intervals) {
        vector<int> start, ending;
        for (auto x : intervals) {
            start.push_back(x[0]);
            ending.push_back(x[1]);
        }
        sort(start.begin(), start.end());
        sort(ending.begin(), ending.end());
        int ans = 0, room = 0;
        int i = 0, j = 0;
        while (i < start.size() && j < ending.size()) {
            if (start[i] < ending[j]) {
                i++;
                room++;
                ans = max(ans, room);
            } else {
                j++;
                room--;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Example test case: meetings intervals
    vector<vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    
    // Call the function to get the minimum number of meeting rooms
    int result = solution.minMeetingRooms(intervals);
    
    // Print the result
    cout << "Minimum number of meeting rooms required: " << result << endl;
    
    return 0;
}
