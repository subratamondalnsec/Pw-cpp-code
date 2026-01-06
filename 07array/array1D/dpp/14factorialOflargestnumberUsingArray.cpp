#include<bits/stdc++.h>
using namespace std;
void go(vector<int>& v,int val,int &size){//int
    int carry=0;
    for(int i=0;i<size;i++){
        int product=(v[i]*val)+carry;

        v[i]=product%10;
        carry=product/10;
    }
    while(carry){
        v[size]=carry%10;
        carry/=10;
        size++;
    }
   // return size;
}
int main(){
    vector<int>v(500,0);
    v[0]=1;
    int size=1;
    int n;
    cout<<"the number of factorial:";
    cin>>n;
    for(int i=2;i<=n;i++){
        go(v,i,size);
    }
    for(int i=size-1;i>=0;i--) cout<<v[i];
}