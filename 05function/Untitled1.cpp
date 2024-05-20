#include <bits/stdc++.h>
using namespace std;
int main()
{ 
    int m=5;
    vector< vector<int> >v;
    for(int i=0;i<=m;i++){
        vector<int> a(i);
        v.push_back(a);
    }
        for(int i=0;i<m;i++){
            for(int j=0;j<=i;j++){
        if(j==0||j==i) v[i][j]=1;
        else v[i][j]=v[i-1][j]+v[i-1][j-1];

        }
    }
     for(int i=0;i<=m;i++){
            for(int j=0;j<=i;j++){
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
}
}
