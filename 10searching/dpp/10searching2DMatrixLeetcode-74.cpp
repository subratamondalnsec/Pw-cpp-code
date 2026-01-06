#include <bits/stdc++.h>
using namespace std;
// class Solution { t.c=>O(m*logn)     sc=>o(1)
// public:
//     bool searchMatrix(vector<vector<int>>& matrix, int target) {
//         int m = matrix.size();    // number of rows
//         int n = matrix[0].size(); // number of columns
//         if(m==1 && n<=2){
//             if(matrix[0][0]==target) return true;
//             else if (n==2 && matrix[0][1]==target) return true;
//             else return false;
//         }
//         for (int i = 0; i < m; i++) {
//             while (matrix[i][n - 1] < target)
//                 break;
//             if (matrix[i][n - 1] >= target) {
//                 int lo = 0;
//                 int hi = n - 1;
//                 bool flag = false;
//                 while (lo <= hi) {
//                     int mid = lo + (hi - lo) / 2;
//                     if (matrix[i][mid] == target) {
//                         return true;
//                     } else if (matrix[i][mid] > target)
//                         hi = mid - 1;
//                     else
//                         lo = mid + 1;
//                 }
//             }
//         }
//         return false;
//     }
// };

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int lo = 0, hi = n * m - 1;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (matrix[mid / n][mid % n] == target)
                return true;
            else if (matrix[mid / n][mid % n] > target)
                hi = mid - 1;
            else
                lo = mid + 1;
        }
        return false;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    
    int target = 3;

    if (solution.searchMatrix(matrix, target)) {
        cout << "Target " << target << " found in the matrix." << endl;
    } else {
        cout << "Target " << target << " not found in the matrix." << endl;
    }

    return 0;
}
