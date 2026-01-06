/* By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dx{-2,-1,-2,-1,2,1,2,1};
    vector<int> dy{1,2,-1,-2,1,2,-1,-2};

    bool f(vector<vector<int>>& grid, int i, int j, int n, int count) {
        // Base condition: If we've reached the last cell and visited all cells, it's a valid tour
        if (count == n * n - 1) {
            return true;
        }

        // Mark the current cell as visited
        grid[i][j] = -1;

        for (int k = 0; k < 8; k++) {
            int x = i + dx[k];
            int y = j + dy[k];

            if (x >= 0 && y >= 0 && x < n && y < n && grid[x][y] == count + 1) {
                if (f(grid, x, y, n, count + 1)) {
                    return true;
                }
            }
        }

        // Backtrack: Unmark the current cell if it doesn't lead to a valid tour
        grid[i][j] = count;
        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
        return f(grid, 0, 0, grid.size(), 0);
    }
};

int main() {
    // Example usage:
    vector<vector<int>> grid = {
        {1, 2, 3},
        {8, 9, 4},
        {7, 6, 5}
    };

    Solution solution;
    bool isValid = solution.checkValidGrid(grid);

    if (isValid) {
        cout << "The grid represents a valid Knight's Tour." << endl;
    } else {
        cout << "The grid does not represent a valid Knight's Tour." << endl;
    }

    return 0;
}