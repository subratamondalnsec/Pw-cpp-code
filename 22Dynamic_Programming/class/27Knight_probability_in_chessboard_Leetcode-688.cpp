/*
Code BY Subrata Mondal
problem link : https://leetcode.com/problems/knight-probability-in-chessboard/description/
*/
#include <iostream>
#include <vector>
#include <string.h>
using namespace std;
class Solution{
public:
    double dp[30][30][105];
    int dx[8]={1,2,1,2,-1,-2,-1,-2};
    int dy[8]={2,1,-2,-1,2,1,-2,-1};
    double f(int n,int i,int j,int k){
        if(i<0 or j<0 or i>=n or j>=n) return 0;
        if(k==0) return 1;
        if(dp[i][j][k]>-0.9) return dp[i][j][k];
        double ans=0.0;
        for(int m=0;m<8;m++){
            ans+=f(n,i+dx[m],j+dy[m],k-1) *(0.125);
        }
        // ans+=f(n,i+1,j+2,k-1) *(0.125);
        // ans+=f(n,i+2,j+1,k-1) *(0.125);
        // ans+=f(n,i+1,j-2,k-1) *(0.125);
        // ans+=f(n,i+2,j-1,k-1) *(0.125);
        // ans+=f(n,i-1,j+2,k-1) *(0.125);
        // ans+=f(n,i-2,j+1,k-1) *(0.125);
        // ans+=f(n,i-1,j-2,k-1) *(0.125);
        // ans+=f(n,i-2,j-1,k-1) *(0.125);
        return dp[i][j][k]=ans;
    }
    double knightProbability(int n,int k,int row,int column){
        memset(dp,-1,sizeof dp);
        return f(n,row,column,k);
    }
};
int main(){
    Solution sol;
    int n,k,row,column;
    cout<<"Enter the size chessboard : ";
    cin>>n;
    cout<<"Enter the knight move is : ";
    cin>>k;
    cout<<"Enter the row knight say : ";
    cin>>row;
    cout<<"Enter the column knight say : ";
    cin>>column;
    cout<<"The knight remain on the chessboard it's probability is : "<<sol.knightProbability(n,k,row,column);
}