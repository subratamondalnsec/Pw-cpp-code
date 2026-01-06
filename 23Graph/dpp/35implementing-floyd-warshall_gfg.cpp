/* Problem Link - https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
 By subrata mondal */

#include <iostream>
#include <vector>
#include <list>
#include <climits>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <stack>
using namespace std;

class Solution {
  public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n=mat.size();
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(mat[i][j]==-1) mat[i][j]=INT_MAX;
           }
       }
       
       for (int k=0;k<n;k++){
           for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                   if(mat[i][k]==INT_MAX || mat[k][j]==INT_MAX) continue;
                   mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
               }
           }
       }
       
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++){
               if(mat[i][j]==INT_MAX) mat[i][j]=-1;
           }
       }
       
    }
};

int main() {
    vector<vector<int>> mat = {
        {0, 3, -1, 7},
        {-1, 0, -1, 1},
        {2, -1, 0, 5},
        {-1, -1, 2, 0}
    };

    Solution sol;
    sol.shortestDistance(mat);

    cout << "Shortest distance matrix:" << endl;
    for (const auto& row : mat) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}