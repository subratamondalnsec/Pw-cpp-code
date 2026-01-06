#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {// same of meeting room II
public:
    bool canAttendMeetings(vector<vector<int> > &intervals) {//m1
        if(intervals.size()==0) return true;
        vector<int>start,ending;
        for(auto x: intervals){
            start.push_back(x[0]);
            ending.push_back(x[1]);
        }
        sort(start.begin(),start.end());
        sort(ending.begin(),ending.end());
        int ans=0,room=0;
        int i=0,j=0;
        while(i<start.size() and j<ending.size()){
            if(start[i]<ending[j]){
                i++;
                room++;
                ans=max(ans,room);
            }
            else if(start[i]>ending[j]){
                j++;
                room--;
            }
            else{
                i++;
                j++;
            }
        }
        return ans==1;
    }
};
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return true;
        
        // Sort the intervals based on start times
        sort(intervals.begin(), intervals.end());
        
        // Check for overlapping intervals
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < intervals[i-1][1]) {
                return false; // Overlap detected
            }
        }
        
        return true; // No overlap found
    }
};

int main() {
    Solution solution;

    // Example test case 1: Overlapping meetings
    vector<vector<int>> intervals1 = {{0, 30}, {5, 10}, {15, 20}};
    bool result1 = solution.canAttendMeetings(intervals1);
    cout << "Can attend all meetings (test case 1)? " << (result1 ? "Yes" : "No") << endl;

    // Example test case 2: No overlapping meetings
    vector<vector<int>> intervals2 = {{7, 10}, {2, 4}};
    bool result2 = solution.canAttendMeetings(intervals2);
    cout << "Can attend all meetings (test case 2)? " << (result2 ? "Yes" : "No") << endl;

    return 0;
}

