/* Problem Link - https://leetcode.com/problems/critical-connections-in-a-network/
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node,int parent,vector<list<int>>&gr,vector<int>& disc,vector<int>&low,vector<bool> &visited,vector<vector<int>>&bridges,int &count){
        disc[node]=low[node]=count;
        visited[node]=1;
        for(auto nei : gr[node]){
            if(nei==parent) continue;
            else if(visited[nei]) low[node]=min(low[node],low[nei]);
            else {
                count++;
                dfs(nei,node,gr,disc,low,visited,bridges,count);
                //bridge exist or not
                low[node]=min(low[node],low[nei]);
                if(low[nei]>disc[node]){
                    vector<int>t;
                    t.push_back(node);
                    t.push_back(nei);
                    bridges.push_back(t);
                }
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<list<int>>gr(n);
        for(int i=0;i<connections.size();i++){
            gr[connections[i][0]].push_back(connections[i][1]);
            gr[connections[i][1]].push_back(connections[i][0]);
        }
        vector<vector<int>>bridges;
        vector<int> disc(n);
        vector<int> low(n);
        vector<bool> visited(n,0);
        int count=0;
        dfs(0,-1,gr,disc,low,visited,bridges,count);
        return bridges;
    }
};


int main() {
    // Number of nodes
    int n = 4;

    // Connections in the graph (edges)
    vector<vector<int>> connections = {
        {0, 1}, {1, 2}, {2, 0}, {1, 3}
    };

    // Create an instance of the Solution class
    Solution sol;

    // Find the critical connections (bridges)
    vector<vector<int>> result = sol.criticalConnections(n, connections);

    // Print the bridges
    cout << "Critical Connections: " << endl;
    for (const auto& bridge : result) {
        cout << "[" << bridge[0] << ", " << bridge[1] << "]" << endl;
    }

    return 0;
}
