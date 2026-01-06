#include <bits/stdc++.h>
using namespace std;
int main(){
    int a[]={5,1,8,2,3};
    int n=sizeof(a)/sizeof(a[0]);
    vector<int>v(a,a+n);
    for(int i=0;i<v.size();i++){
       cout<<v[i]<<" "; 
    }
    cout<<endl; 
    int count =0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(v[i]>v[j]) count++;
        }
    }
    cout<<count;   
}       