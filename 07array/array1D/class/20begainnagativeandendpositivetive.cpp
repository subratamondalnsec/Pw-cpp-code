#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void sort01( vector<int>&v){
    int i=0,j=v.size()-1; 
  while(i<=j){
     if(v[j]>=0)  j--;
   if(v[i]<0)  i++;
    if(i>j) break;
   if(v[i]>=0 && v[j]<0){
        int temp=v[i];    
        v[i]=v[j];       
        v[j]=temp;
        i++;  
         j--;               
    } 
         
    }
}
void sort01method2( vector<int>&v){
    int i=0,j=v.size()-1; 
  while(i<=j){
     if(v[j]>=0)  j--;
   else if(v[i]<0)  i++;
   else if(v[i]>=0 && v[j]<0){
        int temp=v[i];    
        v[i]=v[j];       
        v[j]=temp;
        i++;  
         j--;               
    } 
         
    }
}

int main(){
    vector<int>v;
        v.push_back(-8);
        v.push_back(0);
        v.push_back(5);
        v.push_back(1);
        v.push_back(-6);
       
     display(v);
   //  sort01(v);
     sort01method2(v);
     display(v);
}