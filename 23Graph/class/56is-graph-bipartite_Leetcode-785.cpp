/* Problem Link - https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;
class Solution {//bfs
public:
    bool bfs(int src, vector<int> &color, int n, vector<vector<int>>& graph) {
        queue<int> qu;
        
        qu.push(src);
        color[src] = 0;
        while(not qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for(auto neighbour : graph[curr]) {
                if(color[neighbour] == -1) {
                    color[neighbour] = !color[curr];
                    qu.push(neighbour);
                } else if(color[curr] == color[neighbour]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i = 0; i < graph.size(); i++) {
            if(color[i] == -1) {
                if(bfs(i, color, n, graph) == false) return false;
            }
        }
        return true;
    }
};


class Solution {//dfs
  public:
    bool dfs(int src,vector<vector<int>>& adj,vector<int>&col){
        for(int nei : adj[src]){
            if(col[nei]==-1){
                col[nei]=!col[src];
                if(dfs(nei,adj,col)== false) return false;
            }
            else if(col[nei]==col[src]){
                return false;
            } 
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>col(n,-1);
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                col[i]=0;
                if(dfs(i,adj,col)==false ) return false;
            }
        }
       return true;
    }
};


int main() {
    Solution sol;
    // Example graph as adjacency list
    vector<vector<int>> graph = {
        {1, 3},
        {0, 2},
        {1, 3},
        {0, 2}
    };

    // Call the function and print the result
    if (sol.isBipartite(graph)) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
