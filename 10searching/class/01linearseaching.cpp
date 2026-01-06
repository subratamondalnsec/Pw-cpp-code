#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={1,2,3,4,5,6,7,8};
    int n =sizeof(arr)/sizeof(arr[0]);
    int x=5;
    bool flag=false;
    for(int i=0;i<n;i++){
        if(arr[i]==x){
            flag=true;
            break;
        }
    }
    if(flag==true) cout<<"present";
    else cout<<" not present";
}