/* Problem Link - https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/
 By subrata mondal */
#include <bits/stdc++.h>
#define ll long long int
using namespace std;
class Solution {
public:
    int find(vector<int> &parent, int a) {
        return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
    }

    void Union(vector<int> &par, vector<int> &rank, int a, int b) {
        a = find(par, a);
        b = find(par, b);
        if (a == b) return;
        if (rank[a] >= rank[b]) {
            rank[a]++;
            par[b] = a;
        } else {
            rank[b]++;
            par[a] = b;
        }
    }
    struct Edge {
    int src;
    int dest;
    int wt;
    };

    bool cmp(Edge e1, Edge e2) {
        return e1.wt < e2.wt;
    }

    int minimumCost(int n, vector<vector<int>>& connections) {
        // Convert input to edges
        vector<Edge> edges;
        for (const auto &c : connections) {
            edges.push_back({c[0], c[1], c[2]});
        }
        
        // Sort edges by weight
        sort(edges.begin(), edges.end(), cmp);
        
        // DSU setup
        vector<int> parent(n + 1);
        vector<int> rank(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
        
        // Kruskal's MST
        int edgeCount = 0;
        int totalCost = 0;
        for (const auto &edge : edges) {
            int u = edge.src, v = edge.dest, w = edge.wt;
            if (find(parent, u) != find(parent, v)) {
                Union(parent, rank, u, v);
                totalCost += w;
                edgeCount++;
            }
        }
        
        // If we have less than n-1 edges, MST is not possible
        return (edgeCount == n - 1) ? totalCost : -1;
    }
};
