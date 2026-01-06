#include <bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void merge(vector<int>v1,vector<int>v2,vector<int>& res ){
     int n=v1.size();
    int m=v2.size();
     int i=0;
    int j=0;
    int k=0;
    while(i<=n-1&&j<=m-1){
        if(v1[i]<v2[j]) res[k++]=v1[i++];
        else  res[k++]=v2[j++];
    }
    if(i==n){
        while(j<=m-1)  res[k++]=v2[j++];
    }
    if(j==m){
        while(i<=n-1) res[k++]=v1[i++];
    }
}
int main(){
    int a[]={1,4,5,8};
    int n=sizeof(a)/sizeof(a[0]);
     int b[]={2,3,6,7,10,12};
    int m=sizeof(b)/sizeof(b[0]);
        vector<int>v1(a,a+n);
         vector<int>v2(b,b+m);
         vector<int>res(m+n);
    merge(v1,v2,res);
      display(res);
}