#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>tranpose(vector<vector<int>>&matrix){
    int n= matrix.size();
      vector<vector<int>>t(n,vector<int>(n));
         for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            int temp=matrix[i][j];
           matrix[i][j] =matrix[j][i];
            matrix[j][i]=temp;
        }

        }
        return matrix;
}
int main()
{ // output
    int m;
    cout << "enter the rows and columns :";
    cin >> m;
    vector<vector<int>>matrix(m,vector<int>(m));
    int i, j; // input of 2d vector
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    
    }
    vector<vector<int>>tras=tranpose(matrix);
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    
}