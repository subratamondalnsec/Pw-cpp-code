/* Problem Link - https://leetcode.com/problems/course-schedule-iv/
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
    vector<list<int> >gr;
    vector<int>topo(int n,vector<vector<int>>& prerequisites){
        vector<int>indegree(n,0);
        for(int i=0;i<prerequisites.size();i++){
            gr[prerequisites[i][0]].push_back(prerequisites[i][1]);
            indegree[prerequisites[i][1]]++;
        }
        queue<int>q;
        vector<int>ans;
        for(int i=0;i<indegree.size();i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto nei : gr[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                }
            }
        }
        return ans;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        gr.resize(numCourses);
        vector<bool>r(queries.size(),false);
        if(prerequisites.size()==0) return r;
        vector<int>ans=topo(numCourses,prerequisites);
        vector<unordered_set<int>>result(numCourses);
        for (int node : ans) {
            for (int nei : gr[node]) {
                result[nei].insert(node);  // Add the current node as a prerequisite for neighbors
                result[nei].insert(result[node].begin(), result[node].end());  // Propagate prerequisites
            }
        }

        // Answer the queries
        for (int i = 0; i < queries.size(); i++) {
            if (result[queries[i][1]].count(queries[i][0])) r[i] = true;
        }

        return r;
    }
};

int main() {
    // Number of courses
    int numCourses = 4;

    // Prerequisites: {course, prerequisite}
    vector<vector<int>> prerequisites = {
        {1, 0},
        {2, 0},
        {3, 1},
        {3, 2}
    };

    // Queries: {prerequisite, course}
    vector<vector<int>> queries = {
        {0, 1},
        {1, 3},
        {2, 3},
        {0, 3},
        {3, 0}
    };

    // Create a Solution object and call the function
    Solution sol;
    vector<bool> result = sol.checkIfPrerequisite(numCourses, prerequisites, queries);

    // Print the results
    for (bool res : result) {
        cout << (res ? "true" : "false") << endl;
    }

    return 0;
}