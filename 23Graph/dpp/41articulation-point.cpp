/* Problem Link - https://www.geeksforgeeks.org/problems/articulation-point-1/1
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
  void dfs(int node,int parent,vector<int>adj[],vector<bool>&visit,vector<int>&disc,vector<int>&low,vector<bool>&ap,int& timer){
      visit[node]=1;
      disc[node]=low[node]=timer;
      int child=0;
      
      for(auto nei : adj[node]){
          if(nei==parent) continue;
          else if(visit[nei]) low[node]=min(low[node],disc[nei]);
          else{
              timer++;
              child++;
              dfs(nei,node,adj,visit,disc,low,ap,timer);
              if(disc[node]<=low[nei] && parent!=-1) ap[node]=1;
              
              low[node]=min(low[node],low[nei]);
          }
      }
      if(child>1 && parent==-1) ap[node]=1;
  }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        vector<bool>ap(V,0);
        vector<int>disc(V);
        vector<int>low(V);
         vector<bool>visit(V,0);
         int timer=0;
         dfs(0,-1,adj,visit,disc,low,ap,timer);
         vector<int>ans;
         for(int i=0;i<V;i++){
             if(ap[i]) ans.push_back(i);
         }
         if(ans.size()==0){
             ans.push_back(-1);
         }
         return ans;
    }
};

int main() {
    // Number of vertices
    int V = 5;

    // Graph representation (adjacency list)
    vector<int> adj[V];
    
    // Adding edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[0].push_back(2);
    adj[2].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[1].push_back(3);
    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[4].push_back(3);

    // Create a Solution object
    Solution sol;

    // Find articulation points
    vector<int> articulation_points = sol.articulationPoints(V, adj);

    // Print the articulation points
    cout << "Articulation points: ";
    for (int point : articulation_points) {
        cout << point << " ";
    }
    cout << endl;

    return 0;
}
/*
    0
   / \
  1---2
   |
   3
   |
   4

*/