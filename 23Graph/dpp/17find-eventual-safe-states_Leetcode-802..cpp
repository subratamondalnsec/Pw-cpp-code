/* Problem Link - https://leetcode.com/problems/find-eventual-safe-states/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <list>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<list<int> > gr(n);
        for(int i=0;i<n;i++){
            for(auto v : graph[i]){
                gr[v].push_back(i);
            }
        }
        vector<int> safenode;
        vector<bool> visited(n, false);
        vector<int> indegree(n, 0);
        for(auto i : gr) {
            for(auto v : i){
                indegree[v]++;
            }
        }
        queue<int> qu;
        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0){
                qu.push(i);
                visited[i]=true;
            }
        }
        while(not qu.empty()){
            auto node = qu.front();
            qu.pop();
            safenode.push_back(node);
            for(auto neigh: gr[node]) {
                if(!visited[neigh]){
                    indegree[neigh]--;
                    if(indegree[neigh] == 0) {
                        qu.push(neigh);
                        visited[neigh]=true;
                    }
                }
                
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;
    }
};

int main() {
    Solution solution;

    // Example input graph
    vector<vector<int>> graph = {
        {1, 2},    // Node 0 has edges to nodes 1 and 2
        {2, 3},    // Node 1 has edges to nodes 2 and 3
        {5},       // Node 2 has an edge to node 5
        {0},       // Node 3 has an edge to node 0 (cycle)
        {5},       // Node 4 has an edge to node 5
        {},        // Node 5 has no outgoing edges (terminal)
        {}         // Node 6 has no outgoing edges (terminal)
    };

    // Find eventual safe nodes
    vector<int> safeNodes = solution.eventualSafeNodes(graph);

    // Print the result
    cout << "Safe nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
