/* Problem Link - https://leetcode.com/problems/as-far-from-land-as-possible/
 By subrata mondal */
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) q.push({i,j});
            }
        }
        int dx[]={0,0,1,-1};
        int dy[]={1,-1,0,0};
        int mx=0;
        while(!q.empty()){
            auto curr=q.front();
            q.pop();
            int x=curr.first;
            int y=curr.second;
            for(int i=0;i<4;i++){
                int nx=x+dx[i];
                int ny=y+dy[i];
                if(nx>=0 && ny>=0 && nx<m && ny<n && grid[nx][ny]==0){
                    grid[nx][ny]=1+ grid[x][y];
                    mx=max(mx, grid[nx][ny]);
                    q.push({nx,ny});
                }
            }
        }
        return mx-1;
    }
};


int main() {
    Solution solution;

    // Example test case
    vector<vector<int>> grid = {
        {1, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    int result = solution.maxDistance(grid);
    cout << "Maximum distance from land to water: " << result << endl;

    return 0;
}