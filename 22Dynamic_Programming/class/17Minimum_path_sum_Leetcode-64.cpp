/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/minimum-path-sum/description/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<vector<int> > dp;
    int f(int i, int j,int m,int n,vector<vector<int> >&arr){
        if(i==m-1 && j==n-1) return arr[m-1][n-1];
        if(i>m-1 || j > n-1) return INT_MAX;
        if(dp[i][j]!=-1) return dp[i][j];
        return dp[i][j]=arr[i][j]+min(f(i+1,j,m,n,arr),f(i,j+1,m,n,arr));
    }
    int BU_0_to_n(vector<vector<int> >&grid){
        int m=grid.size();
        int n=grid[0].size();
        for(int i=1;i<n;i++) grid[0][i]+=grid[0][i-1];
        for(int i=1;i<m;i++) grid[i][0]+=grid[i-1][0];
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
            } 
        }
        return grid[m-1][n-1];
    }

    int BU_n_to_0(vector<vector<int> >&grid){
        int m=grid.size();
        int n=grid[0].size();
        for(int i=n-2;i>=0;i--) grid[m-1][i]+=grid[m-1][i+1];
        for(int i=m-2;i>=0;i--) grid[i][n-1]+=grid[i+1][n-1];
        for(int i=m-2;i>=0;i--){
            for(int j=n-2;j>=0;j--){
                grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);
            } 
        }
        return grid[0][0];
    }
    int minPathSum(vector<vector<int> >&grid){
        dp.clear();
        dp.resize(grid.size()+1,vector<int>(grid[0].size()+1,-1));
        return f(0,0,grid.size(),grid[0].size(),grid);
        //return BU_0_to_n(grid);
        //return BU_n_to_0(grid);
    }
};
int main(){
    vector<vector<int> >arr={{1,3,1},{1,5,1},{4,2,1}};
    Solution sol;
    int result=sol.minPathSum(arr);
    cout<<result;
}