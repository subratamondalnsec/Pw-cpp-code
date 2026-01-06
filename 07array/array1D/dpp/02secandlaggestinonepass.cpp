/* it one paas*/
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
int max =INT_MIN;//-2147483648
int smax=INT_MIN;
for(int i=0;i<=n-1;i++){
    if(max<arr[i]){
        smax=max;
        max=arr[i];
    }
   else if(arr[i]!=max&& smax<arr[i]) smax=arr[i];
}
cout<<max<<endl;
 if(smax==INT_MIN){
    cout<<"No second element exists"<<endl;
 }
 else cout<<smax<<endl;
}