/* Problem Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {//dfs
  public:
  void dfs(int node ,vector<list<pair<int,int>>>&gr,vector<int>& dis){
      for(auto nei : gr[node]){
          if(dis[nei.first]>dis[node]+nei.second){
              dis[nei.first]=dis[node]+nei.second;
              dfs(nei.first,gr,dis);
            }
        }
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<list<pair<int,int>>>gr(V);
        for(auto e : edges){
            gr[e[0]].push_back({e[1],e[2]});
        }
        vector<int> dis(V, INT_MAX);
        dis[0]=0;
        //for(int i=0;i<v )
        dfs(0,gr,dis);
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};

class Solution {//topological
  public:
    void dfs(int node,vector<list<pair<int,int>>>& adj,vector<bool>&visit,stack<int>&s){
        visit[node]=true;
        for(auto nei : adj[node]){
            if(!visit[nei.first]) dfs(nei.first,adj,visit,s);
        }
        s.push(node);
    }
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        vector<list<pair<int,int>>>gr(V);
        for(auto e : edges){
            gr[e[0]].push_back({e[1],e[2]});
        }
        vector<int> dis(V, INT_MAX);
        dis[0]=0;
        stack<int>s;
        vector<bool>vis(V,0);
        vis[0]=true;
        dfs(0,gr,vis,s);
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto nei : gr[node]){
                dis[nei.first]=min(dis[nei.first],nei.second+dis[node]);
            }
        }
        for(int i=0;i<V;i++){
            if(dis[i]==INT_MAX) dis[i]=-1;
        }
        return dis;
    }
};

int main() {
    // Inputs
    int V = 5; // Number of vertices
    int E = 6; // Number of edges
    vector<vector<int>> edges = {
        {0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 3, 4}, {2, 3, 1}
    };

    // Solution object
    Solution sol;

    // Call the shortestPath function
    vector<int> result = sol.shortestPath(V, E, edges);

    // Output the result
    cout << "Shortest distances from source 0:" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}


/*
     2       3
  0 ---> 1 ----> 2
   \      \      |
    1      4     1
     \      \    |
      ---> 4 --->3
          2     4

{0, 1, 2}, {0, 4, 1}, {1, 2, 3}, {4, 2, 2}, {4, 3, 4}, {2, 3, 1}
Shortest distances from source 0:
Node 0: 0
Node 1: 2
Node 2: 3
Node 3: 4
Node 4: 1

*/