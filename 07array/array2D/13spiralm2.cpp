#include <bits/stdc++.h>
using namespace std;
int main()
{ // output
    int n, m;
    cout << "enter the rows :";
    cin >> m;
    cout << "enter the columns :";
    cin >> n;
    int arr[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //spiral
int minr=0,minc=0,maxr=m-1,maxc=n-1;
 int tne =n*m,count=0;
while(minr<=maxr && minc<=maxc){
   
//rigit
for(int j=minc;j<=maxc && count<tne;j++){
    cout<<arr[minr][j]<<" ";
    count++;
}
minr++;
//down
for(int i=minr;i<=maxr && count<tne;i++){
    cout<<arr[i][maxc]<<" ";
    count++;
}
maxc--;
//left
for(int j=maxc;j>=minc && count<tne;j--){
    cout<<arr[maxr][j]<<" ";
    count++;
}
maxr--;
//up
for(int i=maxr;i>=minr && count<tne; i--){
    cout<<arr[i][minc]<<" ";
count++;
}
minc++;

}
}