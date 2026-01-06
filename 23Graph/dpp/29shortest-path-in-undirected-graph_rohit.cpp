/* Problem Link - https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1
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
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
       vector<int> dis(N,-1);
       vector<bool> vis(N,0);
       vector<list<int> >gr(N);
       for(auto e : edges){
           gr[e[0]].push_back(e[1]);
            gr[e[1]].push_back(e[0]);
       }
       queue<int>q;
       q.push(src);
       dis[src]=0;
       vis[src]=1;
       while(!q.empty()){
           int cur=q.front();
           q.pop();
           for(auto nei : gr[cur]){
               if(!vis[nei]){
                   dis[nei]=dis[cur]+1;
                   q.push(nei);
                   vis[nei]=1;
               }
           }
       }
       return dis;
    }
};
int main() {
    // Inputs
    int N = 5; // Number of nodes
    int M = 6; // Number of edges
    vector<vector<int>> edges = {
        {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 4}, {3, 4}
    };
    int src = 0; // Source vertex

    // Solution object
    Solution sol;
    
    // Call the shortestPath function
    vector<int> result = sol.shortestPath(edges, N, M, src);

    // Output the result
    cout << "Shortest distances from source " << src << ":" << endl;
    for (int i = 0; i < result.size(); ++i) {
        cout << "Node " << i << ": " << result[i] << endl;
    }

    return 0;
}