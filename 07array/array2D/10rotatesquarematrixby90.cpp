#include <bits/stdc++.h>
using namespace std;
int main()
{ // output
    int m;
    cout << "enter the rows and column :";
    cin >> m;
    int i, j; // input of 2d array
    int matrix[m][m];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
     for (int i = 0; i < m; i++)
    { 
        for (int j = i+1; j < m; j++)
        {
         int temp=matrix[i][j];
         matrix[i][j]=matrix[j][i];
         matrix[j][i]=temp;
        } 
    }
    for(int k=0;k<m;k++){
        int i=0;
        int j=m-1;
        while(i<=j){
            int temp=matrix[k][i];
            matrix[k][i]=matrix[k][j];
            matrix[k][j]=temp;
            i++;
            j--;
        }

    }
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < m; j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}