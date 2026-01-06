
/* Problem Link - https://www.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
#define pp pair<int,int>
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        int n=adj.size();
       priority_queue<pp,vector<pp> ,greater<pp> >q;
       vector<int>dis(n,INT_MAX);
       unordered_set<int>vis;
       dis[src]=0;
       q.push({0,src});
       while(!q.empty()){
           auto curr=q.top();
           q.pop();
           if(vis.count(curr.second)) continue;
           vis.insert(curr.second);
           for(auto nei : adj[curr.second]){
               if(!vis.count(nei.first) && dis[nei.first]>dis[curr.second]+nei.second){
                   dis[nei.first]=dis[curr.second]+nei.second;
                   q.push({dis[nei.first],nei.first});
               }
           }
       }
        for (int i = 0; i < n; i++) {
            if (dis[i] == INT_MAX) dis[i] = -1;
        }

       return dis;
       
    }
};

int main() {
    int V = 5; // Number of vertices
    int E = 6; // Number of edges

    // Adjacency list representation: {to, weight}
    vector<vector<pair<int, int>>> adj(V);
    adj[0] = {{1, 2}, {4, 1}};
    adj[1] = {{2, 3}};
    adj[4] = {{2, 2}, {3, 4}};
    adj[2] = {{3, 1}};

    int src = 0; // Source vertex

    Solution sol;
    vector<int> result = sol.dijkstra(adj, src);

    // Output the result
    cout << "Shortest distances from source " << src << ":\n";
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}

/*
    2       3
0 ----> 1 ----> 2
|        \       |
1         4      1
 \        |      |
  -----> 4 ----> 3
         2       4
Shortest distances from source 0:
Node 0: 0
Node 1: 2
Node 2: 3
Node 3: 4
Node 4: 1

*/