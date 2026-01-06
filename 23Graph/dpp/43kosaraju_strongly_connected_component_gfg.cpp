/* Problem Link - https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?track=SPC-GA
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution{
	public:
	//Function to find number of strongly connected components in the graph.
	void topo_dfs(int node,vector<vector<int>>& adj,vector<bool>&visit,stack<int>&s){
	    visit[node]=1;
	    for(auto nei : adj[node]){
	        if(!visit[nei]) topo_dfs(nei,adj,visit,s);
	    }
	    s.push(node);
	}
	void dfs(int node,vector<vector<int>>&adj2,vector<bool>&visit){
        visit[node]=1;
        for(auto nei : adj2[node]){
            if(!visit[nei]) dfs(nei,adj2,visit);
        }
	}
    int kosaraju(int V, vector<vector<int>>& adj){
       stack<int>s;
       vector<bool>visit(V,0);
       for(int i=0;i<V;i++){
           if(!visit[i]) topo_dfs(i,adj,visit,s);
       }
       vector<vector<int>> adj2(V);//reverse edge
       for(int i=0;i<V;i++){
           for(int j=0;j<adj[i].size();j++){
               int u=i;
               int v=adj[i][j];
               adj2[v].push_back(u);
           }
       }
       visit.clear();
       visit.resize(V,0);
       int scc=0;
       while(!s.empty()){
           int node=s.top();
           s.pop();
           if(!visit[node]){
               scc++;
               dfs(node,adj2,visit);
           }
       }
       return scc;
    }
};

int main() {
    int V, E; // Number of vertices and edges
    cin >> V >> E;
    vector<vector<int>> adj(V); // Adjacency list representation of the graph

    // Input edges
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // Create an instance of the solution class and call the function
    Solution obj;
    int result = obj.kosaraju(V, adj);

    // Output the result
    cout << "Number of Strongly Connected Components: " << result << endl;

    return 0;
}