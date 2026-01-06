/* Problem Link - https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
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
  public:
    /*  Function to implement Bellman Ford
     *   edges: vector of vectors which represents the graph
     *   src: source vertex
     *   V: number of vertices
     */
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        vector<int>dist(V,1e8);
        dist[src]=0;
        int e= edges.size();
        
        for(int i=0;i<V-1;i++){
            bool flag= 0;
            for(int j=0;j<e;j++){
                int u=edges[j][0];
                int v=edges[j][1];
                int wt=edges[j][2];
                if(dist[u]==1e8) continue;
                if(dist[v]>dist[u]+wt){
                    dist[v]=dist[u]+wt;
                    flag=1;
                }
            }
            if(flag==0) return dist;
        }
        
        for(int j=0;j<e;j++){
            int u=edges[j][0];
            int v=edges[j][1];
            int wt=edges[j][2];
            if(dist[u]==1e8) continue;
            if(dist[v]>dist[u]+wt){
                vector<int>ans;
                ans.push_back(-1);
                return ans;
            }
        }
        return dist;
    }
};

int main() {
    Solution obj;

    // Number of vertices (V) and edges (E)
    int V = 5;
    int E = 8;

    // Edges represented as {u, v, weight}
    vector<vector<int>> edges = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2}, 
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };

    // Source vertex
    int src = 0;

    // Run Bellman-Ford algorithm
    vector<int> distances = obj.bellmanFord(V, edges, src);

    // Check and print the result
    if (distances.size() == 1 && distances[0] == -1) {
        cout << "Negative weight cycle detected" << endl;
    } else {
        cout << "Shortest distances from source " << src << ":" << endl;
        for (int i = 0; i < V; i++) {
            cout << "Vertex " << i << " : ";
            if (distances[i] == 1e8) {
                cout << "Infinity" << endl; // Node is unreachable
            } else {
                cout << distances[i] << endl;
            }
        }
    }

    return 0;
}