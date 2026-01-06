/* Problem Link - https://leetcode.com/problems/number-of-provinces/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {//dfs Time complexity: O(n^2).Space complexity: O(n).
public:
    vector<int> vis;
    void dfs(vector<vector<int>>& gr,int i){
        if(vis[i]==1) return;
        vis[i]=1;
        for( int j=0;j<gr[i].size();j++){
            if(!vis[j] && gr[i][j]==1) dfs(gr,j);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vis.resize(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            dfs(isConnected,i);
            count++;
            }
        }
        return count;
    }
};

class Solution {//bfs Time complexity: O(n^2).Space complexity: O(n).
public:
    vector<int> vis;
    void bfs(vector<vector<int>>& gr,int i){
        queue<int>q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for( int j=0;j<gr[x].size();j++){
                if(!vis[j] && gr[x][j]==1){
                    q.push(j);
                    vis[j]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int m=isConnected[0].size();
        vis.resize(n,0);
        int count=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
            bfs(isConnected,i);
            count++;
            }
        }
        return count;
    }
};

class Solution {//DSU
public:

    int find(vector<int>&parent,int x){
    // T.c=O(log*(n));
    //this method return which group/cluster x belongs to 
        return parent[x] = (parent[x]==x) ? x : find(parent,parent[x]);
    }

    void Union(vector<int>& parent,vector<int>&rank ,int a,int b){
        // T.c=O(log*(n));
        a=find(parent,a);
        b=find(parent,b);
        if(a==b) return ;
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> parent(n);
        vector<int>rank(n,1);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    Union(parent,rank,i,j);
                }
            }
        }
        unordered_set<int>s;
        for(int i=0;i<n;i++){
            s.insert(find(parent,i));
        }
        return s.size();
    }
};


int main() {
    // Create an instance of the Solution class
    Solution solution;

    // Example input: isConnected matrix representing the cities' connections
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    // Call the findCircleNum function to find the number of provinces (connected components)
    int result = solution.findCircleNum(isConnected);

    // Output the result
    cout << "Number of provinces: " << result << endl;

    return 0;
}