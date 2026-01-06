#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i=matrix.size()-1;i>=0;i--) {
        for (int j=0;j<matrix[0].size();j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }

   /* int m=matrix.size();//transpose
    int n=matrix[0].size();
    for(int i=0;i<m;i++){
        for(int j=i+1;j<n;j++){
            swap(matrix[i][j],matrix[j][i]);
        }
    }
    for(int j=0;j<n;j++){
        int lo=0;
        int hi=n-1;
        while(lo<hi){
            int temp=matrix[lo][j];
            matrix[lo][j]=matrix[hi][j];
            matrix[hi][j]=temp;
            lo++;
            hi--;
        }
    }
    for (const auto& row : matrix) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
*/
}