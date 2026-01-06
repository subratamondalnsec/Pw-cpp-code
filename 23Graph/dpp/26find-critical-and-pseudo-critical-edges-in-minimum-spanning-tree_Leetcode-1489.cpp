/* Problem Link - https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
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

class Solution {  //normal kruskal
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
        int index;
    };

    static bool cmp(Edge e1, Edge e2) {
        return e1.wt < e2.wt;
    }

    int kruskals(vector<Edge> &input, int n,int skip_edge,int add_edge) { // O(V + ElgE)
        vector<int> parent(n);
        vector<int> rank(n, 1);
        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int edgeCount = 0; // n-1
        int i = 0;
        int ans = 0;
        if(add_edge != -1){
            Edge &e = input[add_edge];
            Union(parent, rank, e.src, e.dest);
            edgeCount++;
            ans+=e.wt;
        }
        while(edgeCount < n-1 and i < input.size()) { // V-1 -> O(Vlg*V)
            if(i==skip_edge){
                i++;
                continue;
            } 
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
        if (edgeCount < n - 1) return INT_MAX;
        return ans;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> v(edges.size());
        for(int i = 0; i < edges.size(); i++) {
            v[i]={edges[i][0], edges[i][1], edges[i][2], i};
        }
        sort(v.begin(), v.end(), cmp); // ElgE
        int mst_weight=kruskals(v,n,-1,-1);
        vector<int>critcal;
        vector<int>Pseudo_critcal;
        for(int i=0;i<edges.size();i++){
            if(kruskals(v,n,i,-1)>mst_weight){//skiping i th edge
                critcal.push_back(v[i].index);
            }
            else if(kruskals(v,n,-1,i)==mst_weight){//force add this edge
                Pseudo_critcal.push_back(v[i].index);
            }
        }
        return {critcal,Pseudo_critcal};
    }
};


class Solution {//modified kruskal
public:
    int find(vector<int> &parent, int a) {
        return parent[a] = ((parent[a] == a) ? a : find(parent, parent[a]));
    }

    void Union(vector<int> &par, vector<int> &rank, int a, int b) {
        a = find(par, a);
        b = find(par, b);
        if (a == b) return;
        if (rank[a] > rank[b]) {
            par[b] = a;
        } else if (rank[a] < rank[b]) {
            par[a] = b;
        } else {
            par[b] = a;
            rank[a]++;
        }
    }

    struct Edge {
        int src, dest, wt, index;
    };

    static bool cmp(Edge e1, Edge e2) {
        return e1.wt < e2.wt;
    }

    int kruskals(vector<Edge> &edges, int n, int skip_edge, int add_edge) {
        vector<int> parent(n);
        vector<int> rank(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int edgeCount = 0, mstWeight = 0;

        // Forcefully add the edge if specified
        if (add_edge != -1) {
            Edge &e = edges[add_edge];
            Union(parent, rank, e.src, e.dest);
            mstWeight += e.wt;
            edgeCount++;
        }

        for (int i = 0; i < edges.size(); i++) {
            if (i == skip_edge) continue;

            Edge &e = edges[i];
            int u = find(parent, e.src);
            int v = find(parent, e.dest);

            if (u != v) {
                Union(parent, rank, u, v);
                mstWeight += e.wt;
                edgeCount++;
            }

            if (edgeCount == n - 1) break;
        }

        // If we couldn't connect all nodes, return a large value
        if (edgeCount < n - 1) return INT_MAX;

        return mstWeight;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<Edge> edgeList(edges.size());
        for (int i = 0; i < edges.size(); i++) {
            edgeList[i] = {edges[i][0], edges[i][1], edges[i][2], i};
        }

        sort(edgeList.begin(), edgeList.end(), cmp);

        int mstWeight = kruskals(edgeList, n, -1, -1);

        vector<int> critical, pseudoCritical;
        for (int i = 0; i < edges.size(); i++) {
            // Check if the edge is critical
            if (kruskals(edgeList, n, i, -1) > mstWeight) {
                critical.push_back(edgeList[i].index);
            }
            // Check if the edge is pseudo-critical
            else if (kruskals(edgeList, n, -1, i) == mstWeight) {
                pseudoCritical.push_back(edgeList[i].index);
            }
        }

        return {critical, pseudoCritical};
    }
};


int main() {
    Solution sol;
    int n = 5;
    vector<vector<int>> edges = {
        {0, 1, 1}, {1, 2, 1}, {2, 3, 2}, {0, 3, 2}, {0, 4, 3}
    };
    vector<vector<int>> result = sol.findCriticalAndPseudoCriticalEdges(n, edges);
    cout << "Critical Edges: ";
    for (int x : result[0]) cout << x << " ";
    cout << "\nPseudo-Critical Edges: ";
    for (int x : result[1]) cout << x << " ";
    return 0;
}

