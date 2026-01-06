#include <bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
    cout<<endl;
}
void merge(vector<int>&v,int low,int mid ,int high ){
    vector<int>a;
    int i=low;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=high){
        if(v[i]>v[j]) a.push_back(v[i++]);
        else  a.push_back(v[j++]);
    }
    while(i<=mid) a.push_back(v[i++]);
    while(j<=high) a.push_back(v[j++]);
    for(int i=low;i<=high;i++) v[i]=a[i-low];
}
void mergesort(vector<int>&v,int low,int high){
    if(low==high) return ; 
    int mid=(low+high)/2;
    //magic kai recursion
    mergesort(v,low,mid);
    mergesort(v,mid+1,high);
    merge(v,low,mid,high);
}
int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    mergesort(v,0,n-1);
    display(v);
}