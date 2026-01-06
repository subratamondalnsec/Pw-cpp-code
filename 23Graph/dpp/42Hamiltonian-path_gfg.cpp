/* Problem Link - https://www.geeksforgeeks.org/problems/hamiltonian-path2522/1
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<list<int>>gr;
    bool dfs(int node,vector<bool>&visit,int &count,int &N){
        visit[node]=1;
        count++;
        if(count==N) return 1;
        for(auto nei : gr[node]){
            if(!visit[nei] && dfs(nei,visit,count,N)) return 1;
        }
        visit[node]=0;
        count--;
        return 0;
    }
    bool check(int N,int M,vector<vector<int>> Edges){
        gr.resize(N);
        for(int i=0;i<M;i++){
            gr[Edges[i][0]-1].push_back(Edges[i][1]-1);
            gr[Edges[i][1]-1].push_back(Edges[i][0]-1);
        }
        vector<bool>visit(N,0);
        int count=0;
        for(int i=0;i<N;i++){
            if(dfs(i,visit,count,N)) return 1;
        }
        return 0;
    }
};


int main() {
    // Example input
    int N = 4; // Number of nodes
    int M = 4; // Number of edges
    vector<vector<int>> Edges = {
        {1, 2}, {2, 3}, {3, 4}, {4, 1}
    }; // Graph edges (1-based index)

    Solution obj;
    if (obj.check(N, M, Edges)) {
        cout << "Hamiltonian Path exists in the graph." << endl;
    } else {
        cout << "No Hamiltonian Path exists in the graph." << endl;
    }

    return 0;
}