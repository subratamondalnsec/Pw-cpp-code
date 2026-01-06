#include <bits/stdc++.h>
using namespace std;
int main()
{ // output
    int n, m,p,q;
    cout << "enter the rows 1st matrix :";
    cin >> m;
    cout << "enter the columns 1st matrix :";
    cin >> n;
     cout << "enter the rows 2nd matrix :";
    cin >> p;
    cout << "enter the columns 2nd matrix :";
    cin >> q;
    if(n==p){
          int arr[m][n],brr[p][q];
          cout<<"enter element of 1st matrix";
     int i, j; // input of 2d array
  
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        } 
    }
     cout<<"enter element of 2nd matrix";
    cout << endl;
     for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cin >> brr[i][j];
        } 
    }
    cout << endl;
    int res[m][q];
     for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < q; j++)
        {
            res[i][j]=0;
            for(int k=0;k<p;k++){
                res[i][j]+=arr[i][k]*brr[k][j];
            }
        }  
    }
 for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < q; j++)
        {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    }
    else{
         cout<<"The matrix cannot be multiplied";
    } 
}