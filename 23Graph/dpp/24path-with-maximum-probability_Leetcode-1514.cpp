/* Problem Link - https://leetcode.com/problems/path-with-maximum-probability/
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

class Solution {//same as dijkstra
#define di pair<double,int>
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<list<pair<int,double>> >gr(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back({edges[i][1],succProb[i]});
            gr[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>mp(n,0.0);
        priority_queue<di>pq;
        unordered_set<int>vis;
        pq.push({1.0,start_node});
        mp[start_node]=1.0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.second==end_node) return curr.first;
            if(vis.count(curr.second)) continue;
            vis.insert(curr.second);
            for(auto nei : gr[curr.second]){
                if(!vis.count(nei.first) && mp[nei.first] < mp[curr.second]*nei.second ){
                    mp[nei.first] = mp[curr.second]*nei.second;
                    pq.push({mp[nei.first],nei.first});
                }
            }   
        }
        return 0.0;
    }
};

class Solution {//normal
#define di pair<double,int>
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<list<pair<int,double>> >gr(n);
        for(int i=0;i<edges.size();i++){
            gr[edges[i][0]].push_back({edges[i][1],succProb[i]});
            gr[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double>mp(n,0.0);
        unordered_set<int>vis;
        priority_queue<di>pq;
        pq.push({1.0,start_node});
        mp[start_node]=1.0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.second==end_node) return curr.first;
            for(auto nei : gr[curr.second]){
                if( mp[nei.first]<curr.first*nei.second){
                    mp[nei.first]=curr.first*nei.second;
                    pq.push({curr.first*nei.second,nei.first});
                }
            }
        }
        return  0.0 ;
    }
};


class Solution { //variable  use
#define di pair<double, int>
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        // Build adjacency list
        vector<list<pair<int, double>>> gr(n);
        for (int i = 0; i < edges.size(); i++) {
            gr[edges[i][0]].push_back({edges[i][1], succProb[i]});
            gr[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        // Max-heap priority queue (max probabilities processed first)
        priority_queue<di> pq;
        vector<double> maxProb(n, 0.0); // Stores the max probability to each node
        maxProb[start_node] = 1.0; // Starting node has 100% probability
        pq.push({1.0, start_node});

        // Dijkstra's Algorithm
        while (!pq.empty()) {
            double currProb = pq.top().first; // Probability of current node
            int currNode = pq.top().second;  // Current node
            pq.pop();

            if (currNode == end_node) return currProb; // Early exit

            for (auto& nei : gr[currNode]) {
                int nextNode = nei.first;
                double edgeProb = nei.second;

                // Update if a better probability is found
                if (maxProb[nextNode] < currProb * edgeProb) {
                    maxProb[nextNode] = currProb * edgeProb;
                    pq.push({maxProb[nextNode], nextNode});
                }
            }
        }

        return 0.0; // If end_node is not reachable
    }
};


int main() {
    Solution solution;

    // Input: Number of nodes
    int n = 3;

    // Input: Graph edges (u, v) and success probabilities
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {0, 2}};
    vector<double> succProb = {0.5, 0.5, 0.2};

    // Input: Start node and end node
    int start_node = 0, end_node = 2;

    // Calling the function
    double result = solution.maxProbability(n, edges, succProb, start_node, end_node);

    // Output the result
    cout << "Maximum Probability: " << result << endl;

    return 0;
}