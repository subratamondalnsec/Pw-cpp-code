#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){ 
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void sort012( vector<int>&v){//two passing solution
  int n=v.size(); 
  int noo=0;
  int noz=0;
  int notw=0;
    for(int i=0;i<n;i++){
        if(v[i]==0) noz++;
        else if(v[i]==1) noo++;
        else notw++;
    }
    for(int i=0;i<n;i++){
        if(i<noz) v[i]=0;
        else if(i<(noz+noo)) v[i]=1;
        else v[i]=2;
    }
}
void m2sort012(vector<int>&v){
    int  hi=v.size()-1;
    int lo = 0;
    int mid=0;
    while (mid<=hi)
    {
        if(v[mid]==2){//high all 2
        int temp=v[hi];
        v[hi]=v[mid];
        v[mid]=temp;
        hi--;
        }
       else if(v[mid]==0){
            int temp= v[lo];
            v[lo]=v[mid];
            v[mid]=temp;
            mid++;
            lo++;
        }
       else if(v[mid]==1){
            mid++;
        }
    }
}
int main(){
    vector<int>v;
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(0);
        v.push_back(1);
        v.push_back(2);
        v.push_back(0);
        v.push_back(1);
     display(v);
    // sort012(v);
    m2sort012(v);
     display(v);
}