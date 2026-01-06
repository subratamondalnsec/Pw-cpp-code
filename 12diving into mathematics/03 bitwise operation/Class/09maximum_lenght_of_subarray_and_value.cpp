#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[]={12,3,6,5,4,9,7,2,3,6,6,6,7,14,14,14,14};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=0;
    int max_el=INT_MIN;
    int count=0;
    for(int i=0;i<n;i++){
        if(arr[i]>max_el){
            max_el=arr[i];
            count=1;
        } else if(arr[i]==max_el) count++;
        ans=max(ans,count);
    }
    cout<<ans;
}