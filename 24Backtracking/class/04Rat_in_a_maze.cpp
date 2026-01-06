/* problem link :
By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

int ways = 0;

bool isValid(int i, int j, int n, vector<vector<int> > &grid) {
    return (i >= 0 and j >= 0 and i < n and j < n and grid[i][j] == 0);
}

void maze(int i, int j, int n, vector<vector<int> > &grid) {
    if(i == n-1 and j == n-1) {
        ways++;
        return;
    }
    grid[i][j] = 2;
    if(isValid(i-1, j, n, grid)) {
        maze(i-1, j, n, grid);
    }
    if(isValid(i, j+1, n, grid)) {
        maze(i, j+1, n, grid);
    }
    if(isValid(i+1, j, n, grid)) {
        maze(i+1, j, n, grid);
    }
    if(isValid(i, j-1, n, grid)) {
        maze(i, j-1, n, grid);
    }
    grid[i][j] = 0;

}
int ratinmaze(vector<vector<int> > &grid,int n){
    maze(0,0,n,grid);
    return ways;
}
int main(){
    vector<vector<int> >grid={
        {0,0,1,0,0,1,0},
        {1,0,1,1,0,0,0},
        {0,0,0,0,1,0,1},
        {1,0,1,0,0,0,0},
        {1,0,1,1,0,1,0},
        {1,0,0,0,0,1,0},
        {1,1,1,1,0,0,0},
    };
    cout<< "Total number of way to travel this grid : " <<ratinmaze(grid,7);
}