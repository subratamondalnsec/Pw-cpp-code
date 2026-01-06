#include <bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
int inversion(vector<int>& v1,vector<int>& v2){
       int count=0;
        int i=0;
        int j=0;
        while(i<v1.size() && j<v2.size()){
            if(v1[i]>v2[j]){ 
                count+=(v1.size()-i);
                j++;
            }
            else i++;
        }
        return count;
}
void merge(vector<int>& v1,vector<int>& v2,vector<int>& res ){
     int n=v1.size(),m=v2.size();
     int i=0, j=0, k=0;
    while(i<=n-1&&j<=m-1){
        if(v1[i]<v2[j]) res[k++]=v1[i++];
        else  res[k++]=v2[j++];
    }
if(i==n) while(j<=m-1)  res[k++]=v2[j++];
if(j==m) while(i<=n-1) res[k++]=v1[i++];
}
int mergesort(vector<int>&v){
    int counter =0;
    int n=v.size();
    if(n==1) return 0; 
    int n1=n/2,n2 =n-n/2;
    vector<int>a(n1),b(n2);
    for(int i=0;i<n1;i++)  a[i]=v[i];
    for(int i=0;i<n2;i++)  b[i]=v[i+n1];
    counter+= mergesort(a);
    counter+= mergesort(b);
    counter+=inversion(a,b);   //count the inversion
    merge(a,b,v);
    a.clear();
    b.clear();
    return counter;
}
int main(){
    int a[]={1,3,2,3,1};
    int n=sizeof(a)/sizeof(a[0]);
        vector<int>v(a,a+n);
        display(v);
        cout<<mergesort(v);
}