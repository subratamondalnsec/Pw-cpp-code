#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
void reversepartofarray(int i,int j, vector<int>&v){
  while(i<=j){
        int temp=v[i];
        v[i]=v[j];
        v[j]=temp;
        i++;
        j--;
    }
}
int main(){
    vector<int>v;
        v.push_back(1);
        v.push_back(2);
          v.push_back(3);
        v.push_back(4);
      
        v.push_back(5);
    display(v);
    int k=2;//rotate the array
    int n=v.size();
    k=k%n;//if(k>n)  k=k%n;
  reversepartofarray(0,n-k-1,v);
  reversepartofarray(n-k,n-1,v);
  reversepartofarray(0,n-1,v);
 display(v);
}