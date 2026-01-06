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
    int mx=INT_MIN,idx;
    for (int i = 0; i <matrix.size(); i++){ 
        int sum=0;
        for (int j = 0; j <matrix[0].size(); j++){
           sum+=matrix[i][j];      
        }
        if(mx<sum){
            mx=max(mx,sum);
            idx=i;
        }
    }
   cout<<"maximum sum of row : "<<idx+1;
}