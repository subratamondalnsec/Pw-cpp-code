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
     if(v[j]==1)  j--;
    if(v[i]==0)  i++;
     if(i>j) break;
    if(v[i]==1 && v[j]==0){
        int temp=v[i];    
        v[i]=v[j];       
        v[j]=temp;
        i++;  
         j--;               
    } 
         
    }
}
void sort01_method2( vector<int>&v){
    int i=0,j=v.size()-1;
  while(i<j){
    if(v[j]==1)  j--;
    if(v[i]==0)  i++;
    if(i>j) break;
    if(v[i]==1 && v[j]==0){
        v[i]=0;
        v[j]=1;
        i++;
        j--;
        }
  }
}
void sort01_method3( vector<int>&v){
    int i=0,j=v.size()-1;
  while(i<j){
     if(v[i]==1 && v[j]==0){
            v[i]=0;
            v[j]=1;
            i++;
            j--;
        }
            if(v[j]==1)  j--;
            if(v[i]==0)  i++;
   
    }
}
void sort01_method4( vector<int>&v){
    int i=0,j=v.size()-1;
  while(i<j){
    if(v[j]==1)  j--;
   else if(v[i]==0)  i++;
   else if(v[i]==1 && v[j]==0){
        v[i]=0;
        v[j]=1;
        i++;
        j--;
        }
  }
}
void sort01_method5( vector<int>&v){
    int i=0,j=v.size()-1;
  while(i<j){
    if(v[j]==1)  j--;
    if(v[i]==0)  i++;
   else if(v[i]==1 && v[j]==0){
        v[i]=0;
        v[j]=1;
        i++;
        j--;
        }
  }
}

int main(){
    vector<int>v;
        v.push_back(0);
        v.push_back(0);
        v.push_back(1);
        v.push_back(1);
        v.push_back(0);
       
     display(v);
    sort01(v);
    //  sort01_method2(v);
    //  sort01_method3(v);
    //  sort01_method4(v);
    //  sort01_method5(v);
     display(v);
}