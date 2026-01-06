/* Problem Link - https://leetcode.com/problems/find-if-path-exists-in-graph/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {//bfs
public:
    vector<list<int>>gr;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        gr.resize(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
            gr[edges[i][1]].push_back(edges[i][0]);
        }
        queue<int>q;
        unordered_set<int>s;
        q.push(source);
        s.insert(source);
        while(!q.empty()){
            int curr=q.front();
            if(destination==curr) return true;
            q.pop();
            for(int nei : gr[curr]){
                if(!s.count(nei)){
                    q.push(nei);
                    s.insert(nei);
                }
            }
        }
        return false;
    }
};

class Solution {//dfs
public:
    vector<list<int>>gr;
    void dfs(int node,unordered_set<int>&s){
        s.insert(node);
        for(int nei : gr[node]){
            if(!s.count(nei)){
                dfs(nei,s);
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        gr.resize(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back(edges[i][1]);
            gr[edges[i][1]].push_back(edges[i][0]);
        }
        unordered_set<int>s;
        dfs(source,s);
        return s.count(destination);
    }
};

class Solution {// T.c=O(log*(n));Space Complexity : O(N) //dsu
public:

    int find(vector<int>&parent,int x){
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int>parent(n);
        vector<int>rank(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<edges.size();i++){
            Union(parent,rank,edges[i][0],edges[i][1]);
        }
        return find(parent,source)==find(parent,destination);
    }
};

int main() {
    Solution sol;

    // Example input
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {3, 5}, {5, 4}, {4, 3}};
    int source = 0;
    int destination = 5;

    // Function call
    if (sol.validPath(n, edges, source, destination)) {
        cout << "Path exists between " << source << " and " << destination << endl;
    } else {
        cout << "No path exists between " << source << " and " << destination << endl;
    }
    return 0;
}
