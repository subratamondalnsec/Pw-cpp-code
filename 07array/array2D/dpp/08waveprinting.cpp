#include <bits/stdc++.h>
using namespace std;
int main() {
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    for (int i=0;i<matrix.size();i++) {
        if(i%2==0){
        for (int j=matrix[0].size()-1;j>=0;j--) cout << matrix[j][i] << " ";
    }
    else {
         for (int j=0;j<matrix[0].size();j++) cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    
    return 0;
}