
/* Problem Link - https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
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
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<list<pp > > gr(n+1);
        for(auto e : edges){
            gr[e[0]].push_back({e[1],e[2]});
            gr[e[1]].push_back({e[0],e[2]});
        }
       priority_queue<pp,vector<pp> ,greater<pp> >q;
       vector<int>dis(n+1,INT_MAX);
       unordered_set<int>vis;
       vector<int>parent(n+1,-1);
       dis[1]=0;
       q.push({0,1});
       while(!q.empty()){
           auto curr=q.top();
           q.pop();
           if(vis.count(curr.second)) continue;
           vis.insert(curr.second);
           for(auto nei : gr[curr.second]){
               if(!vis.count(nei.first) && dis[nei.first]>dis[curr.second]+nei.second){
                   dis[nei.first]=dis[curr.second]+nei.second;
                   q.push({dis[nei.first],nei.first});
                   parent[nei.first]=curr.second;
               }
           }
       }
       vector<int>path;
       if(parent[n]==-1){
           path.push_back(-1);
           return path;
       } 
       int dest=n;
       while(dest!=-1){
           path.push_back(dest);
           dest=parent[dest];
       }
       path.push_back(dis[n]);
       
       reverse(path.begin(),path.end());
       return path;
    }
};


int main() {
    int n = 5; // Number of nodes
    int m = 6; // Number of edges

    // Edges in the format {u, v, weight}
    vector<vector<int>> edges = {
        {1, 2, 2},
        {1, 4, 1},
        {2, 3, 3},
        {4, 5, 7},
        {2, 5, 4},
        {3, 5, 1}
    };

    Solution sol;
    vector<int> result = sol.shortestPath(n, m, edges);

    // Output the result
    if (result[0] == -1) {
        cout << "No path exists to the destination node.\n";
    } else {
        cout << "Shortest Path: ";
        for (size_t i = 0; i < result.size() - 1; ++i) {
            cout << result[i] << " ";
        }
        cout << "\nPath Cost: " << result.back() << endl;
    }

    return 0;
}

/*
    2       3
1 ----> 2 ----> 3
|        \       |
1         4      1
 \        |      |
  -----> 4 ----> 5
         7       1


Shortest Path: 1 2 5 
Path Cost: 6

*/