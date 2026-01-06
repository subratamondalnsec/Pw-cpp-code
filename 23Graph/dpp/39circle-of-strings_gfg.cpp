/* Problem Link - https://www.geeksforgeeks.org/problems/circle-of-strings4530/1
 By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void dfs(int node,vector<list<int>>&gr,vector<bool>&vis){
        vis[node]=1;
        for(auto nei : gr[node]){
            if(!vis[nei]) dfs(nei,gr,vis);
        }
    }
    int isCircle(vector<string> &arr) {
        vector<list<int>>gr(26);
        vector<int>indeg(26,0);
        vector<int>outdeg(26,0);
        int n=arr.size();
        for(int i=0;i<n;i++){
            int u=arr[i][0]-'a';
            int v=arr[i][arr[i].size()-1]-'a';
            gr[u].push_back(v);
            outdeg[u]++;
            indeg[v]++;
        }
        ///Elureian circuit
        for(int i=0;i<26;i++){
            if(indeg[i]!=outdeg[i]) return 0;
        }
        vector<bool>vis(26,0);
        dfs(arr[0][0]-'a',gr,vis);
        for(int i=0;i<26;i++){
            if(indeg[i]&& !vis[i]) return 0;
        }
        return 1;
    }
};

int main() {
    Solution sol;
    vector<string> arr = {"abc", "cde", "efg", "ghi", "iab"};
    cout << sol.isCircle(arr) << endl; // Output should be 1 (true)
    return 0;
}