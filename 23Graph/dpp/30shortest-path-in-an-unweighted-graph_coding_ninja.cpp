/* Problem Link - https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=SUBMISSION
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

vector<int> shortestPath( vector<pair<int,int>> edges , int N , int M, int src , int des){
	vector<int>path(N,-1);
	vector<int> dis(N,-1);
	vector<bool> vis(N,0);
	vector<list<int> >gr(N);
	for(auto e : edges){
		gr[e.first-1].push_back(e.second-1);
		gr[e.second-1].push_back(e.first-1);
	}
	queue<int>q;
	src--;
	des--;
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
				path[nei]=cur;
			}
		}
	}
	vector<int>ans;
	while(des!=-1){
		ans.push_back(des+1);
		des=path[des];
	}
	reverse(ans.begin(),ans.end());
	return ans;
    
}

int main() {
    // Inputs
    int N = 6; // Number of nodes
    int M = 7; // Number of edges
    vector<pair<int, int>> edges = {
        {1, 2}, {1, 3}, {2, 4}, {2, 5}, {3, 5}, {4, 6}, {5, 6}
    };
    int src = 1; // Source node (1-based)
    int des = 6; // Destination node (1-based)

    // Call the function
    vector<int> result = shortestPath(edges, N, M, src, des);

    // Output the result
    cout << "Shortest path from " << src << " to " << des << ": ";
    for (int node : result) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}