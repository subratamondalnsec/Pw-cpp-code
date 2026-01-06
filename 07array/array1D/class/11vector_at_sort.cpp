#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
        v.push_back(4);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);
        v.at(2)=90;//update the value
        v[3]=50;//update the value
        for(int i=0;i<v.size();i++){
            cout<<v[i]<<" "; 
        }
        cout<<endl; 
       sort(v.begin(),v.end());
         for(int i=0;i<v.size();i++){
            cout<<v[i]<<" "; 
        }
}