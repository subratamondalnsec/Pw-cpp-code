/* By subrata mondal */
#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<int> >&grid,int i,int j,int n){
    return i>=0 && j>=0 && i<n && j<n && grid[i][j]==-1;
}
vector<int>dx{-2,-1,-2,-1,2,1,2,1};
vector<int>dy{1,2,-1,-2,1,2,-1,-2,};
void display(vector<vector<int> >&grid,int n){
    for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<"\n \n";
}
void f( vector<vector<int> >&grid,int i,int j,int n,int count){
    if(count==n*n-1){
        grid[i][j]=count;
        display(grid,n);
        cout<<"****************\n";
        grid[i][j]=-1;
        return ;
    }

    //from i,j go 8th direction 
    //for every position we can only go if it is safe
    for(int k=0;k<8;k++){
        if(isSafe(grid,i+dx[k],j+dy[k],n)){
            grid[i][j]=count;
            f(grid,i+dx[k],j+dy[k],n,count+1);
            grid[i][j]=-1;
        }
    }
}
void knighTour(int n,int i,int j){
    vector<vector<int> >grid(n,vector<int>(n,-1));
    f(grid,i,j,n,0);
}
int main(){
    knighTour(5,0,0);
}