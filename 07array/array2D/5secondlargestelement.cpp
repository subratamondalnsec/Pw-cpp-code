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
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }
    int max = INT_MIN;
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            if (max < arr[i][j])
                max = arr[i][j];
        }
    }
    int smax=INT_MIN;
    for (int i = 0; i < m; i++)
    { 
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j]!=max&& smax<arr[i][j])
                smax = arr[i][j];
        }
    }
    cout<<smax;
   
}