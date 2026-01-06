/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/cherry-pickup/description/
*/
#include <iostream>
#include <vector>
#include <climits> 
#include <string.h>
using namespace std;

class Solution{
public:
    int neg=INT_MIN;
    int n,m;// dimensions of the input matrix
    int dp[55][55][55];
    vector<vector<int>>mat;
    int f(int i,int j,int x,int y){
        if(i>n or j>m or x>n or y>m or mat[i][j]== -1 or mat[x][y]== -1  ) return neg;
        if(i==n and j==m ){
            return mat[i][j]==1;
        }
        if(dp[i][j][x]!=-1) return dp[i][j][x];
        int result =neg;
        result=max(result,f(i+1,j,x+1,y));
        result=max(result,f(i+1,j,x,y+1));
        result=max(result,f(i,j+1,x+1,y));
        result=max(result,f(i,j+1,x,y+1));

        if(result==neg ) return dp[i][j][x]=neg;

        result+=(mat[i][j]==1);
        result+=(mat[x][y]==1);
        //remove repition
        if(i==x and j==y and mat[i][j]==1) result--;
        return dp[i][j][x]=result;
    }

    int cherryPickup(vector<vector<int>>&grid){
        memset(dp,-1,sizeof (dp));
        n=grid.size();
        m=grid[0].size();
        mat.resize(55,vector<int>(55,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                mat[i+1][j+1]= grid[i][j];
            }
        }
        int ans=f(1,1,1,1);
        return ans==neg ? 0 :ans;
    }
};

int main(){
    Solution sol;
    vector<vector<int>>v={{0 , 1  ,-1},{1 , 0 , -1 },{1,1,1}};
    cout<<sol.cherryPickup(v);
}



