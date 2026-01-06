#include <bits/stdc++.h>
using namespace std;
int main() {
    // Example matrix
    vector<vector<int>> matrix = {
        {1, 2, 3,12,15},
        {4, 5, 6,13,16},
        {7, 8, 9,14,17},
        {15, 81, 19,4,1},
        {17, 18, 91,1,7}
    };
    int l1,l2,r1,r2,start,last,ls,ll,sum=0;
    cout<<"1st coordinates :";
    cin>>l1>>r1;
    cout<<"2nd coordinates :";
    cin>>l2>>r2;
    start=min(l1,l2);
    last=min(r1,r2);
    ls=max(l1,l2);
    ll=max(r1,r2);
    for (int i = start; i <=ls; i++){ 
        for (int j = last; j <=ll; j++){
           sum+=matrix[i][j];      
        }
    }
    cout<<sum;
    return 0;
}
