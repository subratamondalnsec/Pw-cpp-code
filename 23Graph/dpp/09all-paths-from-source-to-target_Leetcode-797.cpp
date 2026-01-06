/* Problem Link - https://leetcode.com/problems/all-paths-from-source-to-target/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;


class Solution {//dfs
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& graph,int curr,vector<int>&p){      
        if(curr==graph.size()-1) ans.push_back(p);
        for(int nei : graph[curr]){
            p.push_back(nei);
            dfs(graph,nei,p); 
            p.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> p;
        p.push_back(0);
        dfs(graph, 0, p);
        return ans;
    }
};

class Solution {//dfs
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& graph,int curr,vector<int>&p){
        p.push_back(curr);
        if(curr==graph.size()-1) ans.push_back(p);
        for(int nei : graph[curr]){
            dfs(graph,nei,p); 
            p.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> p;
        dfs(graph, 0, p);
        return ans;
    }
};

class Solution {//dfs
public:
    vector<vector<int>>ans;
    void dfs(vector<vector<int>>& graph,int curr,vector<int>&p){
        p.push_back(curr);
        if(curr==graph.size()-1) ans.push_back(p);
        for(int nei : graph[curr]){
            dfs(graph,nei,p);
        }
        p.pop_back();
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> p;
        dfs(graph, 0, p);
        return ans;
    }
};

int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Input graph: Each index represents a node, and the vector at that index represents its neighbors
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};

    // Call the method to find all paths from source (0) to target (n-1)
    vector<vector<int>> result = solution.allPathsSourceTarget(graph);

    // Print the results
    cout << "All paths from source to target:" << endl;
    for (const auto& path : result) {
        cout << "[";
        for (size_t i = 0; i < path.size(); ++i) {
            cout << path[i];
            if (i != path.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}