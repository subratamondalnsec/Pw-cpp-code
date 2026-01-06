#include <bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={4, 2, 7, 9, 8};
    int n =sizeof(arr)/sizeof(arr[0]);
    bool flag=true;
    for(int i=0;i<n;i++){  
        int count =0;  
        for(int j=0;j<n;j++){
            if(i==j) continue;
            if(arr[j]>arr[i]) count++;
        }
        int aidx=n-count-1;
        int diff=abs(aidx-i);
        if(diff>1){
            flag=false;
            break;
        }
    }
    cout<<flag;
}