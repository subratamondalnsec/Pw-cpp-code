#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>tranpose(vector<vector<int>>&matrix){
    int m= matrix.size();
      int n= matrix[0].size();
      vector<vector<int>>t(n,vector<int>(m));
         for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            t[i][j]=matrix[j][i];
        }

        }
        return t;
}
int main()
{ // output
    int n, m;
    cout << "enter the rows :";
    cin >> m;
    cout << "enter the columns :";
    cin >> n;
    vector<vector<int>>matrix(m,vector<int>(n));
    int i, j; // input of 2d vector
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    
    }
    vector<vector<int>>tras=tranpose(matrix);
    cout<<endl;
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            cout<<tras[i][j]<<" ";
        }
        cout<<endl;
    }
    
}