/* Problem Link - https://leetcode.com/problems/parallel-courses-iii/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;


class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& r, vector<int>& time) {
        vector<list<int> >g(n);
        vector<int>indegree(n,0);
        vector<int>ct(n,0);
        for(int i=0;i<r.size();i++){
            g[r[i][0]-1].push_back(r[i][1]-1);
            indegree[r[i][1]-1]++;
        }
        queue<int>q;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        int ans=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for(int nei : g[curr]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
                ct[nei]=max(ct[curr]+time[curr],ct[nei]);
            }
        }
        for(int i=0;i<n;i++) ans=max(ans,ct[i]+time[i]);
        return ans;
    }
};


int main() {
    // Sample test case
    int n = 3; // Number of tasks
    vector<vector<int>> relations = {
        {1, 3}, {2, 3}
    }; // Dependencies where task 1 and task 2 must be completed before task 3
    vector<int> time = {3, 2, 5}; // Time required for each task

    // Create an instance of the Solution class
    Solution sol;

    // Call the minimumTime function
    int result = sol.minimumTime(n, relations, time);

    // Print the result
    cout << "Minimum time required to complete all tasks: " << result << endl;

    return 0;
}