#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the array size: ";
    cin>>n;
    int arr[n];
    cout<<"enter the array element: ";
    for(int i=0;i<=n-1;i++){
      cin>>arr[i];
}
int max =INT_MIN;//-2147483648
int smax=INT_MIN;
int tmax=INT_MIN;
for(int i=0;i<=n-1;i++){
    if(max<arr[i]){
        tmax=smax;
        smax=max;
        max=arr[i];
    }
   else if(arr[i]!=max&& smax<arr[i]){
    tmax=smax;
    smax=arr[i];
    }
    else if(arr[i]!=max && arr[i]!=smax && tmax<arr[i]){
    tmax=arr[i];
    }
}
cout<<"1st largest "<<max<<endl;
cout<<"2nd largest "<<smax<<endl;
cout<<"3rd largest "<<tmax<<endl;
}