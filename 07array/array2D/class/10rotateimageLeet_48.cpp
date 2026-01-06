#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Transpose the matrix
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        // Reverse each row
        for(int k = 0; k < n; k++) {
            int i = 0;
            int j = n - 1;
            while(i < j) {
                int temp = matrix[k][i];
                matrix[k][i] = matrix[k][j];
                matrix[k][j] = temp;
                i++;
                j--;
            }
        }
        return;
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

    // Rotate the matrix
    sol.rotate(matrix);

    // Print the rotated matrix
    for(const auto& row : matrix) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
