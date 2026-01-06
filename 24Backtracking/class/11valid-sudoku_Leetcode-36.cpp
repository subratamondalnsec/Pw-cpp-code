/* problem link : https://leetcode.com/problems/valid-sudoku/
By subrata mondal */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSafe(vector<vector<char>>& board, int r, int c, int num) {
        for (int i = 0; i < 9; i++) {
            if (board[r][i] != '.' && (board[r][i] - '0') == num){
                if(i==c) continue;//same element not check
                return false; // Check for '.' first
            } 
            if (board[i][c] != '.' && (board[i][c] - '0') == num){
                if(i==r) continue;//same element not check
                return false; // Check for '.' first
            }
        }
        int x = (r / 3) * 3;
        int y = (c / 3) * 3;
        for (int i = x; i < x + 3; i++) {
            for (int j = y; j < y + 3; j++) {
                if (board[i][j] != '.' && (board[i][j] - '0') == num){
                    if(i==r && j==c) continue;//same element not check
                    return false; // Check for '.' first
                } 
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) { // Renamed for clarity
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j <9; j++) {
                if(board[i][j] != '.'){
                    if (isSafe(board, i, j, board[i][j] - '0')==false) return false;
                }
            }
        }
        return true;
    }
};


int main() {
    Solution solution;
    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << (solution.isValidSudoku(board) ? "Valid" : "Invalid") << endl;
    return 0;
}
