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
void mergesort(vector<int>&v){
    int n=v.size();
    if(n==1) return ; 
    int n1=n/2,n2 =n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++){
        a[i]=v[i];
    }
    for(int i=0;i<n2;i++){
        b[i]=v[i+n1];
    }
    //magic kai recursion
    mergesort(a);
    mergesort(b);
    merge(a,b,v);
    // merge
    a.clear();
    b.clear();
}
int main(){
    int a[]={4,1,5,10,8};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int>v(a,a+n);
    display(v);
    mergesort(v);
    display(v);
}