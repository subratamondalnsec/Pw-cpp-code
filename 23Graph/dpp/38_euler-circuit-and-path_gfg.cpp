/* Problem Link - https://www.geeksforgeeks.org/problems/euler-circuit-and-path/1
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        for (auto neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int isEulerCircuit(int V, vector<int> adj[]) {
        vector<int> degree(V, 0);
        int odd_deg = 0;

        // Count degrees of vertices
        for (int i = 0; i < V; i++) {
            degree[i] = adj[i].size();
            if (degree[i] % 2 != 0) {
                odd_deg++;
            }
        }

        // Euler Circuit and Euler Path check
        if (odd_deg != 2 && odd_deg != 0) return 0;

        // Check if all vertices with non-zero degree are connected
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (degree[i] > 0) {
                dfs(i, adj, visited);
                break;
            }
        }

        // Check if any vertex with a degree is unvisited
        for (int i = 0; i < V; i++) {
            if (degree[i] > 0 && !visited[i]) {
                return 0;
            }
        }

        // Euler Circuit: All vertices have even degrees
        if (odd_deg == 0) return 2;

        // Euler Path: Exactly two vertices have odd degrees
        return 1;
    }
};

int main() {
    // Number of vertices and edges
    int V = 5;
    vector<int> adj[V];

    // Add edges to the graph
    adj[0].push_back(1);
    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[3].push_back(2);
    adj[3].push_back(4);
    adj[4].push_back(3);

    Solution sol;
    int result = sol.isEulerCircuit(V, adj);

    // Print result
    if (result == 2) {
        cout << "The graph has an Euler Circuit." << endl;
    } else if (result == 1) {
        cout << "The graph has an Euler Path." << endl;
    } else {
        cout << "The graph has neither an Euler Path nor an Euler Circuit." << endl;
    }

    return 0;
}
