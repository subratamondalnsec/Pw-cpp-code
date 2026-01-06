#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the array : ";
    cin>>n;
    int arr[n];
    for(int i=0;i<=n-1;i++){
      cin>>arr[i];
}
/*int max =arr[0];
for(int i=1;i<=n-1;i++){
    if(max<arr[i]) max=arr[i];
}
cout<<max;*/
int max =INT_MIN;
for(int i=0;i<=n-1;i++){
    if(max<arr[i]) max=arr[i];
}
cout<<max;
}