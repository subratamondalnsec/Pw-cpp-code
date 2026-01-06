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

class Solution {//bfs
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool bfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        bool result =true;
        grid2[i][j]=-1;
        while(!q.empty()){
            auto p = q.front();
            int x = p.first;
            int y = p.second;
            q.pop();
            if(grid1[x][y]!=1) result=false;
            for(auto &d :dir){
                int nx=x+d[0];
                int ny=y+d[1];
                 if (nx >= 0 && ny >= 0 && nx < grid1.size() && ny < grid1[0].size() && grid2[nx][ny] == 1) {
                    grid2[nx][ny] =-1;
                    q.push({nx,ny});
                }
            }
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && bfs(grid1,grid2,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};

class Solution {//dfs
public:
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2,int i,int j){
        if(i<0 || j<0 || i>=grid1.size() || j>=grid1[0].size()) return true;

        if(grid2[i][j]!=1) return true;
        grid2[i][j]=-1;
        bool result=(grid1[i][j]==1);
        for(auto &d :dir){
            result=result & dfs(grid1,grid2,i+d[0],j+d[1]);
        }
        return result;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m=grid1.size();
        int n=grid1[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid2[i][j]==1 && dfs(grid1,grid2,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};


int main() {
    // Example test case
    vector<vector<int>> grid1 = {
        {1, 1, 1, 0, 0},
        {1, 0, 1, 0, 1},
        {0, 1, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    
    vector<vector<int>> grid2 = {
        {1, 1, 1, 0, 0},
        {1, 0, 0, 0, 1},
        {0, 0, 1, 1, 1},
        {0, 1, 0, 0, 0}
    };
    
    Solution solution;
    int result = solution.countSubIslands(grid1, grid2);
    
    cout << "Number of sub-islands: " << result << endl;

    return 0;
}