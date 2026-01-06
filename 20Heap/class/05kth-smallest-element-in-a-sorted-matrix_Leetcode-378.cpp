#include <iostream>
#include <vector>
#include <queue> // For priority_queue
using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> pq;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                pq.push(matrix[i][j]);
                if (pq.size() > k) pq.pop();  // Keep only k smallest elements
            }
        }
        return pq.top();  // The k-th smallest element will be on top
    }
};

int main() {
    Solution solution;
    vector<vector<int>> matrix = { 
        {1, 5, 9}, 
        {10, 11, 13}, 
        {12, 13, 15} 
    };  // Example matrix
    int k = 8;  // We want the 8th smallest element
    int result = solution.kthSmallest(matrix, k);

    cout << "The " << k << "th smallest element is: " << result << endl;

    return 0;
}
