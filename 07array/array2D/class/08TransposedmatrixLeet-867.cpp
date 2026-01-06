#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int m = matrix.size(); // number of rows
        int n = matrix[0].size(); // number of columns
        vector<vector<int>> t(n, vector<int>(m)); // transposed matrix with dimensions n x m
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                t[i][j] = matrix[j][i];
            }
        }
        return t;
    }
};

int main() {
    Solution sol;

    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Transpose the matrix
    vector<vector<int>> result = sol.transpose(matrix);

    // Print the transposed matrix
    for(const auto& row : result) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
