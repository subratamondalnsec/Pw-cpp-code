/*
code by Subrata Mondal
*/

#include <bits/stdc++.h>
using namespace std;

vector<list<int> > graph;
int v; // no of vertices
void add_edge(int a, int b, bool bidir = true) {
    graph[a].push_back(b); // a->b
    if(bidir) {
        graph[b].push_back(a);
    }
}

void topoBFS() {
    // Kahn algo
    vector<int> indegree(v, 0);
    for(int i = 0 ; i < v; i++){
        for(auto neighbour : graph[i]){
            // i ---> neighbour
            indegree[neighbour]++;
        }
    }
    queue<int> qu;
    unordered_set<int> vis;
    for(int i = 0; i < v; i++){
        if(indegree[i] == 0){
            qu.push(i);
            vis.insert(i);
        }
    }
    cout<<"starting bfs\n";
    while(not qu.empty()){
        int node = qu.front();
        cout<<node<<" ";
        qu.pop();
        for(auto neighbour : graph[node]){
            if(not vis.count(neighbour)) {
                indegree[neighbour]--;
                if(indegree[neighbour] == 0){
                    qu.push(neighbour);
                    vis.insert(neighbour);
                }
            }
        }
    }
} 

int main() {
    cin>>v;
    int e;
    cin>>e;
    graph.resize(v, list<int> ());
    while(e--) {
        int x, y;
        cin>>x>>y;
        add_edge(x, y, false);//directed 
    }
    topoBFS();
    return 0;
}

/* acyclic
8 8
0 2
2 4
1 2
4 6
2 6
2 5
2 3
3 5
cyclic
8 8
0 2
2 4
1 2
4 6
6 2
2 5
2 3
3 5
*/