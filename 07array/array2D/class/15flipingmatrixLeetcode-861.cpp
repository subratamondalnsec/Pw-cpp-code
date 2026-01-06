#include<bits/stdc++.h>
using namespace std;
    int matrixScore(vector<vector<int>>& grid) {
        int rows=grid.size();
        int col=grid[0].size();
        //making the first column all 1's
        for(int i=0;i<rows;i++){
            if(grid[i][0]==0){//FLIP
                for(int j=0;j<col;j++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]= 0;
                }
            }
        }
        for(int j=0;j<col;j++){
            int noz=0;
            int noo=0;
            for(int i=0;i<rows;i++){
                if(grid[i][j]==0) noz++;
                else noo++;
            }
            if(noz>noo){
            for(int i=0;i<rows;i++){
                    if(grid[i][j]==0) grid[i][j]=1;
                    else grid[i][j]= 0;
                }  
            }
        }
        int sum=0;
        for(int i=0;i<rows;i++){
            int x=1;
            for(int j=col-1;j>=0;j--){
            sum+=grid[i][j]*x;
            x*=2;
        } 
    }
    return sum;
}
int main() {

    // Example input grid
    vector<vector<int>> grid = {
        {0, 0, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 0}
    };

    // Calculate the matrix score
    int result = matrixScore(grid);

    // Output the result
    cout << "Matrix Score: " << result << endl;

    return 0;
}