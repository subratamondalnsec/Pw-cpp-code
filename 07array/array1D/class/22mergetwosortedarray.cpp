#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
vector<int> merge(vector<int>&v,vector<int>&v1){
    int n=v.size();
    int m=v1.size();
    vector<int>res(m+n);
    int i=0;
    int j=0;
    int k=0;
    while(i<=n-1&&j<=m-1){
        if(v[i]<v1[j]){
        res[k]=v[i];
        i++;
  }
  else{
    res[k]=v1[j];
    j++;
  }
  k++;
    }
if(i==n){
    while(j<=m-1){
        res[k]=v1[j];
        j++;
        k++;
    }
if(j==m){
    while(i<=n-1){
        res[k]=v[i];
        i++;
        k++;
    }
}
}
return res;
}
int main(){
 vector<int>v;
        v.push_back(2);
        v.push_back(3);
        v.push_back(6);
        v.push_back(8);
        v.push_back(9);
        v.push_back(10);
        v.push_back(13);
        v.push_back(15);
 vector<int>v1;
        v1.push_back(1);
        v1.push_back(4);
        v1.push_back(5);
        v1.push_back(7);
        v1.push_back(11);
        v1.push_back(12);
        v1.push_back(14);
        v1.push_back(16);
     display(v);
     display(v1);
  vector<int> v2 =merge(v,v1);
  display(v2);
  }