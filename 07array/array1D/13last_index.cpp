/*#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    vector<int>v;
        v.push_back(4);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);
        v.push_back(1);
        v.push_back(6);
        v.push_back(5);
        v.push_back(2);
        int x=6;
        int idx=-1;
        for(int i=0;i<v.size();i++){
            if(v[i]==x){
                idx=i;
            } 
        }
        cout<<idx; 
        }*/

#include<bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
        v.push_back(4);
        v.push_back(6);
        v.push_back(7);
        v.push_back(8);
        v.push_back(1);
        v.push_back(6);
        v.push_back(5);
        v.push_back(2);
        int x=6;
        int idx=-1;
        for(int i=v.size()-1;i>=0;i--){
            if(v[i]==x){
                idx=i;
                break;
            } 
        }
        cout<<idx; 
        }