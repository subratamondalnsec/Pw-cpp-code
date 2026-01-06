#include <bits/stdc++.h>
using namespace std;
/*class Solution {// sc=O(m+n)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int> row(n,0);
        vector<int> col(m,0);
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    row[i]=1;
                    col[j]=1;
                }
            }
        }
        for (int i=0;i<n;i++) {
            for (int j=0;j<m;j++){
                if(row[i]==1 || col[j]==1){
                   matrix[i][j]=0;
                }
            }
        } 
        return;       
    }
};*/

// class Solution {//sc=O(1)
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         int flag=0;
//         for (int i=0;i<n;i++) {
//             if(matrix[i][0]==0) flag=1;
//             for (int j=1;j<m;j++){                
//                 if(matrix[i][j]==0){
//                     matrix[0][j]=matrix[i][0]=0;
//                 }
//             }
//         }
//         for (int i=n-1;i>=0;i--) {
//             for (int j=m-1;j>0;j--){
//                 if(matrix[0][j]==0 || matrix[i][0]==0){
//                    matrix[i][j]=0;
//                 }
//             }
//             if(flag) matrix[i][0]=0;
//         }       
//     }
// };

class Solution {//sc=O(1)
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        bool flagrow=false;
        bool flagcol=false;
        for (int j=0;j<n;j++){ 
            if(matrix[0][j]==0) flagrow=true; 
        } 

        for (int i=0;i<m;i++) {
            if(matrix[i][0]==0) flagcol=true;
        }
            
        for (int i=1;i<m;i++) {
            for (int j=1;j<n;j++){       
                if(matrix[i][j]==0){
                    matrix[0][j]=0;
                    matrix[i][0]=0;
                }
            }
        }
        for (int j=1;j<n;j++){
                if(matrix[0][j]==0){//puri calumn kai zero kore do
                    for (int i=1;i<m;i++) {
                        matrix[i][j]=0;
                }
            }
        }
        for (int i=1;i<m;i++) {
            if( matrix[i][0]==0){
                for (int j=1;j<n;j++){
                   matrix[i][j]=0;
                }
            }
        } 
         
        if(flagrow==true) {
            for(int j=0;j<n;j++) matrix[0][j]=0;
        } 
        if(flagcol==true) {
            for(int i=0;i<m;i++) matrix[i][0]=0;
        }      
    }
};
int main() {
    Solution solution;
    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    solution.setZeroes(matrix);

    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}