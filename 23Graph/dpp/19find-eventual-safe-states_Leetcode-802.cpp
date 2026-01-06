/* Problem Link - https://leetcode.com/problems/find-eventual-safe-states/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>

using namespace std;


class Solution {//dfs
public:
    bool isCycleDFS(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool>& inRecursion) {
        visited[u] = true;
        inRecursion[u] = true;
        
        
        for(int &v : adj[u]) {
            //if not visited, then we check for cycle in DFS
            if(visited[v] == false && isCycleDFS(adj, v, visited, inRecursion))
                return true;
            else if(inRecursion[v] == true)
                return true;
        }
        
        inRecursion[u] = false;
        return false;
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> visited(n, false);
        vector<bool> inRecursion(n, false);
        
        for(int i = 0; i<n; i++) {
            if(!visited[i]) isCycleDFS(graph, i, visited, inRecursion);
        }
        vector<int> safenode;
        for(int i=0;i<n;i++){
            if(inRecursion[i]==false) safenode.push_back(i);
        }
        return safenode;
    }
};


class Solution {//Ttopological sort
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
    // Sample Input
    vector<vector<int>> graph = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};

    Solution solution;
    vector<int> safeNodes = solution.eventualSafeNodes(graph);

    // Output the result
    cout << "Safe Nodes: ";
    for (int node : safeNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}