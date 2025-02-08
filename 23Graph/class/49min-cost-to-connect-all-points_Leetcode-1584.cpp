/* Problem Link - https://leetcode.com/problems/connecting-cities-with-minimum-cost/description/
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int find(vector<int> &parent, int a) {
        return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
    }

    void Union(vector<int> &par, vector<int> &rank, int a, int b) {
        a = find(par, a);
        b = find(par, b);
        if(a == b) return;
        if(rank[a] >= rank[b]) {
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

    static bool cmp(Edge e1, Edge e2) {
        return e1.wt < e2.wt;
    }

    int kruskals(vector<Edge> &input, int n) { // O(V + ElgE)
        sort(input.begin(), input.end(), cmp); // ElgE
        vector<int> parent(n+1);
        vector<int> rank(n+1, 1);
        for(int i = 0; i <= n; i++) {
            parent[i] = i;
        }
        int edgeCount = 0; // n-1
        int i = 0;
        int ans = 0;
        while(edgeCount < n-1 and i < input.size()) { // V-1 -> O(Vlg*V)
            Edge curr = input[i]; // because input is sorted so we will get min wt edge
            int srcPar = find(parent, curr.src);
            int destpar = find(parent, curr.dest);
            if(srcPar != destpar) {
                // include edge as this will not make cycle
                Union(parent, rank, srcPar, destpar);
                ans += curr.wt;
                edgeCount++;
            }

            i++; // doesnt matter u picked the last edge or not, we still need to go to next edge
        }

        return ans;

    }

    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        int e=(n*(n-1))/2;
        vector<Edge> v;
        for(int i=0;i<e;i++){
            for(int j=i+1;j<n;j++){
                Edge eg;
                eg.src=i;
                eg.dest=j;
                eg.wt=(abs(points[i][0]-points[j][0]) + abs(points[i][1]-points[j][1]));
                v.push_back(eg);
            }
        }
        return kruskals(v,n);
    }
};


int main() {
    Solution sol;

    // Example input
    vector<vector<int>> points = {{0, 0}, {2, 2}, {3, 10}, {5, 2}, {7, 0}};

    // Calculate the minimum cost to connect all points
    int result = sol.minCostConnectPoints(points);

    // Output the result
    cout << "Minimum cost to connect all points: " << result << endl;

    return 0;
}
/*
Overall Time Complexity:
Edge creation: 𝑂(𝑛2)
Sorting edges: O(ElogE), where E=n(n−1)/2
Kruskal's union-find operations: O(Elog∗V)
Total:  𝑂(𝑛2log𝑛)
*/