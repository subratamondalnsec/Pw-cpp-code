/* Problem Link - https://leetcode.com/problems/loud-and-rich/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>

using namespace std;

class Solution {//dfs
public:
    vector<list<int> >gr;
    int dfs(int node,vector<int>&vis,vector<int>& quiet){
        if(vis[node]!=-1) return vis[node];
        int mn=INT_MAX;
        int n=-1;
        for(auto nei : gr[node]){
            int val=dfs(nei,vis,quiet);
            if(mn>quiet[val]){
                mn=quiet[val];
                n=val;
            }
        }
        if(mn>quiet[node]){
            n=node;
        }
        return vis[node]=n;
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        gr.resize(n);
        for(int i=0;i<richer.size();i++){
            gr[richer[i][1]].push_back(richer[i][0]);
        }
        vector<int>vis(n,-1);
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int v=dfs(i,vis,quiet);
                ans.push_back(v);
            }
            else{
                ans.push_back(vis[i]);
            }
        }
        return ans;
    }
};

class Solution {//topological sort
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n=quiet.size();
        vector<list<int> >gr(n);
        vector<int> indegee(n,0);
        for(int i=0;i<richer.size();i++){
            gr[richer[i][0]].push_back(richer[i][1]);
            indegee[richer[i][1]]++;
        }
        queue<int> q;
        vector<int> answer(n);
        for(int i=0;i<n;i++){
            if(indegee[i] == 0){
                q.push(i);
            }
            answer[i] = i;
        }

        while(!q.empty()){
            int curr = q.front();
            int currQ = quiet[curr];
            q.pop();
            for(auto it:gr[curr]){
                if(currQ<quiet[it]){
                    answer[it] = answer[curr];
                    quiet[it] = currQ;
                }
                indegee[it]--;
                if(indegee[it] == 0)
                q.push(it);
            }
        }
        return answer;
    }
};

int main() {
    // Example input
    vector<vector<int>> richer = {{1, 0}, {2, 1}, {3, 1}, {3, 7}, {4, 3}, {5, 3}, {6, 3}};
    vector<int> quiet = {3, 2, 5, 4, 6, 1, 7, 0};

    Solution sol;
    vector<int> result = sol.loudAndRich(richer, quiet);

    // Output the result
    cout << "Result: ";
    for (int i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}