#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void sort01( vector<int>&v){
  int n=v.size(); 
  int noo=0;
  int noz=0;
    for(int i=0;i<n;i++){
        if(v[i]==0) noz++;
        else noo++;
    }
    for(int i=0;i<n;i++){
        if(i<noz)v[i]=0;
        else v[i]=1;
    }
}

int main(){
    vector<int>v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(0);
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);
        v.push_back(0);
        v.push_back(1);
     display(v);
     sort01(v);
     display(v);
}