/* Problem Link - https://leetcode.com/problems/max-area-of-island/
 By subrata mondal */
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j,int& area){
        if (i < 0 || j < 0 || i >= grid.size() || j >=grid[0].size())return;
        if (grid[i][j] == 0) return;
        if (grid[i][j] == 1){
            area++;
            grid[i][j] = 0;
            dfs(grid, i, j + 1,area);
            dfs(grid, i, j - 1,area);
            dfs(grid, i - 1, j,area);
            dfs(grid, i + 1, j,area);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maximum_area = 0;
        for (int i = 0; i < grid.size(); i++){
            for (int j = 0; j < grid[0].size(); j++){
                if (grid[i][j] == 1){
                    int area=0;
                    dfs(grid, i, j,area);
                    maximum_area=max(maximum_area,area);
                }
            }
        }
        return maximum_area;
    }
};

int main() {
    Solution solution;
    vector<vector<int>> grid = {
        {0, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };

    int result = solution.maxAreaOfIsland(grid);
    cout << "Maximum area of an island: " << result << endl;
    return 0;
}