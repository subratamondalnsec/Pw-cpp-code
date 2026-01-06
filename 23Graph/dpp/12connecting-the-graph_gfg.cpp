/* Problem Link - https://www.geeksforgeeks.org/problems/connecting-the-graph/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
  public:
    int find(vector<int>&parent,int x){
// T.c=O(log*(n));
//this method return which group/cluster x belongs to 
        return parent[x] = (parent[x]==x) ? x : find(parent,parent[x]);
    }
    
    void Union(vector<int>& parent,vector<int>&rank ,int a,int b){
        // T.c=O(log*(n));
        a=find(parent,a);
        b=find(parent,b);
        if(a==b) return ;
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    
    int Solve(int n, vector<vector<int>>& edge) {
       vector<int> parent(n);
        vector<int>rank(n,0);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        int extraedge=0;
        for(auto el : edge){
            int u=el[0];
            int v=el[1];
            if(find(parent , u)==find(parent,v)) extraedge++;
            else Union(parent,rank,u,v);
        }
        int cc=0;
        for(int i=0;i<n;i++){
           if (find(parent,i)==i) cc++;
        }
        if(extraedge>=cc-1) return cc-1;
        return -1;
    }
};


int main() {
    Solution solution;  // Create an instance of the Solution class.
    
    int n; // Number of nodes.
    int m; // Number of edges.
    cin >> n >> m;

    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; ++i) {
        cin >> edges[i][0] >> edges[i][1]; // Read each edge (0-based indices assumed).
    }

    int result = solution.Solve(n, edges); // Call the Solve function.

    cout << result << endl; // Output the result.
    return 0;
}