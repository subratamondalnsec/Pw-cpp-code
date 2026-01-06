/* problem link : https://leetcode.com/problems/n-queens/description/
By subrata mondal */
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> result;
    vector<vector<char>> grid;

    bool check(int row, int col, int n) {
        for (int i = row - 1; i >= 0; i--) {
            if (grid[i][col] == 'Q') return false; // up
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (grid[i][j] == 'Q') return false; // upper left
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (grid[i][j] == 'Q') return false; // upper right
        }
        return true;
    }

    void f(int n, int row) {
        if (row == n) { 
            vector<string> temp;
            for (int i = 0; i < n; i++) {
                string res = "";
                for (int j = 0; j < n; j++) {
                    res += grid[i][j];
                }
                temp.push_back(res);
            }
            result.push_back(temp);
            return;
        }

        for (int col = 0; col < n; col++) {
            if (check(row, col, n)) {
                grid[row][col] = 'Q';
                f(n, row + 1);
                grid[row][col] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        grid.clear();
        result.clear();
        grid.resize(n, vector<char>(n, '.'));
        f(n, 0);
        return result;
    }
};

int main() {
    int n;
    cout << "Enter the value of N for the N-Queens problem: ";
    cin >> n;

    Solution solution;
    vector<vector<string>> solutions = solution.solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto& board : solutions) {
        for (const string& row : board) {
            cout << row << endl;
        }
        cout << endl; // Separate each solution with a blank line
    }

    return 0;
}
