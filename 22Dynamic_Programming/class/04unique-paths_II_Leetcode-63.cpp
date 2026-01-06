#include <iostream>
#include <vector>
using namespace std;

class Solution {//Pure Recursion  t.c=O(2^(m+n)) and O(m+n),for recusion stack
public:
    int helper(vector<vector<int>>& grid,int sr,int sc){//sr=>starting row ,sc=starting column
        if(sr==grid.size()-1 && sc==grid[0].size()-1 && grid[sr][sc]==0) return 1;
        if(sr>=grid.size() || sc>=grid[0].size() || grid[sr][sc]==1) return 0;
        return helper(grid,sr,sc+1)+helper(grid,sr+1,sc);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return helper(obstacleGrid,0,0);
    }
};


class Solution {//Memoization //T.C=O(M*N) s.c=O(M*N)
public:
    int helper(vector<vector<int>>& grid,int sr,int sc,vector<vector<int>>&dp){//sr=>starting row ,sc=starting column
        if(sr==grid.size()-1 && sc==grid[0].size()-1 && grid[sr][sc]==0) return 1;
        if(sr>=grid.size() || sc>=grid[0].size() || grid[sr][sc]==1) return 0;
        if(dp[sr][sc]!=-1) return dp[sr][sc];
        return dp[sr][sc]=helper(grid,sr,sc+1,dp)+helper(grid,sr+1,sc,dp);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {//Memoization
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return helper(obstacleGrid,0,0,dp);
    }
};


class Solution {//Tabulation //T.C=O(M*N) s.c=O(M*N)
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[m-1][n-1]==1) return 0;
        if(m==1 && n==1 && obstacleGrid[m-1][n-1]==0) return 1;
        int dp[m][n];
        int k=1;
        for(int i=0;i<n;i++){
            if(obstacleGrid[0][i]==1) k = 0;
            dp[0][i]=k;
        }
        k=1;
        for(int j=0;j<m;j++){
            if(obstacleGrid[j][0]==1) k = 0;
            dp[j][0]=k;
        }
        for(int i=1;i<m;i++){
            for(int j=1; j<n; j++){
                if(obstacleGrid[i][j]==0) dp[i][j]=dp[i-1][j]+dp[i][j-1];
                else dp[i][j]=0;
            }
        }
        return dp[m-1][n-1];
    }
};

int main() {
    vector<vector<int>> arr={{0,0,0},{0,1,0},{0,0,0}};
    Solution sol;
    int result = sol.uniquePathsWithObstacles(arr);
    cout << "The number of possible unique paths is: " << result << endl;
    return 0;
}