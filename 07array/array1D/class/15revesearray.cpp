#include<bits/stdc++.h>
using namespace std;
void display(vector<int>&a){
    for(int i=0;i<a.size();i++){
            cout<<a[i]<<" "; 
        }
        cout<<endl;
}
int main(){
    vector<int>v;
        v.push_back(1);
        v.push_back(3);
        v.push_back(2);
        v.push_back(4);
        v.push_back(3);
        v.push_back(4);
        v.push_back(1);
        v.push_back(6);
    display(v);
    /*vector<int>v1(v.size());

    for(int i=0;i<=v.size()-1;i++){
       v1[i] =v[v.size()-1-i];
    }*/
reverse(v.begin(),v.end());
    display(v);
    



} 