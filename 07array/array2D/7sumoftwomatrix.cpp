#include <bits/stdc++.h>
using namespace std;
int main()
{ // output
    int n, m;
    cout << "enter the rows :";
    cin >> m;
    cout << "enter the columns :";
    cin >> n;
    int i, j; // input of 2d array
    int arr[m][n],brr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> brr[i][j];
        }
        cout << endl;
    }
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            arr[i][j]+=brr[i][j];
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
}