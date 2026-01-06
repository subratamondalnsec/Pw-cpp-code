/* problem link :
By subrata mondal */
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ways = 0;

    void dfs(int i, int j, int remainingCells, vector<vector<int>>& grid) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) {
            return; // Out of bounds or obstacle
        }

        if (grid[i][j] == 2) {
            if (remainingCells == 0) ways++; // All cells visited
            return;
        }

        // Mark the cell as visited
        grid[i][j] = -1;

        // Explore all 4 directions
        dfs(i - 1, j, remainingCells - 1, grid); // Up
        dfs(i + 1, j, remainingCells - 1, grid); // Down
        dfs(i, j - 1, remainingCells - 1, grid); // Left
        dfs(i, j + 1, remainingCells - 1, grid); // Right

        // Backtrack and restore the cell
        grid[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX = 0, startY = 0, emptyCells = 0;

        // Find the starting point and count all walkable cells
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                if (grid[i][j] != -1) { // Count all non-obstacle cells
                    emptyCells++;
                }
            }
        }

        // Start DFS from the starting point
        dfs(startX, startY, emptyCells - 1, grid); // Exclude the starting cell from remainingCells
        return ways;
    }
};

int main() {
    // Example grid input
    vector<vector<int>> grid = {
        {1, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 2, -1}
    };

    // Create an instance of the Solution class
    Solution solution;

    // Call the function and print the result
    int result = solution.uniquePathsIII(grid);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
