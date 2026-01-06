/* Problem Link - https://leetcode.com/problems/island-perimeter/
 By subrata mondal */

#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#include <algorithm>
#include <list>
#include <utility>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int up=1;
                    if((i-1<0)? 0 :  (grid[i-1][j]==1) ) up=0;

                    int down=1;
                    if((i+1>m-1) ? 0 :(grid[i+1][j]==1)) down=0;

                    int left=1;
                    if((j-1<0) ? 0 :(grid[i][j-1]==1))   left=0;

                    int right=1;
                    if((j+1>n-1) ? 0 :(grid[i][j+1]==1)) right=0;

                    ans+=up+down+left+right;

                }
            }
        }
        return ans;
    }
};

class Solution{//bfs
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};
    int islandPerimeter(vector<vector<int>> &grid){
        int n = grid.size(), m = grid[0].size(), ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1){
                    for (int k = 0; k < 4; k++){
                        if (((i + dx[k]) >= 0) && ((i + dx[k]) < n) && ((j + dy[k]) >= 0) && ((j + dy[k]) < m)){
                            if (grid[i + dx[k]][j + dy[k]] == 0) ans++;
                        }
                        else if (i == 0 || i == n - 1 || j == 0 || j == m - 1){
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};

class Solution{//dfs
public:
    vector<int> dx = {1, -1, 0, 0};
    vector<int> dy = {0, 0, 1, -1};

    int dfs(vector<vector<int>> &grid,int i,int j,vector<vector<bool>>&vis){
        if (i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size()  || grid[i][j] == 0) return 1;
        if(vis[i][j]==true) return 0;
        vis[i][j]=true;
        int perimeter =0;
        for (int k = 0; k < 4; k++){
            perimeter+=dfs(grid,i + dx[k],j + dy[k],vis);       
        }
        return perimeter;
    }


    int islandPerimeter(vector<vector<int>> &grid){
        int n =grid.size() , m = grid[0].size(), ans = 0;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1){
                   ans+= dfs(grid,i ,j ,vis);
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    cout << "Island Perimeter: " << solution.islandPerimeter(grid) << endl;
    return 0;
}