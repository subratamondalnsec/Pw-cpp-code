/* Problem Link - https://leetcode.com/problems/divide-nodes-into-the-maximum-number-of-groups/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    bool Bipartite(int src, vector<int>& color, vector<list<int>>& graph) {
        queue<int> qu;
        qu.push(src);
        color[src] = 0;

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for (auto neighbour : graph[curr]) {
                if (color[neighbour] == -1) {
                    color[neighbour] = !color[curr];
                    qu.push(neighbour);
                } else if (color[curr] == color[neighbour]) {
                    return false; // Not bipartite
                }
            }
        }
        return true;
    }

    int bfsmaxlength(const vector<int>& component, vector<list<int>>& graph) {
        int maxDepth = 0;

        for (int start : component) {
            unordered_set<int> visited;
            queue<int> qu;
            qu.push(start);
            visited.insert(start);

            int depth = 0;
            while (!qu.empty()) {
                int levelSize = qu.size();
                depth++;

                while (levelSize--) {
                    int curr = qu.front();
                    qu.pop();
                    for (int neighbour : graph[curr]) {
                        if (!visited.count(neighbour)) {
                            qu.push(neighbour);
                            visited.insert(neighbour);
                        }
                    }
                }
            }
            maxDepth = max(maxDepth, depth);
        }

        return maxDepth;
    }

    int magnificentSets(int n, vector<vector<int>>& edges) {
        // Graph construction
        vector<list<int>> graph(n + 1);
        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        // Bipartite check
        vector<int> color(n + 1, -1);
        for (int i = 1; i <= n; i++) {
            if (color[i] == -1 && !Bipartite(i, color, graph)) {
                return -1; // Graph is not bipartite
            }
        }

        // Find connected components
        vector<bool> visited(n + 1, false);
        int result = 0;

        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                // Perform BFS to find the connected component
                vector<int> component;
                queue<int> qu;
                qu.push(i);
                visited[i] = true;

                while (!qu.empty()) {
                    int curr = qu.front();
                    qu.pop();
                    component.push_back(curr);

                    for (int neighbour : graph[curr]) {
                        if (!visited[neighbour]) {
                            qu.push(neighbour);
                            visited[neighbour] = true;
                        }
                    }
                }
                // Compute the maximum BFS depth for this component
                result += bfsmaxlength(component, graph);
            }
        }
        return result;
    }
};

int main() {
    // Input: Number of nodes and edges
    int n, m;
    cin >> n >> m;

    // Input: Edges
    vector<vector<int>> edges(m, vector<int>(2));
    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the magnificentSets function and output the result
    int result = solution.magnificentSets(n, edges);
    cout << result << endl;

    return 0;
}
