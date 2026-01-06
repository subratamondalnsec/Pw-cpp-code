#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <map>
using namespace std;

class Solution {//bfs method
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1) return -1; // Starting point is blocked
        if (grid[0][0] == 0 && n == 1) return 1; // Single cell grid and it's open

        queue<pair<int, int>> q;
        int level = 0;
        q.push({0, 0});
        grid[0][0] = 1; // Mark as visited

        vector<vector<int>> dir = {{0, -1}, {-1, -1}, {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1} };// All 8 directions

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if (x == n - 1 && y == n - 1) return level + 1; // Found path
                for (int i = 0; i < 8; i++) {
                    int nx = x + dir[i][0];
                    int ny = y + dir[i][1];

                    if (nx >= 0 && ny >= 0 && nx < n && ny < n && grid[nx][ny] == 0) {
                        grid[nx][ny] = 1; // Mark as visited
                        q.push({nx, ny});
                    }
                }
            }
            level++;
        }

        return -1; // No path found
    }
};

class Solution {//t.c=O(VLogV) Space Complexity : O(V) dijkstra using map
typedef pair<int,pair<int,int>> pp;
public:
    vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 and n==1) return 1;
        
        priority_queue<pp, vector<pp> , greater<pp> > pq;
        map<pair<int,int>, int> mp;
        for(int i = 0; i < n; i++) { 
            for(int j = 0; j < n; j++) {
                mp[{i,j}] = INT_MAX;
            }
        }
        pq.push({0, {0,0}});
        mp[{0,0}] = 0;
        while(!pq.empty()) {
            int d=pq.top().first;
            auto curr=pq.top().second;
            int x=curr.first;
            int y=curr.second;
            pq.pop();

            for(auto di : dir){
                int nx=x+di[0];
                int ny=y+di[1];
                int dist=1;
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && mp[{nx, ny}]>d+dist ){
                    grid[nx][ny]=1;
                    pq.push({d+dist,{nx,ny}});
                    mp[{nx,ny}]=d+dist;
                }
            }
        }
        if(mp[{n-1,n-1}]==INT_MAX) return -1;
        return mp[{n-1,n-1}]+1;
    }
};

class Solution { // dijkstra using vector
typedef pair<int,pair<int,int>> pp;
public:
    vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 and n==1) return 1;
        
        priority_queue<pp, vector<pp> , greater<pp> > pq;

        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        pq.push({0, {0,0}});
        result[0][0] = 0;
        while(!pq.empty()) {
            int d=pq.top().first;
            auto curr=pq.top().second;
            int x=curr.first;
            int y=curr.second;
            pq.pop();

            for(auto di : dir){
                int nx=x+di[0];
                int ny=y+di[1];
                int dist=1;
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && result[nx][ny]>d+dist ){
                    grid[nx][ny]=1;
                    pq.push({d+dist,{nx,ny}});
                    result[nx][ny]=d+dist;
                }
            }
        }
        if(result[n-1][n-1]==INT_MAX) return -1;
        return result[n-1][n-1]+1;
    }
};

class Solution {//dijkstra using vector and queue
typedef pair<int,pair<int,int>> pp;
public:
    vector<vector<int>>dir={{0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1}};
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1) return -1;
        if(grid[0][0]==0 and n==1) return 1;
        
        queue<pp> pq;

        vector<vector<int>> result(n, vector<int>(n, INT_MAX));
        pq.push({0, {0,0}});
        result[0][0] = 0;
        while(!pq.empty()) {
            int d=pq.front().first;
            auto curr=pq.front().second;
            int x=curr.first;
            int y=curr.second;
            pq.pop();

            for(auto di : dir){
                int nx=x+di[0];
                int ny=y+di[1];
                int dist=1;
                if(nx>=0 && ny>=0 && nx<n && ny<n && grid[nx][ny]==0 && result[nx][ny]>d+dist ){
                    grid[nx][ny]=1;
                    pq.push({d+dist,{nx,ny}});
                    result[nx][ny]=d+dist;
                }
            }
        }
        if(result[n-1][n-1]==INT_MAX) return -1;
        return result[n-1][n-1]+1;
    }
};


int main() {
    Solution solution;

    // Example test case
    vector<vector<int>> grid = {
        {0, 1, 0},
        {1, 0, 0},
        {1, 1, 0}
    };

    int result = solution.shortestPathBinaryMatrix(grid);
    cout << "Shortest path in binary matrix: " << result << endl;

    return 0;
}
