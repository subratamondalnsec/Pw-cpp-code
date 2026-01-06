#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if(n==0){
            return{};
        }
  int m=n;
  int nums=1;
   vector<vector<int>>matrix(n,vector<int>(n));
//rigit
int minr=0,minc=0,maxr=m-1,maxc=n-1;
    int tne =n*m,count=0;    
while(minr<=maxr && minc<=maxc){
    
//rigit
for(int j=minc;j<=maxc && count<tne;j++){
    matrix[minr][j]=nums++;
    count++;
}
minr++;
//down
for(int i=minr;i<=maxr && count<tne;i++){
     matrix[i][maxc]=nums++;
    count++;
}
maxc--;
//left
for(int j=maxc;j>=minc && count<tne;j--){
    matrix[maxr][j]=nums++;
    count++;
}
maxr--;
//up
for(int i=maxr;i>=minr&&count<tne; i--){
     matrix[i][minc]=nums++;
count++;
}
minc++;
}

    return matrix;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> matrix= sol.generateMatrix(3);
    for (int i=0;i<matrix.size();i++) {
        for (int j=0;j<matrix.size();j++) {
             cout<<matrix[i][j]<<" ";
        } 
        cout<<endl;  
    }
    cout << endl;

    return 0;
}
