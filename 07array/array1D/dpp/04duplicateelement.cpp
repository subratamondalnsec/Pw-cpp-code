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
bool flag= true;
for(int i=0;i<=n-1;i++){
    for(int j=i+1;j<n;j++){
    if(arr[i]==arr[j])  flag= false;
    }
}
if (flag==true) cout<<"Duplicate Element not found"<<endl;
else cout<<"Duplicate Element found"<<endl;
}