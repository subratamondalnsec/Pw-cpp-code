    #include <bits/stdc++.h>
    using namespace std;
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int cols = matrix[0].size();
        int i=0;
        int j=cols-1;
        while(i<=row-1&&j>=0){
            if(matrix[i][j]==target) return true;
            else if(matrix[i][j]>target) j--;
            else i++;
        }
        return false;
    }
    int main() {
    // Example input matrix
    vector<vector<int>> matrix = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };

    // Example target
    int target = 5;

    // Search the target in the matrix
    bool result = searchMatrix(matrix, target);

    // Output the result
    cout << "Target " << target << (result ? " found" : " not found") << " in the matrix." << endl;

    return 0;
}