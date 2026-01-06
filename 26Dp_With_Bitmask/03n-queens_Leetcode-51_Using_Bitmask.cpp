#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<string>> res;
    int col_mask = 0;           // Mask to track columns
    int right_Diagonal_mask = 0;        // Mask to track right diagonals (row + col)
    int left_Diagonal_mask = 0;        // Mask to track left diagonals (row - col)

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0, n);
        return res;
    }

    // Backtracking function with class-level bitmasks
    void backtrack(vector<string>& board, int row, int n) {
        // Base case: If all queens are placed, add the board to the result
        if (row == n) {
            res.push_back(board);
            return;
        }

        // Loop through each column and try placing a queen
        for (int col = 0; col < n; ++col) {
            // Check if the column, right diagonal, or left diagonal is already occupied
            if ((col_mask & (1 << col)) || 
                (right_Diagonal_mask & (1 << (row + col))) || 
                (left_Diagonal_mask & (1 << (row - col + (n - 1))))) {
                continue;  // Skip if this position is under attack
            }

            // Place the queen at (row, col)
            board[row][col] = 'Q';

            // Mark the current column and diagonals as occupied
            col_mask ^= (1 << col);  // Set bit for column
            right_Diagonal_mask ^= (1 << (row + col));  // Set bit for right diagonal
            left_Diagonal_mask ^= (1 << (row - col + (n - 1)));  // Set bit for left diagonal

            // Recur to place the next queen
            backtrack(board, row + 1, n);

            // Backtrack: Remove the queen and toggle the bit back to restore the previous state
            board[row][col] = '.';
            col_mask ^= (1 << col);  // Unset bit for column (toggle back)
            right_Diagonal_mask ^= (1 << (row + col));  // Unset bit for right diagonal (toggle back)
            left_Diagonal_mask ^= (1 << (row - col + (n - 1)));  // Unset bit for left diagonal (toggle back)
        }
    }
};


int main() {
    Solution solution; // Create an object of the Solution class
    int n;             // The size of the chessboard (n x n)
    
    cout << "Enter the value of n (size of the chessboard): ";
    cin >> n;
    
    // Solve the N-Queens problem
    vector<vector<string>> results = solution.solveNQueens(n);

    // Print the results
    cout << "Number of solutions: " << results.size() << endl;
    for (int i = 0; i < results.size(); ++i) {
        cout << "Solution " << i + 1 << ":\n";
        for (const string& row : results[i]) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}