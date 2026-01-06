/* Problem Link - https://leetcode.com/problems/count-sub-islands/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <list>
#include <utility>
using namespace std;

class Solution { //dfs
public:
    vector<vector<int>> ans; // Stores the results
    int x, y;                // Top-left corner of the farmland
    vector<vector<int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}}; // Directions for DFS

    // Perform DFS to find the farmland boundaries
    void dfs(vector<vector<int>>& land, int i, int j, int& maxX, int& maxY) {
        if (i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 1)
            return;

        // Update the bottom-right corner of the farmland
        maxX = max(maxX, i);
        maxY = max(maxY, j);

        // Mark as visited
        land[i][j] = -1;

        // Explore neighbors
        for (auto& d : dir) {
            int nx = i + d[0];
            int ny = j + d[1];
            dfs(land, nx, ny, maxX, maxY);
        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (land[i][j] == 1) {
                    // Start of a new farmland
                    x = i;
                    y = j;
                    int maxX = i, maxY = j;

                    // Perform DFS to find the bottom-right corner
                    dfs(land, i, j, maxX, maxY);

                    // Add the farmland to the result
                    ans.push_back({x, y, maxX, maxY});
                }
            }
        }
        return ans;
    }
};

class Solution {//bfs
public:
    vector<vector<int>>ans;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void bfs(vector<vector<int>>& land,int i,int j,int &mx ,int& my){
        queue<pair<int,int > >q;
        q.push({i,j});
        land[i][j]=-1;
        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            mx = max(mx, x);
            my = max(my, y);
            q.pop();
            for(auto &d :dir){
                int nx=x+d[0];
                int ny=y+d[1];
                 if (nx >= 0 && ny >= 0 && nx < land.size() && ny < land[0].size() && land[nx][ny] == 1) {
                    land[nx][ny] =-1;
                    q.push({nx,ny});
                }
            }
        }
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m=land.size();
        int n=land[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j]==1){
                    int x=i,y=j;
                    int maxX = i, maxY = j;

                    // Perform DFS to find the bottom-right corner
                    bfs(land, i, j, maxX, maxY);

                    // Add the farmland to the result
                    ans.push_back({x, y, maxX, maxY});
                }
            }
        }
        return ans;
    }
};

//Approach-3 (Brute Force Greedy)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int m = land.size();
        int n = land[0].size();
        
        vector<vector<int>> result;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                
                if(land[i][j] == 0) continue;
                
                //find the right most column of the current group
                int c1 = j;
                while(c1 < n && land[i][c1] == 1) {
                    c1++;
                }
                
                //find the bottom most row of the current group
                int r1 = i;
                while(r1 < m && land[r1][j] == 1) {
                    r1++;
                }
                
                c1 = c1 == 0 ?  c1 : c1-1;
                r1 = r1 == 0 ?  r1 : r1-1;
                
                result.push_back({i, j, r1, c1});
                
                
                //mark all the inbetween 1s to 0s
                for(int k = i; k <= r1; k++) {
                    for(int l = j; l <= c1; l++) {
                        land[k][l] = 0; //visited
                    }
                }
                
                
            }
        }
        
        return result;
        
        
    }
};


int main() {
    // Input farmland grid
    vector<vector<int>> land = {
        {1, 0, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 1},
        {1, 1, 0, 1, 1}
    };

    // Create a Solution object
    Solution solution;

    // Call the function and get the result
    vector<vector<int>> farmlands = solution.findFarmland(land);

    // Print the output
    cout << "Farmlands found:\n";
    for (const auto& farmland : farmlands) {
        cout << "[" << farmland[0] << ", " << farmland[1] << ", "
             << farmland[2] << ", " << farmland[3] << "]\n";
    }

    return 0;
}
